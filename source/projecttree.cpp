//     _    ____ ___ ____  _____
//    / \  / ___|_ _|  _ \| ____|
//   / _ \ \___ \| || | | |  _|
//  / ___ \ ___) | || |_| | |___
// /_/   \_\____/___|____/|_____|
// Originally written by Marcus Loo Vergara (aka. Bitsauce)
// 2011-2014 (C)

#include "projecttree.h"

#include "workspace.h"
#include "project.h"
#include "settings.h"
#include "scripteditor.h"

//---------------------------------------------
// ProjectTree
//---------------------------------------------

ProjectTree::ProjectTree(QWidget *parent) :
    QTreeView(parent)
{
    // Setup contex menut
    QAction *folder = new QAction("Add folder", this);
    folder->setIcon(QIcon(":/menubar/icons/new_folder.png"));
    QAction *browse = new QAction("Open in explorer", this);

    QAction *separator1 = new QAction(this);
    separator1->setSeparator(true);

    QAction *separator2 = new QAction(this);
    separator2->setSeparator(true);

    connect(folder, SIGNAL(triggered()), this, SLOT(createFolderInCurrentDirectory()));
    connect(browse, SIGNAL(triggered()), this, SLOT(showCurrentDirectoryInExplorer()));

    addAction(folder);
    addAction(browse);
    addAction(separator1);
    addAction(workspace()->cutAction());
    addAction(workspace()->copyAction());
    addAction(workspace()->pasteAction());
    addAction(separator2);
    addAction(workspace()->newAction());
    addAction(workspace()->renameAction());
    addAction(workspace()->deleteAction());

    setContextMenuPolicy(Qt::ActionsContextMenu);

    // Setup tree model
    treeModel = new QFileSystemModel(this);
    treeModel->setReadOnly(false);

    proxyModel = new FileSystemSortProxyModel(this);
    proxyModel->setDynamicSortFilter(true);
    proxyModel->setSourceModel(treeModel);
    setModel(proxyModel);

    // Setup tree
    //setAnimated(true);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QTreeView::DragDrop);
    setSelectionMode(QTreeView::ExtendedSelection);
    setSortingEnabled(true);
    sortByColumn(0, Qt::AscendingOrder);

    // Remove header
    header()->hideSection(3);
    header()->hideSection(2);
    header()->hideSection(1);
    header()->close();
}

ProjectTree::~ProjectTree()
{
}

void ProjectTree::setRootPath(QString rootPath)
{
    // Set root path
    QModelIndex index = treeModel->setRootPath(rootPath);
    setRootIndex(proxyModel->mapFromSource(index));
    setCurrentIndex(rootIndex());
}

//---------------------------------------------
// Slots
//---------------------------------------------

void ProjectTree::startDrag(Qt::DropActions supportedActions)
{
    QModelIndexList proxyIndexes = selectedIndexes();
    QList<QPersistentModelIndex> persistentIndexes;
    QModelIndexList indexes;
    foreach(QModelIndex index, proxyIndexes)
        indexes.push_back(proxyModel->mapToSource(index));

    if(indexes.count() > 0)
    {
        QMimeData *data = treeModel->mimeData(indexes);
        if(!data)
            return;

        for(int i = 0; i < indexes.count(); i++)
        {
            QModelIndex idx = indexes.at(i);
            persistentIndexes.append(QPersistentModelIndex(idx));
        }

        QPixmap pixmap = indexes.first().data(Qt::DecorationRole).value<QPixmap>();
        QDrag *drag = new QDrag(this);
        drag->setPixmap(pixmap);
        drag->setMimeData(data);
        drag->setHotSpot(QPoint(pixmap.width()/2, pixmap.height()/2));

        Qt::DropAction defaultDropAction = Qt::IgnoreAction;
        if(supportedActions & Qt::MoveAction && dragDropMode() != QAbstractItemView::InternalMove)
            defaultDropAction = Qt::MoveAction;

        if(drag->exec(supportedActions, defaultDropAction) == Qt::MoveAction)
        {
            for(int i = 0; i < indexes.count(); i++)
            {
                QPersistentModelIndex idx = persistentIndexes.at(i);
                if (idx.isValid())
                    treeModel->removeRow(idx.row(), idx.parent());
                else
                    treeModel->removeRow(idx.row(), QModelIndex());
            }
        }
    }
}

bool ProjectTree::edit(const QModelIndex &index, EditTrigger trigger, QEvent *event)
{
    if(trigger == QAbstractItemView::DoubleClicked)
    {
        doubleClicked(index);
        return true;
    }
    return QTreeView::edit(index, trigger, event);
}

void ProjectTree::doubleClicked(const QModelIndex &index)
{
    // Open double clicked file, if linked to an interface
    QFileInfo fileInfo = treeModel->fileInfo(proxyModel->mapToSource(index));
    if(fileInfo.isDir())
    {
        if(!isExpanded(index))
            expand(index);
        else
            collapse(index);
    }else{
        workspace()->openFile(fileInfo.absoluteFilePath());
    }
}

void ProjectTree::focusInEvent(QFocusEvent *event)
{
    // Connect actions
    workspace()->cutAction()->setEnabled(true);
    disconnect(workspace()->cutAction(), 0, 0, 0);
    connect(workspace()->cutAction(), SIGNAL(triggered()), this, SLOT(cutSelection()));
    workspace()->copyAction()->setEnabled(true);
    disconnect(workspace()->copyAction(), 0, 0, 0);
    connect(workspace()->copyAction(), SIGNAL(triggered()), this, SLOT(copySelection()));
    workspace()->pasteAction()->setEnabled(true);
    disconnect(workspace()->pasteAction(), 0, 0, 0);
    connect(workspace()->pasteAction(), SIGNAL(triggered()), this, SLOT(pasteClipboard()));

    workspace()->newAction()->setEnabled(true);
    disconnect(workspace()->newAction(), 0, 0, 0);
    connect(workspace()->newAction(), SIGNAL(triggered()), this, SLOT(createItemInCurrentDirectory()));
    workspace()->renameAction()->setEnabled(true);
    disconnect(workspace()->renameAction(), 0, 0, 0);
    connect(workspace()->renameAction(), SIGNAL(triggered()), this, SLOT(renameSelection()));
    workspace()->deleteAction()->setEnabled(true);
    disconnect(workspace()->deleteAction(), 0, 0, 0);
    connect(workspace()->deleteAction(), SIGNAL(triggered()), this, SLOT(deleteSelection()));

    QTreeView::focusInEvent(event);
}

void ProjectTree::mousePressEvent(QMouseEvent *e)
{
    // Button events
    if(e->button() == Qt::LeftButton &&
            !(e->modifiers() & Qt::ControlModifier) &&
            !(e->modifiers() & Qt::ShiftModifier))
    {
        QModelIndex index = indexAt(e->pos());
        if(!index.isValid())
        {
            clearSelection();
            setCurrentIndex(rootIndex());
        }
    }
    QTreeView::mousePressEvent(e);
}

void ProjectTree::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if(!current.isValid() || current == rootIndex())
    {
        workspace()->cutAction()->setEnabled(false);
        workspace()->copyAction()->setEnabled(false);
        workspace()->deleteAction()->setEnabled(false);
        workspace()->renameAction()->setEnabled(false);
    }else{
        workspace()->cutAction()->setEnabled(true);
        workspace()->copyAction()->setEnabled(true);
        workspace()->deleteAction()->setEnabled(true);
        workspace()->renameAction()->setEnabled(true);
    }
    QTreeView::currentChanged(current, previous);
}

void ProjectTree::deleteSelection()
{
    // Delete selected tree items
    QModelIndexList indexes = selectedIndexes();

    if(indexes.size() > 1)
    {
        // When deleting more than one file
        int r = QMessageBox::warning(this, "Warning", "You are trying to delete "
                                     "more than one file, do you want to continue?",
                                     QMessageBox::Yes, QMessageBox::No);

        // Cancel delete
        if(r == QMessageBox::No)
            return;
    }

    foreach(QModelIndex index, indexes)
    {
        index = proxyModel->mapToSource(index);
        if(treeModel->fileInfo(index).suffix() == "x2d")
        {
            // When deleting the project file
            QMessageBox::warning(this, "Error", "Project files can not be deleted.",
                                 QMessageBox::Ok, QMessageBox::NoButton);
            continue;
        }

        treeModel->remove(index);
    }
}

void ProjectTree::renameSelection()
{
    // Make sure index is valid
    QModelIndex index = proxyModel->mapToSource(currentIndex());
    if(!index.isValid()) {
        return;
    }

    // Get new name
    QString newname = QInputDialog::getText(this, tr("Rename"), tr("Enter a new name:"), QLineEdit::Normal, treeModel->fileInfo(index).baseName());
    if(newname.isEmpty()) {
        return;
    }

    QFileInfo io(treeModel->fileInfo(index));
    if(io.isDir())
    {
        // Rename dir
        QFile dir(treeModel->filePath(index));
        dir.rename(io.absolutePath() + "/" + newname);
    }else{
        // Rename file
        QFile file(treeModel->filePath(index));
        file.rename(io.absolutePath() + "/" + newname + "." + io.suffix());
    }
}

void ProjectTree::showItemCreate(QString defaultDir)
{
    // Get the file type filter for the editor
    QString filter;
    foreach(QString fileType, settings()->fileTypes())
    {
        QStringList list = fileType.split(";");
        filter += QString("%1 (*.%2);;").arg(list[0], list[1]);
    }

    // Get new file name
    QString newFile = QFileDialog::getSaveFileName(this, tr("New File"), defaultDir, filter);
    if(!newFile.isEmpty())
    {
        // Create the script file
        ScriptEditor::createFile(newFile);
    }
}

void ProjectTree::createItemInCurrentDirectory()
{
    // Get current directory
    QModelIndex index = proxyModel->mapToSource(currentIndex());
    QString directory = Project::getDirectory();
    if(index.isValid())
    {
        if(treeModel->isDir(index))
        {
            directory = treeModel->filePath(index);
        }else{
            directory = treeModel->filePath(index.parent());
        }
    }

    // Show new file dialog starting in 'directory'
    showItemCreate(directory);

    // Expand if we created an item in a folder
    if(treeModel->isDir(index)) {
        expand(proxyModel->mapFromSource(index));
    }
}

void ProjectTree::createFolderInCurrentDirectory()
{
    // Add a tree folder
    QModelIndex index = proxyModel->mapToSource(currentIndex());
    if(!index.isValid()) {
        return;
    }

    // Get new folder name
    QString folerName = QInputDialog::getText(this, tr("Add Folder"), tr("Enter folder name:"), QLineEdit::Normal,  tr("folder"));
    if(folerName.isEmpty()) {
        return;
    }

    // Create folder
    if(treeModel->isDir(index))
    {
        treeModel->mkdir(index, folerName);
        expand(index);
    }else{
        treeModel->mkdir(index.parent(), folerName);
    }
}

void ProjectTree::showCurrentDirectoryInExplorer()
{
    // Get current index folder
    QModelIndex index = proxyModel->mapToSource(currentIndex());
    QString folderPath = Project::getDirectory();
    if(index.isValid())
    {
        if(treeModel->isDir(index)) {
            folderPath = treeModel->filePath(index);
        }else{
            folderPath = treeModel->filePath(index.parent());
        }
    }

    // Open folder path
    QString path = QDir::toNativeSeparators(folderPath);
    QDesktopServices::openUrl(QUrl("file:///" + path));
}

void ProjectTree::cutSelection()
{
    // Get indexes to cut
    QList<QUrl> urls;
    foreach(QModelIndex index, selectedIndexes())
    {
        bool parentSelected = false;
        QModelIndex findIndex = index;
        while(findIndex.parent() != rootIndex())
        {
            if(selectionModel()->isSelected(findIndex.parent()))
            {
                parentSelected = true;
                break;
            }
            findIndex = findIndex.parent();
        }
        if(parentSelected)
            continue;

        // Make sure we only have copy data
        copyData.clear();

        // Set mime data
        index = proxyModel->mapToSource(index);
        urls.push_back(treeModel->fileInfo(index).absoluteFilePath());
    }
    cutData.setUrls(urls);
    workspace()->pasteAction()->setEnabled(true);
}

void ProjectTree::copySelection()
{
    // Get indexes to copy
    QList<QUrl> urls;
    foreach(QModelIndex index, selectedIndexes())
    {
        bool parentSelected = false;
        QModelIndex findIndex = index;
        while(findIndex.parent() != rootIndex())
        {
            if(selectionModel()->isSelected(findIndex.parent()))
            {
                parentSelected = true;
                break;
            }
            findIndex = findIndex.parent();
        }
        if(parentSelected)
            continue;

        // Make sure we only have copy data
        cutData.clear();

        // Set mime data
        index = proxyModel->mapToSource(index);
        urls.push_back(treeModel->fileInfo(index).absoluteFilePath());
    }
    copyData.setUrls(urls);
    workspace()->pasteAction()->setEnabled(true);
}

void copyFolder(QString sourceFolder, QString destFolder)
{
    QDir sourceDir(sourceFolder);
    if(!sourceDir.exists())
        return;

    QDir destDir(destFolder);
    if(!destDir.exists())
        destDir.mkdir(destFolder);

    QStringList files = sourceDir.entryList(QDir::Files);
    for(int i = 0; i < files.count(); i++)
    {
        QString srcName = sourceFolder + "/" + files[i];
        QString destName = destFolder + "/" + files[i];
        QFile::copy(srcName, destName);
    }
    files.clear();

    files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for(int i = 0; i < files.count(); i++)
    {
        QString srcName = sourceFolder + "/" + files[i];
        QString destName = destFolder + "/" + files[i];
        copyFolder(srcName, destName);
    }
}

void ProjectTree::pasteClipboard()
{
    // Get copy or cut
    bool copy = false;
    bool cut = false;
    if(copyData.hasUrls())
        copy = true;
    if(cutData.hasUrls())
        cut = true;

    // Sanity xor check
    if((!copy && !cut) || (copy && cut))
        return;

    // Get index to paste within
    QModelIndex index = proxyModel->mapToSource(currentIndex());
    if(!index.isValid())
        return;
    if(!treeModel->isDir(index))
    {
        index = index.parent();
        if(!index.isValid())
            return;
    }

    // Get file urls
    QList<QUrl> urls;
    if(copy) urls = copyData.urls();
    else urls = cutData.urls();

    // Get file info
    foreach(QUrl url, urls)
    {
        QFileInfo io(url.toString());
        if(!io.exists())
        {
            QMessageBox::information(this, cut ? "Unable to move" : "Unable to copy",
                                     cut ? "Could not find the file to move." :
                                           "Could not find the file to copy.",
                                     QMessageBox::Ok);
            if(cut)
            {
                // Clear cut data
                workspace()->pasteAction()->setEnabled(false);
                cutData.clear();
            }
            return;
        }

        // Make sure the operation is legal
        QString source = io.absoluteFilePath() + "/";
        QString dest = treeModel->filePath(index) + "/" + io.fileName() + "/";
        if(source == dest && cut)
        {
            QMessageBox::information(this, "Unable to move",
                                     "Destination folder is same as source.",
                                     QMessageBox::Ok);

            // Clear cut data
            workspace()->pasteAction()->setEnabled(false);
            cutData.clear();
            return;
        }
        else if(dest.contains(source))
        {
            if(source != dest)
            {
                QMessageBox::information(this, cut ? "Unable to move" : "Unable to copy",
                                         "Destination folder is a subfolder of "
                                         "the source folder.",
                                         QMessageBox::Ok);
                if(cut)
                {
                    // Clear cut data
                    workspace()->pasteAction()->setEnabled(false);
                    cutData.clear();
                }
                return;
            }
        }

        // Check for directory
        if(io.isDir())
        {
            // Get dir name
            QString dirName = io.fileName();
            int c = 0;
            while(QDir(treeModel->filePath(index) + "/" + dirName).exists())
            {
                if(c == 0) dirName = io.baseName() + "_copy";
                else dirName = io.baseName() + "_copy_" + QString::number(c);
                c++;
            }

            // Create folders
            QModelIndex dirIndex = treeModel->mkdir(index, dirName);

            // Copy folder
            copyFolder(io.absoluteFilePath(), treeModel->filePath(dirIndex));

            // Perform cut
            if(cut)
            {
                // Remove folder
                treeModel->remove(treeModel->index(io.absoluteFilePath()));

                // Clear cut data
                workspace()->pasteAction()->setEnabled(false);
                cutData.clear();
            }

        }else{
            // Copy file
            QFile file(io.absoluteFilePath());

            // Check if a file with the
            // same name exists in the dir
            QString fileName = io.fileName();
            int c = 0;
            while(QFile(treeModel->filePath(index) + "/" + fileName).exists())
            {
                if(c == 0) fileName = io.baseName() + "_copy." + io.suffix();
                else fileName = io.baseName() + "_copy_" + QString::number(c) + "." + io.suffix();
                c++;
            }

            file.copy(treeModel->filePath(index) + "/" + fileName);

            // Perform cut
            if(cut)
            {
                // Remove file
                treeModel->remove(treeModel->index(io.absoluteFilePath()));

                // Clear cut data
                workspace()->pasteAction()->setEnabled(false);
                cutData.clear();
            }
        }
    }

    if(treeModel->isDir(index))
        expand(proxyModel->mapFromSource(index));
}
