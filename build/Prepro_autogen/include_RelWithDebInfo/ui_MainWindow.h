/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvtkopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *mouseMode_gb;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *mouseModeOrient_rb;
    QRadioButton *mouseModeSel_rb;
    QToolBox *toolBox;
    QWidget *page1;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *selMode_gb;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *add_rb;
    QRadioButton *replace_rb;
    QRadioButton *subtract_rb;
    QRadioButton *reselect_rb;
    QVBoxLayout *verticalLayout_5;
    QPushButton *selectAll_pb;
    QPushButton *unselectAll_pb;
    QPushButton *selectInvert_pb;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_7;
    QPushButton *showSelection_pb;
    QPushButton *hideSelection_pb;
    QPushButton *showAll_pb;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *selEntity_gb;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *selFaces_rb;
    QRadioButton *selVolumes_rb;
    QRadioButton *selNodes_rb;
    QRadioButton *selEdges_rb;
    QGroupBox *selMethod_gb;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *selMethodBox_rb;
    QRadioButton *selMethodSlider_rb;
    QGroupBox *selSlide_gb;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_3;
    QSlider *slideSelYm_slider;
    QDoubleSpinBox *slideSelYm_spin;
    QSplitter *splitter;
    QSlider *slideSelZm_slider;
    QDoubleSpinBox *slideSelZm_spin;
    QSplitter *splitter_2;
    QSlider *slideSelZp_slider;
    QDoubleSpinBox *slideSelZp_spin;
    QSplitter *splitter_6;
    QSlider *slideSelXp_slider;
    QDoubleSpinBox *slideSelXp_spin;
    QSplitter *splitter_4;
    QSlider *slideSelYp_slider;
    QDoubleSpinBox *slideSelYp_spin;
    QSplitter *splitter_5;
    QSlider *slideSelXm_slider;
    QDoubleSpinBox *slideSelXm_spin;
    QCheckBox *selBoxBoundary_cb;
    QCheckBox *selBoxInside_cb;
    QWidget *page_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QPushButton *viewXp_pb;
    QPushButton *viewXm_pb;
    QPushButton *viewYp_pb;
    QPushButton *viewZp_pb;
    QPushButton *viewYm_pb;
    QPushButton *viewZm_pb;
    QCheckBox *viewParallelProjection_cb;
    QWidget *page2;
    QGroupBox *display_gb;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *displayVol_cb;
    QCheckBox *displayVolSel_cb;
    QComboBox *displayVol_combo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSlider *transpVol_slider;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *displayFac_cb;
    QCheckBox *displayFacSel_cb;
    QComboBox *displayFac_combo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSlider *transpFac_slider;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *displayEdg_cb;
    QCheckBox *displayEdgSel_cb;
    QComboBox *displayEdg_combo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QSlider *transpEdg_slider;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *displayNod_cb;
    QCheckBox *displayNodSel_cb;
    QComboBox *displayNod_combo;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QSlider *transpNod_slider;
    QWidget *page;
    QTableWidget *collections_table;
    QWidget *horizontalLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *expAddVol_pb;
    QPushButton *expAddFac_pb;
    QPushButton *expAddEdg_pb;
    QPushButton *expAddNod_pb;
    QPushButton *exportCollections_pb;
    QVBoxLayout *verticalLayout_2;
    QPushButton *loadMesh_button;
    QVTKOpenGLWidget *openGLWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *displayCheckBox_bg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1293, 846);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        mouseMode_gb = new QGroupBox(centralwidget);
        mouseMode_gb->setObjectName(QString::fromUtf8("mouseMode_gb"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mouseMode_gb->sizePolicy().hasHeightForWidth());
        mouseMode_gb->setSizePolicy(sizePolicy);
        mouseMode_gb->setMinimumSize(QSize(0, 44));
        layoutWidget = new QWidget(mouseMode_gb);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 291, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        mouseModeOrient_rb = new QRadioButton(layoutWidget);
        mouseModeOrient_rb->setObjectName(QString::fromUtf8("mouseModeOrient_rb"));
        mouseModeOrient_rb->setChecked(true);

        horizontalLayout_7->addWidget(mouseModeOrient_rb);

        mouseModeSel_rb = new QRadioButton(layoutWidget);
        mouseModeSel_rb->setObjectName(QString::fromUtf8("mouseModeSel_rb"));

        horizontalLayout_7->addWidget(mouseModeSel_rb);


        verticalLayout_3->addWidget(mouseMode_gb);

        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        page1->setGeometry(QRect(0, 0, 315, 611));
        layoutWidget1 = new QWidget(page1);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 1, 311, 571));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        selMode_gb = new QGroupBox(layoutWidget1);
        selMode_gb->setObjectName(QString::fromUtf8("selMode_gb"));
        selMode_gb->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selMode_gb->sizePolicy().hasHeightForWidth());
        selMode_gb->setSizePolicy(sizePolicy1);
        selMode_gb->setMinimumSize(QSize(0, 172));
        selMode_gb->setCheckable(false);
        selMode_gb->setChecked(false);
        layoutWidget2 = new QWidget(selMode_gb);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(12, 22, 291, 148));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        add_rb = new QRadioButton(layoutWidget2);
        add_rb->setObjectName(QString::fromUtf8("add_rb"));
        add_rb->setChecked(true);

        verticalLayout_8->addWidget(add_rb);

        replace_rb = new QRadioButton(layoutWidget2);
        replace_rb->setObjectName(QString::fromUtf8("replace_rb"));

        verticalLayout_8->addWidget(replace_rb);

        subtract_rb = new QRadioButton(layoutWidget2);
        subtract_rb->setObjectName(QString::fromUtf8("subtract_rb"));

        verticalLayout_8->addWidget(subtract_rb);

        reselect_rb = new QRadioButton(layoutWidget2);
        reselect_rb->setObjectName(QString::fromUtf8("reselect_rb"));

        verticalLayout_8->addWidget(reselect_rb);


        horizontalLayout_6->addLayout(verticalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        selectAll_pb = new QPushButton(layoutWidget2);
        selectAll_pb->setObjectName(QString::fromUtf8("selectAll_pb"));

        verticalLayout_5->addWidget(selectAll_pb);

        unselectAll_pb = new QPushButton(layoutWidget2);
        unselectAll_pb->setObjectName(QString::fromUtf8("unselectAll_pb"));

        verticalLayout_5->addWidget(unselectAll_pb);

        selectInvert_pb = new QPushButton(layoutWidget2);
        selectInvert_pb->setObjectName(QString::fromUtf8("selectInvert_pb"));

        verticalLayout_5->addWidget(selectInvert_pb);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        showSelection_pb = new QPushButton(layoutWidget2);
        showSelection_pb->setObjectName(QString::fromUtf8("showSelection_pb"));

        verticalLayout_7->addWidget(showSelection_pb);

        hideSelection_pb = new QPushButton(layoutWidget2);
        hideSelection_pb->setObjectName(QString::fromUtf8("hideSelection_pb"));

        verticalLayout_7->addWidget(hideSelection_pb);

        showAll_pb = new QPushButton(layoutWidget2);
        showAll_pb->setObjectName(QString::fromUtf8("showAll_pb"));

        verticalLayout_7->addWidget(showAll_pb);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_6->addWidget(selMode_gb);

        selEntity_gb = new QGroupBox(layoutWidget1);
        selEntity_gb->setObjectName(QString::fromUtf8("selEntity_gb"));
        selEntity_gb->setEnabled(false);
        sizePolicy1.setHeightForWidth(selEntity_gb->sizePolicy().hasHeightForWidth());
        selEntity_gb->setSizePolicy(sizePolicy1);
        selEntity_gb->setMinimumSize(QSize(0, 84));
        gridLayoutWidget = new QWidget(selEntity_gb);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 291, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        selFaces_rb = new QRadioButton(gridLayoutWidget);
        selFaces_rb->setObjectName(QString::fromUtf8("selFaces_rb"));

        gridLayout->addWidget(selFaces_rb, 1, 0, 1, 1);

        selVolumes_rb = new QRadioButton(gridLayoutWidget);
        selVolumes_rb->setObjectName(QString::fromUtf8("selVolumes_rb"));
        selVolumes_rb->setChecked(true);

        gridLayout->addWidget(selVolumes_rb, 0, 0, 1, 1);

        selNodes_rb = new QRadioButton(gridLayoutWidget);
        selNodes_rb->setObjectName(QString::fromUtf8("selNodes_rb"));

        gridLayout->addWidget(selNodes_rb, 1, 1, 1, 1);

        selEdges_rb = new QRadioButton(gridLayoutWidget);
        selEdges_rb->setObjectName(QString::fromUtf8("selEdges_rb"));

        gridLayout->addWidget(selEdges_rb, 0, 1, 1, 1);


        verticalLayout_6->addWidget(selEntity_gb);

        selMethod_gb = new QGroupBox(layoutWidget1);
        selMethod_gb->setObjectName(QString::fromUtf8("selMethod_gb"));
        selMethod_gb->setEnabled(false);
        sizePolicy1.setHeightForWidth(selMethod_gb->sizePolicy().hasHeightForWidth());
        selMethod_gb->setSizePolicy(sizePolicy1);
        selMethod_gb->setMinimumSize(QSize(0, 49));
        layoutWidget3 = new QWidget(selMethod_gb);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 291, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        selMethodBox_rb = new QRadioButton(layoutWidget3);
        selMethodBox_rb->setObjectName(QString::fromUtf8("selMethodBox_rb"));
        selMethodBox_rb->setChecked(true);

        horizontalLayout_8->addWidget(selMethodBox_rb);

        selMethodSlider_rb = new QRadioButton(layoutWidget3);
        selMethodSlider_rb->setObjectName(QString::fromUtf8("selMethodSlider_rb"));

        horizontalLayout_8->addWidget(selMethodSlider_rb);


        verticalLayout_6->addWidget(selMethod_gb);

        selSlide_gb = new QGroupBox(layoutWidget1);
        selSlide_gb->setObjectName(QString::fromUtf8("selSlide_gb"));
        selSlide_gb->setEnabled(false);
        sizePolicy.setHeightForWidth(selSlide_gb->sizePolicy().hasHeightForWidth());
        selSlide_gb->setSizePolicy(sizePolicy);
        selSlide_gb->setMinimumSize(QSize(0, 138));
        selSlide_gb->setCheckable(false);
        layoutWidget4 = new QWidget(selSlide_gb);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 301, 106));
        gridLayout_2 = new QGridLayout(layoutWidget4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(layoutWidget4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        slideSelYm_slider = new QSlider(splitter_3);
        slideSelYm_slider->setObjectName(QString::fromUtf8("slideSelYm_slider"));
        slideSelYm_slider->setMaximum(100);
        slideSelYm_slider->setOrientation(Qt::Horizontal);
        splitter_3->addWidget(slideSelYm_slider);
        slideSelYm_spin = new QDoubleSpinBox(splitter_3);
        slideSelYm_spin->setObjectName(QString::fromUtf8("slideSelYm_spin"));
        splitter_3->addWidget(slideSelYm_spin);

        gridLayout_2->addWidget(splitter_3, 3, 0, 1, 1);

        splitter = new QSplitter(layoutWidget4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        slideSelZm_slider = new QSlider(splitter);
        slideSelZm_slider->setObjectName(QString::fromUtf8("slideSelZm_slider"));
        slideSelZm_slider->setMaximum(100);
        slideSelZm_slider->setOrientation(Qt::Horizontal);
        splitter->addWidget(slideSelZm_slider);
        slideSelZm_spin = new QDoubleSpinBox(splitter);
        slideSelZm_spin->setObjectName(QString::fromUtf8("slideSelZm_spin"));
        splitter->addWidget(slideSelZm_spin);

        gridLayout_2->addWidget(splitter, 4, 0, 1, 1);

        splitter_2 = new QSplitter(layoutWidget4);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        slideSelZp_slider = new QSlider(splitter_2);
        slideSelZp_slider->setObjectName(QString::fromUtf8("slideSelZp_slider"));
        slideSelZp_slider->setMaximum(100);
        slideSelZp_slider->setOrientation(Qt::Horizontal);
        splitter_2->addWidget(slideSelZp_slider);
        slideSelZp_spin = new QDoubleSpinBox(splitter_2);
        slideSelZp_spin->setObjectName(QString::fromUtf8("slideSelZp_spin"));
        splitter_2->addWidget(slideSelZp_spin);

        gridLayout_2->addWidget(splitter_2, 4, 1, 1, 1);

        splitter_6 = new QSplitter(layoutWidget4);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        slideSelXp_slider = new QSlider(splitter_6);
        slideSelXp_slider->setObjectName(QString::fromUtf8("slideSelXp_slider"));
        slideSelXp_slider->setMaximum(100);
        slideSelXp_slider->setOrientation(Qt::Horizontal);
        splitter_6->addWidget(slideSelXp_slider);
        slideSelXp_spin = new QDoubleSpinBox(splitter_6);
        slideSelXp_spin->setObjectName(QString::fromUtf8("slideSelXp_spin"));
        splitter_6->addWidget(slideSelXp_spin);

        gridLayout_2->addWidget(splitter_6, 2, 1, 1, 1);

        splitter_4 = new QSplitter(layoutWidget4);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        slideSelYp_slider = new QSlider(splitter_4);
        slideSelYp_slider->setObjectName(QString::fromUtf8("slideSelYp_slider"));
        slideSelYp_slider->setMaximum(100);
        slideSelYp_slider->setOrientation(Qt::Horizontal);
        splitter_4->addWidget(slideSelYp_slider);
        slideSelYp_spin = new QDoubleSpinBox(splitter_4);
        slideSelYp_spin->setObjectName(QString::fromUtf8("slideSelYp_spin"));
        splitter_4->addWidget(slideSelYp_spin);

        gridLayout_2->addWidget(splitter_4, 3, 1, 1, 1);

        splitter_5 = new QSplitter(layoutWidget4);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        slideSelXm_slider = new QSlider(splitter_5);
        slideSelXm_slider->setObjectName(QString::fromUtf8("slideSelXm_slider"));
        slideSelXm_slider->setMaximum(100);
        slideSelXm_slider->setOrientation(Qt::Horizontal);
        splitter_5->addWidget(slideSelXm_slider);
        slideSelXm_spin = new QDoubleSpinBox(splitter_5);
        slideSelXm_spin->setObjectName(QString::fromUtf8("slideSelXm_spin"));
        splitter_5->addWidget(slideSelXm_spin);

        gridLayout_2->addWidget(splitter_5, 2, 0, 1, 1);

        selBoxBoundary_cb = new QCheckBox(layoutWidget4);
        selBoxBoundary_cb->setObjectName(QString::fromUtf8("selBoxBoundary_cb"));

        gridLayout_2->addWidget(selBoxBoundary_cb, 0, 1, 1, 1);

        selBoxInside_cb = new QCheckBox(layoutWidget4);
        selBoxInside_cb->setObjectName(QString::fromUtf8("selBoxInside_cb"));
        selBoxInside_cb->setChecked(true);

        gridLayout_2->addWidget(selBoxInside_cb, 0, 0, 1, 1);


        verticalLayout_6->addWidget(selSlide_gb);

        toolBox->addItem(page1, QString::fromUtf8("Selection"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayoutWidget_2 = new QWidget(page_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 301, 91));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        viewXp_pb = new QPushButton(gridLayoutWidget_2);
        viewXp_pb->setObjectName(QString::fromUtf8("viewXp_pb"));

        gridLayout_4->addWidget(viewXp_pb, 0, 0, 1, 1);

        viewXm_pb = new QPushButton(gridLayoutWidget_2);
        viewXm_pb->setObjectName(QString::fromUtf8("viewXm_pb"));

        gridLayout_4->addWidget(viewXm_pb, 1, 0, 1, 1);

        viewYp_pb = new QPushButton(gridLayoutWidget_2);
        viewYp_pb->setObjectName(QString::fromUtf8("viewYp_pb"));

        gridLayout_4->addWidget(viewYp_pb, 0, 1, 1, 1);

        viewZp_pb = new QPushButton(gridLayoutWidget_2);
        viewZp_pb->setObjectName(QString::fromUtf8("viewZp_pb"));

        gridLayout_4->addWidget(viewZp_pb, 0, 2, 1, 1);

        viewYm_pb = new QPushButton(gridLayoutWidget_2);
        viewYm_pb->setObjectName(QString::fromUtf8("viewYm_pb"));

        gridLayout_4->addWidget(viewYm_pb, 1, 1, 1, 1);

        viewZm_pb = new QPushButton(gridLayoutWidget_2);
        viewZm_pb->setObjectName(QString::fromUtf8("viewZm_pb"));

        gridLayout_4->addWidget(viewZm_pb, 1, 2, 1, 1);

        viewParallelProjection_cb = new QCheckBox(page_2);
        viewParallelProjection_cb->setObjectName(QString::fromUtf8("viewParallelProjection_cb"));
        viewParallelProjection_cb->setGeometry(QRect(10, 0, 299, 20));
        toolBox->addItem(page_2, QString::fromUtf8("View"));
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        page2->setGeometry(QRect(0, 0, 315, 611));
        display_gb = new QGroupBox(page2);
        display_gb->setObjectName(QString::fromUtf8("display_gb"));
        display_gb->setGeometry(QRect(0, 0, 315, 368));
        sizePolicy.setHeightForWidth(display_gb->sizePolicy().hasHeightForWidth());
        display_gb->setSizePolicy(sizePolicy);
        display_gb->setMinimumSize(QSize(0, 368));
        verticalLayoutWidget = new QWidget(display_gb);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 291, 346));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        displayVol_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg = new QButtonGroup(MainWindow);
        displayCheckBox_bg->setObjectName(QString::fromUtf8("displayCheckBox_bg"));
        displayCheckBox_bg->setExclusive(false);
        displayCheckBox_bg->addButton(displayVol_cb);
        displayVol_cb->setObjectName(QString::fromUtf8("displayVol_cb"));
        displayVol_cb->setChecked(true);

        horizontalLayout_12->addWidget(displayVol_cb);

        displayVolSel_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayVolSel_cb);
        displayVolSel_cb->setObjectName(QString::fromUtf8("displayVolSel_cb"));
        displayVolSel_cb->setChecked(true);

        horizontalLayout_12->addWidget(displayVolSel_cb);


        verticalLayout_4->addLayout(horizontalLayout_12);

        displayVol_combo = new QComboBox(verticalLayoutWidget);
        displayVol_combo->addItem(QString());
        displayVol_combo->addItem(QString());
        displayVol_combo->addItem(QString());
        displayVol_combo->setObjectName(QString::fromUtf8("displayVol_combo"));

        verticalLayout_4->addWidget(displayVol_combo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        transpVol_slider = new QSlider(verticalLayoutWidget);
        transpVol_slider->setObjectName(QString::fromUtf8("transpVol_slider"));
        transpVol_slider->setMaximum(100);
        transpVol_slider->setSingleStep(1);
        transpVol_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(transpVol_slider);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        displayFac_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayFac_cb);
        displayFac_cb->setObjectName(QString::fromUtf8("displayFac_cb"));

        horizontalLayout_13->addWidget(displayFac_cb);

        displayFacSel_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayFacSel_cb);
        displayFacSel_cb->setObjectName(QString::fromUtf8("displayFacSel_cb"));
        displayFacSel_cb->setChecked(true);

        horizontalLayout_13->addWidget(displayFacSel_cb);


        verticalLayout_4->addLayout(horizontalLayout_13);

        displayFac_combo = new QComboBox(verticalLayoutWidget);
        displayFac_combo->addItem(QString());
        displayFac_combo->addItem(QString());
        displayFac_combo->addItem(QString());
        displayFac_combo->setObjectName(QString::fromUtf8("displayFac_combo"));

        verticalLayout_4->addWidget(displayFac_combo);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        transpFac_slider = new QSlider(verticalLayoutWidget);
        transpFac_slider->setObjectName(QString::fromUtf8("transpFac_slider"));
        transpFac_slider->setMaximum(100);
        transpFac_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(transpFac_slider);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        displayEdg_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayEdg_cb);
        displayEdg_cb->setObjectName(QString::fromUtf8("displayEdg_cb"));

        horizontalLayout_14->addWidget(displayEdg_cb);

        displayEdgSel_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayEdgSel_cb);
        displayEdgSel_cb->setObjectName(QString::fromUtf8("displayEdgSel_cb"));
        displayEdgSel_cb->setChecked(true);

        horizontalLayout_14->addWidget(displayEdgSel_cb);


        verticalLayout_4->addLayout(horizontalLayout_14);

        displayEdg_combo = new QComboBox(verticalLayoutWidget);
        displayEdg_combo->addItem(QString());
        displayEdg_combo->addItem(QString());
        displayEdg_combo->setObjectName(QString::fromUtf8("displayEdg_combo"));

        verticalLayout_4->addWidget(displayEdg_combo);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        transpEdg_slider = new QSlider(verticalLayoutWidget);
        transpEdg_slider->setObjectName(QString::fromUtf8("transpEdg_slider"));
        transpEdg_slider->setMaximum(100);
        transpEdg_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(transpEdg_slider);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        displayNod_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayNod_cb);
        displayNod_cb->setObjectName(QString::fromUtf8("displayNod_cb"));

        horizontalLayout_15->addWidget(displayNod_cb);

        displayNodSel_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayNodSel_cb);
        displayNodSel_cb->setObjectName(QString::fromUtf8("displayNodSel_cb"));
        displayNodSel_cb->setChecked(true);

        horizontalLayout_15->addWidget(displayNodSel_cb);


        verticalLayout_4->addLayout(horizontalLayout_15);

        displayNod_combo = new QComboBox(verticalLayoutWidget);
        displayNod_combo->addItem(QString());
        displayNod_combo->addItem(QString());
        displayNod_combo->setObjectName(QString::fromUtf8("displayNod_combo"));

        verticalLayout_4->addWidget(displayNod_combo);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        transpNod_slider = new QSlider(verticalLayoutWidget);
        transpNod_slider->setObjectName(QString::fromUtf8("transpNod_slider"));
        transpNod_slider->setMaximum(100);
        transpNod_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(transpNod_slider);


        verticalLayout_4->addLayout(horizontalLayout_5);

        toolBox->addItem(page2, QString::fromUtf8("Display"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 315, 611));
        collections_table = new QTableWidget(page);
        if (collections_table->columnCount() < 4)
            collections_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        collections_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        collections_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        collections_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        collections_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        collections_table->setObjectName(QString::fromUtf8("collections_table"));
        collections_table->setGeometry(QRect(10, 60, 301, 371));
        collections_table->setFrameShape(QFrame::StyledPanel);
        collections_table->setFrameShadow(QFrame::Sunken);
        collections_table->setMidLineWidth(0);
        collections_table->setRowCount(0);
        collections_table->setColumnCount(4);
        collections_table->horizontalHeader()->setVisible(true);
        collections_table->horizontalHeader()->setCascadingSectionResizes(false);
        collections_table->horizontalHeader()->setMinimumSectionSize(10);
        collections_table->horizontalHeader()->setDefaultSectionSize(100);
        collections_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        collections_table->verticalHeader()->setVisible(true);
        collections_table->verticalHeader()->setDefaultSectionSize(30);
        collections_table->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 301, 56));
        gridLayout_3 = new QGridLayout(horizontalLayoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        expAddVol_pb = new QPushButton(horizontalLayoutWidget);
        expAddVol_pb->setObjectName(QString::fromUtf8("expAddVol_pb"));

        gridLayout_3->addWidget(expAddVol_pb, 0, 0, 1, 1);

        expAddFac_pb = new QPushButton(horizontalLayoutWidget);
        expAddFac_pb->setObjectName(QString::fromUtf8("expAddFac_pb"));

        gridLayout_3->addWidget(expAddFac_pb, 0, 1, 1, 1);

        expAddEdg_pb = new QPushButton(horizontalLayoutWidget);
        expAddEdg_pb->setObjectName(QString::fromUtf8("expAddEdg_pb"));

        gridLayout_3->addWidget(expAddEdg_pb, 1, 0, 1, 1);

        expAddNod_pb = new QPushButton(horizontalLayoutWidget);
        expAddNod_pb->setObjectName(QString::fromUtf8("expAddNod_pb"));

        gridLayout_3->addWidget(expAddNod_pb, 1, 1, 1, 1);

        exportCollections_pb = new QPushButton(page);
        exportCollections_pb->setObjectName(QString::fromUtf8("exportCollections_pb"));
        exportCollections_pb->setGeometry(QRect(10, 440, 161, 24));
        toolBox->addItem(page, QString::fromUtf8("Collections"));

        verticalLayout_3->addWidget(toolBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        loadMesh_button = new QPushButton(centralwidget);
        loadMesh_button->setObjectName(QString::fromUtf8("loadMesh_button"));

        verticalLayout_2->addWidget(loadMesh_button);

        openGLWidget = new QVTKOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        verticalLayout_2->addWidget(openGLWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1293, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mouseMode_gb->setTitle(QCoreApplication::translate("MainWindow", "Mouse mode", nullptr));
        mouseModeOrient_rb->setText(QCoreApplication::translate("MainWindow", "Orientation", nullptr));
        mouseModeSel_rb->setText(QCoreApplication::translate("MainWindow", "Selection", nullptr));
        selMode_gb->setTitle(QCoreApplication::translate("MainWindow", "Selection mode", nullptr));
        add_rb->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        replace_rb->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        subtract_rb->setText(QCoreApplication::translate("MainWindow", "Subtract", nullptr));
        reselect_rb->setText(QCoreApplication::translate("MainWindow", "Reselect", nullptr));
        selectAll_pb->setText(QCoreApplication::translate("MainWindow", "Select all", nullptr));
        unselectAll_pb->setText(QCoreApplication::translate("MainWindow", "Unselect all", nullptr));
        selectInvert_pb->setText(QCoreApplication::translate("MainWindow", "Invert selection", nullptr));
        showSelection_pb->setText(QCoreApplication::translate("MainWindow", "Show Only", nullptr));
        hideSelection_pb->setText(QCoreApplication::translate("MainWindow", "Hide", nullptr));
        showAll_pb->setText(QCoreApplication::translate("MainWindow", "Show All", nullptr));
        selEntity_gb->setTitle(QCoreApplication::translate("MainWindow", "Selection entity", nullptr));
        selFaces_rb->setText(QCoreApplication::translate("MainWindow", "Faces", nullptr));
        selVolumes_rb->setText(QCoreApplication::translate("MainWindow", "Volumes", nullptr));
        selNodes_rb->setText(QCoreApplication::translate("MainWindow", "Nodes", nullptr));
        selEdges_rb->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        selMethod_gb->setTitle(QCoreApplication::translate("MainWindow", "Selection method", nullptr));
        selMethodBox_rb->setText(QCoreApplication::translate("MainWindow", "Box select", nullptr));
        selMethodSlider_rb->setText(QCoreApplication::translate("MainWindow", "Slider select", nullptr));
        selSlide_gb->setTitle(QCoreApplication::translate("MainWindow", "Box selection", nullptr));
        selBoxBoundary_cb->setText(QCoreApplication::translate("MainWindow", "Select boundary cells", nullptr));
        selBoxInside_cb->setText(QCoreApplication::translate("MainWindow", "Select inside", nullptr));
        toolBox->setItemText(toolBox->indexOf(page1), QCoreApplication::translate("MainWindow", "Selection", nullptr));
        viewXp_pb->setText(QCoreApplication::translate("MainWindow", "X+", nullptr));
        viewXm_pb->setText(QCoreApplication::translate("MainWindow", "X-", nullptr));
        viewYp_pb->setText(QCoreApplication::translate("MainWindow", "Y+", nullptr));
        viewZp_pb->setText(QCoreApplication::translate("MainWindow", "Z+", nullptr));
        viewYm_pb->setText(QCoreApplication::translate("MainWindow", "Y-", nullptr));
        viewZm_pb->setText(QCoreApplication::translate("MainWindow", "Z-", nullptr));
        viewParallelProjection_cb->setText(QCoreApplication::translate("MainWindow", "Parallel projection", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "View", nullptr));
        display_gb->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
        displayVol_cb->setText(QCoreApplication::translate("MainWindow", "Volumes", nullptr));
        displayVolSel_cb->setText(QCoreApplication::translate("MainWindow", "Selection", nullptr));
        displayVol_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Surface", nullptr));
        displayVol_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Surface with edges", nullptr));
        displayVol_combo->setItemText(2, QCoreApplication::translate("MainWindow", "Wireframe", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        displayFac_cb->setText(QCoreApplication::translate("MainWindow", "Faces", nullptr));
        displayFacSel_cb->setText(QCoreApplication::translate("MainWindow", "Selection", nullptr));
        displayFac_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Surface", nullptr));
        displayFac_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Surface with edges", nullptr));
        displayFac_combo->setItemText(2, QCoreApplication::translate("MainWindow", "Shrink", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        displayEdg_cb->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        displayEdgSel_cb->setText(QCoreApplication::translate("MainWindow", "Selection", nullptr));
        displayEdg_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Lines", nullptr));
        displayEdg_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Shrink", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        displayNod_cb->setText(QCoreApplication::translate("MainWindow", "Nodes", nullptr));
        displayNodSel_cb->setText(QCoreApplication::translate("MainWindow", "Selection", nullptr));
        displayNod_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Points", nullptr));
        displayNod_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Spheres", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        toolBox->setItemText(toolBox->indexOf(page2), QCoreApplication::translate("MainWindow", "Display", nullptr));
        QTableWidgetItem *___qtablewidgetitem = collections_table->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = collections_table->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Entity", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = collections_table->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Elements", nullptr));
        expAddVol_pb->setText(QCoreApplication::translate("MainWindow", "Add Volumes", nullptr));
        expAddFac_pb->setText(QCoreApplication::translate("MainWindow", "Add Faces", nullptr));
        expAddEdg_pb->setText(QCoreApplication::translate("MainWindow", "Add Edges", nullptr));
        expAddNod_pb->setText(QCoreApplication::translate("MainWindow", "Add Nodes", nullptr));
        exportCollections_pb->setText(QCoreApplication::translate("MainWindow", "Export selected collections", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Collections", nullptr));
        loadMesh_button->setText(QCoreApplication::translate("MainWindow", "Load Mesh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
