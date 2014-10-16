#ifndef PROFILER_H
#define PROFILER_H

#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class Profiler;
}

class ProfilerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilerWidget(QWidget *parent = 0);
    ~ProfilerWidget();

    struct Node
    {
        QString functionName;
        int totalTime;
        int maxTime;
        int minTime;
        int aveTime;
        int callCount;
    };

    void push(Node *node);
    void pop();

    void clear();

    void updateItem(QTreeWidgetItem *item, Node *node);

public slots:
    void toggleProfiler();
    void applicationStart();
    void applicationEnd();

signals:
    void start();
    void stop();

private:
    Ui::Profiler *ui;
    QTreeWidgetItem *m_currentItem;
    bool m_enabled;
};

#endif // PROFILER_H
