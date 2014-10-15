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

    void updateItem(QTreeWidgetItem *item, Node *node);

private:
    Ui::Profiler *ui;
    QTreeWidgetItem *m_currentItem;
};

#endif // PROFILER_H
