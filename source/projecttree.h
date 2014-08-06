#ifndef PROJECTTREE_H
#define PROJECTTREE_H

#include <QtCore>
#include <QtWidgets>

//------------------------------------------------
// ProjectTree
//------------------------------------------------

class FileSystemSortProxyModel  : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    FileSystemSortProxyModel(QObject *parent) :
        QSortFilterProxyModel(parent)
    {
    }
protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const
    {
        QFileSystemModel* model = qobject_cast<QFileSystemModel*>(sourceModel());

        // To keep the the folder always on the up, we need to do the followings
        // while the compare indice are folder & file exclusively.
        if(model){
            if((model->isDir(left) && !model->isDir(right))){
                return sortOrder() == Qt::AscendingOrder;
            }
            else if((!model->isDir(left) && model->isDir(right))){
                return sortOrder() == Qt::DescendingOrder;
            }
        }

        return QSortFilterProxyModel::lessThan(left, right);
    }
};


class ProjectTree : public QTreeView
{
    Q_OBJECT
public:
    explicit ProjectTree(QWidget *parent = 0);
    ~ProjectTree();

    void setRootPath(QString rootPath);

private:
    QFileSystemModel *treeModel;
    QMimeData cutData;
    QMimeData copyData;
    FileSystemSortProxyModel *proxyModel;

private:
    // Reimplemented startDrag for drag drop moving
    void startDrag(Qt::DropActions supportedActions);

    // Reimplement doubleClick
    bool edit(const QModelIndex &index, EditTrigger trigger, QEvent *event);

    // Double click
    void doubleClicked(const QModelIndex &index);

    // Focus event
    void focusInEvent(QFocusEvent *event);

    // Mouse press event
    void mousePressEvent(QMouseEvent *event);

    void currentChanged(const QModelIndex &current, const QModelIndex &previous);

public slots:

    // Tree
    void cutSelection();
    void copySelection();
    void pasteClipboard();

    // Item creation
    void showItemCreate(QString defaultDir);
    void createItemInCurrentDirectory();

    // Item modification
    void deleteSelection();
    void renameSelection();

    // Folder creation
    void createFolderInCurrentDirectory();

    // Explorer
    void showCurrentDirectoryInExplorer();
};


#endif // FILETREE_H
