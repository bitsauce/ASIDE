#include "profiler.h"
#include "ui_profiler.h"

ProfilerWidget::ProfilerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Profiler),
    m_currentItem(0),
    m_enabled(false)
{
    ui->setupUi(this);

    connect(ui->toggleProfilerButton, SIGNAL(clicked()), this, SLOT(toggleProfiler()));
}

ProfilerWidget::~ProfilerWidget()
{
    delete ui;
}

void ProfilerWidget::push(ProfilerWidget::Node *node)
{
    if(m_currentItem == 0)
    {
        QList<QTreeWidgetItem*> items = ui->profilerTree->findItems(node->functionName, Qt::MatchExactly);
        if(!items.empty())
        {
            m_currentItem = items[0];
        }
        else
        {
            m_currentItem = new QTreeWidgetItem();
            ui->profilerTree->addTopLevelItem(m_currentItem);
        }
    }
    else
    {
        QTreeWidgetItem *find = 0;
        for(int i = 0; i < m_currentItem->childCount(); i++)
        {
            if(m_currentItem->child(i)->text(0) == node->functionName)
            {
                find = m_currentItem->child(i);
                break;
            }
        }

        if(find)
        {
            m_currentItem = find;
        }
        else
        {
            m_currentItem = new QTreeWidgetItem(m_currentItem);
        }
    }
    updateItem(m_currentItem, node);
}

void ProfilerWidget::pop()
{
    Q_ASSERT(m_currentItem != 0);
    m_currentItem = m_currentItem->parent();
}

void ProfilerWidget::clear()
{
    if(m_enabled)
    {
        ui->profilerTree->clear();
    }
}

void ProfilerWidget::updateItem(QTreeWidgetItem *item, ProfilerWidget::Node *node)
{
    item->setText(0, node->functionName);
    item->setText(1, QString("%1 ms").arg(QString::number(node->maxTime)));
    item->setText(2, QString("%1 ms").arg(QString::number(node->minTime)));
    item->setText(3, QString("%1 ms").arg(QString::number(node->aveTime)));
    item->setText(4, QString("%1 ms").arg(QString::number(node->totalTime)));
    item->setText(5, QString::number(node->callCount));
}

void ProfilerWidget::toggleProfiler()
{
    if(m_enabled)
    {
        ui->toggleProfilerButton->setIcon(QIcon(":/toolbar/icons/run.png"));
        emit stop();
    }
    else
    {
        ui->toggleProfilerButton->setIcon(QIcon(":/toolbar/icons/stop.png"));
        emit start();
    }
    m_enabled = !m_enabled;
}

void ProfilerWidget::applicationStart()
{
    ui->profilerTree->clear();
    ui->toggleProfilerButton->setEnabled(true);
}

void ProfilerWidget::applicationEnd()
{
    ui->toggleProfilerButton->setEnabled(false);
}
