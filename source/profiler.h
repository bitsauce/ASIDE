#ifndef PROFILER_H
#define PROFILER_H

#include <QWidget>
#include <QTreeWidget>
#include <QList>

namespace Ui {
class Profiler;
}

class ProfilerTreeNode
{
public:
    explicit ProfilerTreeNode(const QString &name, ProfilerTreeNode *parent);

    void updateData(const QStringList &dataList);
    void resetData();
    void update(QTreeWidgetItem *item, float &parentTime, float &rootTime);

    QString name() const;
    ProfilerTreeNode *parent() const;
    QList<ProfilerTreeNode*> children() const;

private:
    QString m_name;
    int totalTime;
    int maxTime;
    int minTime;
    int aveTime;
    int callCount;
    ProfilerTreeNode *m_parent;
    QList<ProfilerTreeNode*> m_children;
};

class ProfilerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilerWidget(QWidget *parent = 0);
    ~ProfilerWidget();

    void push(const QStringList &dataList);
    void pop();

    void update();

private:
    void buildTree(ProfilerTreeNode *node, QTreeWidgetItem *item, float parentTime, float rootTime);
    void deleteTree(ProfilerTreeNode *node);

public slots:
    void toggleProfiler();
    void applicationStart();
    void applicationEnd();

signals:
    void start();
    void stop();

private:
    Ui::Profiler *ui;
    ProfilerTreeNode *m_root;
    ProfilerTreeNode *m_currentNode;
    bool m_enabled;
};

#endif // PROFILER_H
