/********************************************************************************
** Form generated from reading UI file 'spriteeditor.ui'
**
** Created: Tue 10. Jul 17:37:58 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEEDITOR_H
#define UI_SPRITEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteEditor
{
public:
    QAction *actionExit_and_Save;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionImage_Size;
    QAction *actionCanvas_Size;
    QAction *actionHide_Layers;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QWidget *workspace;
    QGridLayout *gridLayout_4;
    QFrame *layers;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QLabel *label_3;
    QListWidget *listWidget;
    QLabel *label_2;
    QGridLayout *gridLayout_6;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QWidget *toolbox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QPushButton *pencilButton;
    QPushButton *brushButton;
    QPushButton *eraseButton;
    QPushButton *lineButton;
    QPushButton *boxButton;
    QPushButton *circleButton;
    QPushButton *rectmarkButton;
    QPushButton *eyedropButton;
    QPushButton *zoomoutButton;
    QPushButton *zoominButton;
    QPushButton *scaleButton;
    QPushButton *rotateButton;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *sizeEdit;
    QLabel *label_4;
    QLineEdit *transpEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindow;
    QMenu *menuLayers;
    QMenu *menuImage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SpriteEditor)
    {
        if (SpriteEditor->objectName().isEmpty())
            SpriteEditor->setObjectName(QString::fromUtf8("SpriteEditor"));
        SpriteEditor->resize(560, 329);
        actionExit_and_Save = new QAction(SpriteEditor);
        actionExit_and_Save->setObjectName(QString::fromUtf8("actionExit_and_Save"));
        actionClose = new QAction(SpriteEditor);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave = new QAction(SpriteEditor);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(SpriteEditor);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionCut = new QAction(SpriteEditor);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(SpriteEditor);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(SpriteEditor);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionOpen = new QAction(SpriteEditor);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(SpriteEditor);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionImage_Size = new QAction(SpriteEditor);
        actionImage_Size->setObjectName(QString::fromUtf8("actionImage_Size"));
        actionCanvas_Size = new QAction(SpriteEditor);
        actionCanvas_Size->setObjectName(QString::fromUtf8("actionCanvas_Size"));
        actionHide_Layers = new QAction(SpriteEditor);
        actionHide_Layers->setObjectName(QString::fromUtf8("actionHide_Layers"));
        centralwidget = new QWidget(SpriteEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(256, 256));
        scrollArea->setWidgetResizable(true);
        workspace = new QWidget();
        workspace->setObjectName(QString::fromUtf8("workspace"));
        workspace->setGeometry(QRect(0, 0, 254, 254));
        gridLayout_4 = new QGridLayout(workspace);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea->setWidget(workspace);
        splitter->addWidget(scrollArea);
        layers = new QFrame(splitter);
        layers->setObjectName(QString::fromUtf8("layers"));
        layers->setMinimumSize(QSize(146, 256));
        layers->setMaximumSize(QSize(266, 16777215));
        layers->setFrameShape(QFrame::StyledPanel);
        gridLayout_2 = new QGridLayout(layers);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(layers);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(layers);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(layers);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(layers);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(layers);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        horizontalLayout->addWidget(toolButton_5);


        gridLayout_2->addLayout(horizontalLayout, 7, 0, 1, 1);

        label_3 = new QLabel(layers);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        listWidget = new QListWidget(layers);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(listWidget, 6, 0, 1, 1);

        label_2 = new QLabel(layers);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSlider = new QSlider(layers);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(horizontalSlider, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layers);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);
        lineEdit->setMinimumSize(QSize(29, 20));
        lineEdit->setMaximumSize(QSize(29, 20));

        gridLayout_6->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 4, 0, 1, 1);

        splitter->addWidget(layers);

        gridLayout->addWidget(splitter, 0, 1, 1, 1);

        toolbox = new QWidget(centralwidget);
        toolbox->setObjectName(QString::fromUtf8("toolbox"));
        verticalLayout = new QVBoxLayout(toolbox);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pencilButton = new QPushButton(toolbox);
        pencilButton->setObjectName(QString::fromUtf8("pencilButton"));
        pencilButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/editors/sprite/icons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        pencilButton->setIcon(icon);
        pencilButton->setCheckable(true);
        pencilButton->setChecked(true);

        gridLayout_3->addWidget(pencilButton, 0, 0, 1, 1);

        brushButton = new QPushButton(toolbox);
        brushButton->setObjectName(QString::fromUtf8("brushButton"));
        brushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/editors/sprite/icons/brush.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushButton->setIcon(icon1);
        brushButton->setCheckable(true);

        gridLayout_3->addWidget(brushButton, 0, 1, 1, 1);

        eraseButton = new QPushButton(toolbox);
        eraseButton->setObjectName(QString::fromUtf8("eraseButton"));
        sizePolicy2.setHeightForWidth(eraseButton->sizePolicy().hasHeightForWidth());
        eraseButton->setSizePolicy(sizePolicy2);
        eraseButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/editors/sprite/icons/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraseButton->setIcon(icon2);
        eraseButton->setCheckable(true);

        gridLayout_3->addWidget(eraseButton, 0, 2, 1, 1);

        lineButton = new QPushButton(toolbox);
        lineButton->setObjectName(QString::fromUtf8("lineButton"));
        lineButton->setStyleSheet(QString::fromUtf8(""));
        lineButton->setIcon(icon);
        lineButton->setCheckable(true);

        gridLayout_3->addWidget(lineButton, 1, 0, 1, 1);

        boxButton = new QPushButton(toolbox);
        boxButton->setObjectName(QString::fromUtf8("boxButton"));
        boxButton->setStyleSheet(QString::fromUtf8(""));
        boxButton->setIcon(icon);
        boxButton->setCheckable(true);

        gridLayout_3->addWidget(boxButton, 1, 1, 1, 1);

        circleButton = new QPushButton(toolbox);
        circleButton->setObjectName(QString::fromUtf8("circleButton"));
        circleButton->setStyleSheet(QString::fromUtf8(""));
        circleButton->setIcon(icon);
        circleButton->setCheckable(true);

        gridLayout_3->addWidget(circleButton, 1, 2, 1, 1);

        rectmarkButton = new QPushButton(toolbox);
        rectmarkButton->setObjectName(QString::fromUtf8("rectmarkButton"));
        rectmarkButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/editors/sprite/icons/rectmark.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectmarkButton->setIcon(icon3);
        rectmarkButton->setCheckable(true);

        gridLayout_3->addWidget(rectmarkButton, 2, 0, 1, 1);

        eyedropButton = new QPushButton(toolbox);
        eyedropButton->setObjectName(QString::fromUtf8("eyedropButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/editors/sprite/icons/eyedropper.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyedropButton->setIcon(icon4);
        eyedropButton->setCheckable(true);

        gridLayout_3->addWidget(eyedropButton, 2, 1, 1, 1);

        zoomoutButton = new QPushButton(toolbox);
        zoomoutButton->setObjectName(QString::fromUtf8("zoomoutButton"));
        zoomoutButton->setStyleSheet(QString::fromUtf8(""));
        zoomoutButton->setIcon(icon);
        zoomoutButton->setCheckable(true);

        gridLayout_3->addWidget(zoomoutButton, 3, 2, 1, 1);

        zoominButton = new QPushButton(toolbox);
        zoominButton->setObjectName(QString::fromUtf8("zoominButton"));
        zoominButton->setStyleSheet(QString::fromUtf8(""));
        zoominButton->setIcon(icon);
        zoominButton->setCheckable(true);

        gridLayout_3->addWidget(zoominButton, 3, 1, 1, 1);

        scaleButton = new QPushButton(toolbox);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/editors/sprite/icons/scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        scaleButton->setIcon(icon5);
        scaleButton->setCheckable(true);

        gridLayout_3->addWidget(scaleButton, 3, 0, 1, 1);

        rotateButton = new QPushButton(toolbox);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/editors/sprite/icons/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotateButton->setIcon(icon6);

        gridLayout_3->addWidget(rotateButton, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        scrollArea_2 = new QScrollArea(toolbox);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        sizePolicy1.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy1);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 113, 108));
        formLayout = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        sizeEdit = new QLineEdit(scrollAreaWidgetContents_2);
        sizeEdit->setObjectName(QString::fromUtf8("sizeEdit"));
        sizePolicy2.setHeightForWidth(sizeEdit->sizePolicy().hasHeightForWidth());
        sizeEdit->setSizePolicy(sizePolicy2);
        sizeEdit->setMinimumSize(QSize(22, 20));
        sizeEdit->setMaximumSize(QSize(22, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, sizeEdit);

        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        transpEdit = new QLineEdit(scrollAreaWidgetContents_2);
        transpEdit->setObjectName(QString::fromUtf8("transpEdit"));
        sizePolicy2.setHeightForWidth(transpEdit->sizePolicy().hasHeightForWidth());
        transpEdit->setSizePolicy(sizePolicy2);
        transpEdit->setMinimumSize(QSize(22, 20));
        transpEdit->setMaximumSize(QSize(22, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, transpEdit);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);


        gridLayout->addWidget(toolbox, 0, 0, 1, 1);

        SpriteEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpriteEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 560, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuLayers = new QMenu(menubar);
        menuLayers->setObjectName(QString::fromUtf8("menuLayers"));
        menuImage = new QMenu(menubar);
        menuImage->setObjectName(QString::fromUtf8("menuImage"));
        SpriteEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(SpriteEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SpriteEditor->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuImage->menuAction());
        menubar->addAction(menuLayers->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuImage->addAction(actionImage_Size);
        menuImage->addAction(actionCanvas_Size);

        retranslateUi(SpriteEditor);
        QObject::connect(actionClose, SIGNAL(triggered()), SpriteEditor, SLOT(close()));
        QObject::connect(actionImage_Size, SIGNAL(triggered()), SpriteEditor, SLOT(imageResize()));
        QObject::connect(actionSave, SIGNAL(triggered()), SpriteEditor, SLOT(editSave()));
        QObject::connect(actionCopy, SIGNAL(activated()), SpriteEditor, SLOT(keyCopy()));
        QObject::connect(actionCut, SIGNAL(activated()), SpriteEditor, SLOT(keyCut()));
        QObject::connect(actionPaste, SIGNAL(activated()), SpriteEditor, SLOT(keyPaste()));
        QObject::connect(pencilButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintPencil()));
        QObject::connect(eraseButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintErase()));
        QObject::connect(brushButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintBrush()));
        QObject::connect(rectmarkButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintRectMark()));
        QObject::connect(zoominButton, SIGNAL(clicked()), SpriteEditor, SLOT(imageZoomIn()));
        QObject::connect(zoomoutButton, SIGNAL(clicked()), SpriteEditor, SLOT(imageZoomOut()));
        QObject::connect(sizeEdit, SIGNAL(editingFinished()), SpriteEditor, SLOT(paintSetSize()));
        QObject::connect(transpEdit, SIGNAL(editingFinished()), SpriteEditor, SLOT(paintSetTransp()));
        QObject::connect(eyedropButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintEyeDrop()));
        QObject::connect(rotateButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintRotate()));
        QObject::connect(scaleButton, SIGNAL(clicked()), SpriteEditor, SLOT(paintScale()));

        QMetaObject::connectSlotsByName(SpriteEditor);
    } // setupUi

    void retranslateUi(QMainWindow *SpriteEditor)
    {
        SpriteEditor->setWindowTitle(QApplication::translate("SpriteEditor", "sprite", 0, QApplication::UnicodeUTF8));
        actionExit_and_Save->setText(QApplication::translate("SpriteEditor", "Save and Exit", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("SpriteEditor", "&Close", 0, QApplication::UnicodeUTF8));
        actionClose->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("SpriteEditor", "&Save...", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("SpriteEditor", "Save &As...", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("SpriteEditor", "C&ut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("SpriteEditor", "&Copy", 0, QApplication::UnicodeUTF8));
        actionCopy->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("SpriteEditor", "&Paste", 0, QApplication::UnicodeUTF8));
        actionPaste->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SpriteEditor", "&Open...", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("SpriteEditor", "&New...", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("SpriteEditor", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionImage_Size->setText(QApplication::translate("SpriteEditor", "Image Size...", 0, QApplication::UnicodeUTF8));
        actionCanvas_Size->setText(QApplication::translate("SpriteEditor", "Canvas Size...", 0, QApplication::UnicodeUTF8));
        actionHide_Layers->setText(QApplication::translate("SpriteEditor", "Hide Layers", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("SpriteEditor", "New Layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("SpriteEditor", "N", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_2->setToolTip(QApplication::translate("SpriteEditor", "Move Up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_2->setText(QApplication::translate("SpriteEditor", "U", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_3->setToolTip(QApplication::translate("SpriteEditor", "Move Down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_3->setText(QApplication::translate("SpriteEditor", "D", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_4->setToolTip(QApplication::translate("SpriteEditor", "Duplicate Layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_4->setText(QApplication::translate("SpriteEditor", "X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_5->setToolTip(QApplication::translate("SpriteEditor", "Delete Layer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_5->setText(QApplication::translate("SpriteEditor", "R", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpriteEditor", "Opacity:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpriteEditor", "Layers:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("SpriteEditor", "1.00", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pencilButton->setToolTip(QApplication::translate("SpriteEditor", "Pencil", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pencilButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        brushButton->setToolTip(QApplication::translate("SpriteEditor", "Brush", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        brushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        eraseButton->setToolTip(QApplication::translate("SpriteEditor", "Eraser", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        eraseButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineButton->setToolTip(QApplication::translate("SpriteEditor", "Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        boxButton->setToolTip(QApplication::translate("SpriteEditor", "Box", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        boxButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        circleButton->setToolTip(QApplication::translate("SpriteEditor", "Circle", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        circleButton->setText(QString());
        rectmarkButton->setText(QString());
        eyedropButton->setText(QString());
        zoomoutButton->setText(QString());
        zoominButton->setText(QString());
        scaleButton->setText(QString());
        rotateButton->setText(QString());
        label->setText(QApplication::translate("SpriteEditor", "Size:", 0, QApplication::UnicodeUTF8));
        sizeEdit->setText(QApplication::translate("SpriteEditor", "5", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SpriteEditor", "Opacity:", 0, QApplication::UnicodeUTF8));
        transpEdit->setText(QApplication::translate("SpriteEditor", "1.0", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("SpriteEditor", "&Sprite", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("SpriteEditor", "&Edit", 0, QApplication::UnicodeUTF8));
        menuWindow->setTitle(QApplication::translate("SpriteEditor", "Window", 0, QApplication::UnicodeUTF8));
        menuLayers->setTitle(QApplication::translate("SpriteEditor", "Layers", 0, QApplication::UnicodeUTF8));
        menuImage->setTitle(QApplication::translate("SpriteEditor", "Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpriteEditor: public Ui_SpriteEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITOR_H
