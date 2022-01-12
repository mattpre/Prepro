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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
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
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *mouseModeOrient_rb;
    QRadioButton *mouseModeSel_rb;
    QGroupBox *selMode_gb;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *selection_vl;
    QRadioButton *add_rb;
    QRadioButton *replace_rb;
    QRadioButton *subtract_rb;
    QRadioButton *reselect_rb;
    QVBoxLayout *verticalLayout_9;
    QPushButton *selectAll_pb;
    QPushButton *unselectAll_pb;
    QPushButton *selectInvert_pb;
    QVBoxLayout *verticalLayout_8;
    QPushButton *showSelection_pb;
    QPushButton *hideSelection_pb;
    QPushButton *showAll_pb;
    QGroupBox *selEntity_gb;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *selFaces_rb;
    QRadioButton *selVolumes_rb;
    QRadioButton *selEdges_rb;
    QRadioButton *selNodes_rb;
    QGroupBox *selMethod_gb;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *selMethodBox_rb;
    QRadioButton *selMethodSlider_rb;
    QGroupBox *selSlide_gb;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *selBoxInside_cb;
    QCheckBox *selBoxBoundary_cb;
    QHBoxLayout *horizontalLayout_6;
    QSlider *slideSelXm_slider;
    QDoubleSpinBox *slideSelXm_spin;
    QSlider *slideSelXp_slider;
    QDoubleSpinBox *slideSelXp_spin;
    QHBoxLayout *horizontalLayout_8;
    QSlider *slideSelYm_slider;
    QDoubleSpinBox *slideSelYm_spin;
    QSlider *slideSelYp_slider;
    QDoubleSpinBox *slideSelYp_spin;
    QHBoxLayout *horizontalLayout_10;
    QSlider *slideSelZm_slider;
    QDoubleSpinBox *slideSelZm_spin;
    QSlider *slideSelZp_slider;
    QDoubleSpinBox *slideSelZp_spin;
    QGroupBox *display_gb;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *displayVol_cb;
    QCheckBox *displayVolSel_cb;
    QComboBox *displayVol_combo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *transpVol_slider;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *displayFac_cb;
    QCheckBox *displayFacSel_cb;
    QComboBox *displayFac_combo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *transpFac_slider;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *displayEdg_cb;
    QCheckBox *displayEdgSel_cb;
    QComboBox *displayEdg_combo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *transpEdg_slider;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *displayNod_cb;
    QCheckBox *displayNodSel_cb;
    QComboBox *displayNod_combo;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *transpNod_slider;
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
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mouseMode_gb = new QGroupBox(centralwidget);
        mouseMode_gb->setObjectName(QString::fromUtf8("mouseMode_gb"));
        verticalLayoutWidget_4 = new QWidget(mouseMode_gb);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 160, 51));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        mouseModeOrient_rb = new QRadioButton(verticalLayoutWidget_4);
        mouseModeOrient_rb->setObjectName(QString::fromUtf8("mouseModeOrient_rb"));
        mouseModeOrient_rb->setChecked(true);

        verticalLayout_6->addWidget(mouseModeOrient_rb);

        mouseModeSel_rb = new QRadioButton(verticalLayoutWidget_4);
        mouseModeSel_rb->setObjectName(QString::fromUtf8("mouseModeSel_rb"));

        verticalLayout_6->addWidget(mouseModeSel_rb);


        verticalLayout_3->addWidget(mouseMode_gb);

        selMode_gb = new QGroupBox(centralwidget);
        selMode_gb->setObjectName(QString::fromUtf8("selMode_gb"));
        selMode_gb->setEnabled(false);
        selMode_gb->setCheckable(false);
        selMode_gb->setChecked(false);
        horizontalLayoutWidget = new QWidget(selMode_gb);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 291, 102));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        selection_vl = new QVBoxLayout();
        selection_vl->setObjectName(QString::fromUtf8("selection_vl"));
        add_rb = new QRadioButton(horizontalLayoutWidget);
        add_rb->setObjectName(QString::fromUtf8("add_rb"));
        add_rb->setChecked(true);

        selection_vl->addWidget(add_rb);

        replace_rb = new QRadioButton(horizontalLayoutWidget);
        replace_rb->setObjectName(QString::fromUtf8("replace_rb"));

        selection_vl->addWidget(replace_rb);

        subtract_rb = new QRadioButton(horizontalLayoutWidget);
        subtract_rb->setObjectName(QString::fromUtf8("subtract_rb"));

        selection_vl->addWidget(subtract_rb);

        reselect_rb = new QRadioButton(horizontalLayoutWidget);
        reselect_rb->setObjectName(QString::fromUtf8("reselect_rb"));

        selection_vl->addWidget(reselect_rb);


        horizontalLayout_7->addLayout(selection_vl);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        selectAll_pb = new QPushButton(horizontalLayoutWidget);
        selectAll_pb->setObjectName(QString::fromUtf8("selectAll_pb"));

        verticalLayout_9->addWidget(selectAll_pb);

        unselectAll_pb = new QPushButton(horizontalLayoutWidget);
        unselectAll_pb->setObjectName(QString::fromUtf8("unselectAll_pb"));

        verticalLayout_9->addWidget(unselectAll_pb);

        selectInvert_pb = new QPushButton(horizontalLayoutWidget);
        selectInvert_pb->setObjectName(QString::fromUtf8("selectInvert_pb"));

        verticalLayout_9->addWidget(selectInvert_pb);


        horizontalLayout_7->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        showSelection_pb = new QPushButton(horizontalLayoutWidget);
        showSelection_pb->setObjectName(QString::fromUtf8("showSelection_pb"));

        verticalLayout_8->addWidget(showSelection_pb);

        hideSelection_pb = new QPushButton(horizontalLayoutWidget);
        hideSelection_pb->setObjectName(QString::fromUtf8("hideSelection_pb"));

        verticalLayout_8->addWidget(hideSelection_pb);

        showAll_pb = new QPushButton(horizontalLayoutWidget);
        showAll_pb->setObjectName(QString::fromUtf8("showAll_pb"));

        verticalLayout_8->addWidget(showAll_pb);


        horizontalLayout_7->addLayout(verticalLayout_8);


        verticalLayout_3->addWidget(selMode_gb);

        selEntity_gb = new QGroupBox(centralwidget);
        selEntity_gb->setObjectName(QString::fromUtf8("selEntity_gb"));
        selEntity_gb->setEnabled(false);
        gridLayoutWidget = new QWidget(selEntity_gb);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 291, 48));
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

        selEdges_rb = new QRadioButton(gridLayoutWidget);
        selEdges_rb->setObjectName(QString::fromUtf8("selEdges_rb"));

        gridLayout->addWidget(selEdges_rb, 0, 1, 1, 1);

        selNodes_rb = new QRadioButton(gridLayoutWidget);
        selNodes_rb->setObjectName(QString::fromUtf8("selNodes_rb"));

        gridLayout->addWidget(selNodes_rb, 1, 1, 1, 1);


        verticalLayout_3->addWidget(selEntity_gb);

        selMethod_gb = new QGroupBox(centralwidget);
        selMethod_gb->setObjectName(QString::fromUtf8("selMethod_gb"));
        selMethod_gb->setEnabled(false);
        verticalLayoutWidget_5 = new QWidget(selMethod_gb);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 20, 160, 51));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        selMethodBox_rb = new QRadioButton(verticalLayoutWidget_5);
        selMethodBox_rb->setObjectName(QString::fromUtf8("selMethodBox_rb"));
        selMethodBox_rb->setChecked(true);

        verticalLayout_7->addWidget(selMethodBox_rb);

        selMethodSlider_rb = new QRadioButton(verticalLayoutWidget_5);
        selMethodSlider_rb->setObjectName(QString::fromUtf8("selMethodSlider_rb"));

        verticalLayout_7->addWidget(selMethodSlider_rb);


        verticalLayout_3->addWidget(selMethod_gb);

        selSlide_gb = new QGroupBox(centralwidget);
        selSlide_gb->setObjectName(QString::fromUtf8("selSlide_gb"));
        selSlide_gb->setEnabled(false);
        layoutWidget = new QWidget(selSlide_gb);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 301, 146));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        selBoxInside_cb = new QCheckBox(layoutWidget);
        selBoxInside_cb->setObjectName(QString::fromUtf8("selBoxInside_cb"));
        selBoxInside_cb->setChecked(true);

        horizontalLayout_9->addWidget(selBoxInside_cb);

        selBoxBoundary_cb = new QCheckBox(layoutWidget);
        selBoxBoundary_cb->setObjectName(QString::fromUtf8("selBoxBoundary_cb"));

        horizontalLayout_9->addWidget(selBoxBoundary_cb);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        slideSelXm_slider = new QSlider(layoutWidget);
        slideSelXm_slider->setObjectName(QString::fromUtf8("slideSelXm_slider"));
        slideSelXm_slider->setMaximum(100);
        slideSelXm_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(slideSelXm_slider);

        slideSelXm_spin = new QDoubleSpinBox(layoutWidget);
        slideSelXm_spin->setObjectName(QString::fromUtf8("slideSelXm_spin"));

        horizontalLayout_6->addWidget(slideSelXm_spin);

        slideSelXp_slider = new QSlider(layoutWidget);
        slideSelXp_slider->setObjectName(QString::fromUtf8("slideSelXp_slider"));
        slideSelXp_slider->setMaximum(100);
        slideSelXp_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(slideSelXp_slider);

        slideSelXp_spin = new QDoubleSpinBox(layoutWidget);
        slideSelXp_spin->setObjectName(QString::fromUtf8("slideSelXp_spin"));

        horizontalLayout_6->addWidget(slideSelXp_spin);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        slideSelYm_slider = new QSlider(layoutWidget);
        slideSelYm_slider->setObjectName(QString::fromUtf8("slideSelYm_slider"));
        slideSelYm_slider->setMaximum(100);
        slideSelYm_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(slideSelYm_slider);

        slideSelYm_spin = new QDoubleSpinBox(layoutWidget);
        slideSelYm_spin->setObjectName(QString::fromUtf8("slideSelYm_spin"));

        horizontalLayout_8->addWidget(slideSelYm_spin);

        slideSelYp_slider = new QSlider(layoutWidget);
        slideSelYp_slider->setObjectName(QString::fromUtf8("slideSelYp_slider"));
        slideSelYp_slider->setMaximum(100);
        slideSelYp_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(slideSelYp_slider);

        slideSelYp_spin = new QDoubleSpinBox(layoutWidget);
        slideSelYp_spin->setObjectName(QString::fromUtf8("slideSelYp_spin"));

        horizontalLayout_8->addWidget(slideSelYp_spin);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        slideSelZm_slider = new QSlider(layoutWidget);
        slideSelZm_slider->setObjectName(QString::fromUtf8("slideSelZm_slider"));
        slideSelZm_slider->setMaximum(100);
        slideSelZm_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(slideSelZm_slider);

        slideSelZm_spin = new QDoubleSpinBox(layoutWidget);
        slideSelZm_spin->setObjectName(QString::fromUtf8("slideSelZm_spin"));

        horizontalLayout_10->addWidget(slideSelZm_spin);

        slideSelZp_slider = new QSlider(layoutWidget);
        slideSelZp_slider->setObjectName(QString::fromUtf8("slideSelZp_slider"));
        slideSelZp_slider->setMaximum(100);
        slideSelZp_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(slideSelZp_slider);

        slideSelZp_spin = new QDoubleSpinBox(layoutWidget);
        slideSelZp_spin->setObjectName(QString::fromUtf8("slideSelZp_spin"));

        horizontalLayout_10->addWidget(slideSelZp_spin);


        verticalLayout_5->addLayout(horizontalLayout_10);


        verticalLayout_3->addWidget(selSlide_gb);

        display_gb = new QGroupBox(centralwidget);
        display_gb->setObjectName(QString::fromUtf8("display_gb"));
        verticalLayoutWidget = new QWidget(display_gb);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 160, 346));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
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

        transpNod_slider = new QSlider(verticalLayoutWidget);
        transpNod_slider->setObjectName(QString::fromUtf8("transpNod_slider"));
        transpNod_slider->setMaximum(100);
        transpNod_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(transpNod_slider);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(display_gb);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(4, 2);
        verticalLayout_3->setStretch(5, 4);

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
        selEdges_rb->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        selNodes_rb->setText(QCoreApplication::translate("MainWindow", "Nodes", nullptr));
        selMethod_gb->setTitle(QCoreApplication::translate("MainWindow", "Selection method", nullptr));
        selMethodBox_rb->setText(QCoreApplication::translate("MainWindow", "Box select", nullptr));
        selMethodSlider_rb->setText(QCoreApplication::translate("MainWindow", "Slider select", nullptr));
        selSlide_gb->setTitle(QString());
        selBoxInside_cb->setText(QCoreApplication::translate("MainWindow", "Select inside", nullptr));
        selBoxBoundary_cb->setText(QCoreApplication::translate("MainWindow", "Select boundary cells", nullptr));
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
        loadMesh_button->setText(QCoreApplication::translate("MainWindow", "Load Mesh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
