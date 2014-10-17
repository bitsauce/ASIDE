#include "profiler.h"
#include "ui_profiler.h"

ProfilerWidget::ProfilerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Profiler),
    m_root(0),
    m_currentNode(0),
    m_enabled(false)
{
    ui->setupUi(this);
    connect(ui->toggleProfilerButton, SIGNAL(clicked()), this, SLOT(toggleProfiler()));
}

ProfilerWidget::~ProfilerWidget()
{
    delete ui;
}

void ProfilerWidget::push(const QStringList &dataList)
{
    ProfilerTreeNode *find = 0;
    if(m_currentNode)
    {
        foreach(ProfilerTreeNode *child, m_currentNode->children())
        {
            if(child->name() == dataList[0])
            {
                find = child;
                break;
            }
        }

        if(find)
        {
            m_currentNode = find;
        }
        else
        {
            m_currentNode = new ProfilerTreeNode(dataList[0], m_currentNode);
        }
    }
    else
    {
        if(m_root == 0)
        {
            m_currentNode = m_root = new ProfilerTreeNode(dataList[0], 0);
        }
        else
        {
            m_currentNode = m_root;
        }
    }

    m_currentNode->updateData(dataList);
}

void ProfilerWidget::pop()
{
    Q_ASSERT(m_currentNode != 0);
    m_currentNode = m_currentNode->parent();
}

void ProfilerWidget::update()
{
    if(m_enabled)
    {
        // Clear tree
        ui->profilerTree->clear();

        // Build tree
        buildTree(m_root, 0, 0.0f, 0.0f);

        // Set node values
        if(ui->stepRadioButton->isChecked())
        {
            m_root = 0;
        }
        m_currentNode = 0;
    }
    else
    {
        if(m_root)
        {
            deleteTree(m_root);
        }
        m_root = m_currentNode = 0;
    }
}

void ProfilerWidget::buildTree(ProfilerTreeNode *node, QTreeWidgetItem *item, float parentTime, float rootTime)
{
    QTreeWidgetItem *childItem = new QTreeWidgetItem(item);
    node->update(childItem, parentTime, rootTime);

    foreach(ProfilerTreeNode *childNode, node->children())
    {
        buildTree(childNode, childItem, parentTime, rootTime);
    }

    if(ui->stepRadioButton->isChecked())
    {
        delete node;
    }

    if(item == 0)
    {
        ui->profilerTree->addTopLevelItem(childItem);
    }
}

void ProfilerWidget::deleteTree(ProfilerTreeNode *node)
{
    foreach(ProfilerTreeNode *child, node->children())
    {
        deleteTree(child);
    }
    delete node;
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

ProfilerTreeNode::ProfilerTreeNode(const QString &name, ProfilerTreeNode *parent) :
    m_parent(parent),
    m_name(name)
{
    if(m_parent)
    {
        m_parent->m_children.push_back(this);
    }
    resetData();
}

void ProfilerTreeNode::updateData(const QStringList &dataList)
{
    Q_ASSERT(dataList.size() == 5);

    // Apply data
    totalTime += dataList[1].toInt();
    maxTime = qMax<int>(dataList[2].toInt(), maxTime);
    minTime = qMin<int>(dataList[3].toInt(), minTime);
    callCount += dataList[4].toInt();
}

void ProfilerTreeNode::resetData()
{
    totalTime = 0;
    maxTime = INT_MIN;
    minTime = INT_MAX;
    callCount = 0;
}

void ProfilerTreeNode::update(QTreeWidgetItem *item, float &parentTime, float &rootTime)
{
    // Calculate percentages
    float branchPercent = 0.0f, rootPercent = 0.0f;
    if(m_parent)
    {
        branchPercent = totalTime/parentTime;
        rootPercent = totalTime/rootTime;
    }
    else
    {
        branchPercent = 1.0f;
        rootPercent = 1.0f;
        rootTime = totalTime;
    }
    parentTime = totalTime;

    // Update all texts
    item->setText(0, m_name);
    item->setText(1, QString("%1 ms").arg(QString::number(maxTime)));
    item->setText(2, QString("%1 ms").arg(QString::number(minTime)));
    item->setText(3, QString("%1 ms").arg(QString::number(totalTime/callCount)));
    item->setText(4, QString("%1 ms").arg(QString::number(totalTime)));
    item->setText(5, QString::number(callCount));
    item->setText(6, QString("%1%").arg(QString::number(branchPercent*100, 'f', 2)));
    item->setText(7, QString("%1%").arg(QString::number(rootPercent*100, 'f', 2)));
}

QString ProfilerTreeNode::name() const
{
    return m_name;
}

ProfilerTreeNode *ProfilerTreeNode::parent() const
{
    return m_parent;
}

QList<ProfilerTreeNode *> ProfilerTreeNode::children() const
{
    return m_children;
}
