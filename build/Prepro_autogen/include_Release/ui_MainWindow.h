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
    QGroupBox *selection_gb;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *selection_vl;
    QRadioButton *add_rb;
    QRadioButton *replace_rb;
    QRadioButton *subtract_rb;
    QRadioButton *reselect_rb;
    QGroupBox *display_gb;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *displayVol_cb;
    QComboBox *displayVol_combo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *transpVol_slider;
    QCheckBox *displayFac_cb;
    QComboBox *displayFac_combo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *transpFac_slider;
    QCheckBox *displayEdg_cb;
    QComboBox *displayEdg_combo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *transpEdg_slider;
    QCheckBox *displayNod_cb;
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
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        selection_gb = new QGroupBox(centralwidget);
        selection_gb->setObjectName(QString::fromUtf8("selection_gb"));
        selection_gb->setCheckable(true);
        selection_gb->setChecked(false);
        verticalLayoutWidget_3 = new QWidget(selection_gb);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 160, 100));
        selection_vl = new QVBoxLayout(verticalLayoutWidget_3);
        selection_vl->setObjectName(QString::fromUtf8("selection_vl"));
        selection_vl->setContentsMargins(0, 0, 0, 0);
        add_rb = new QRadioButton(verticalLayoutWidget_3);
        add_rb->setObjectName(QString::fromUtf8("add_rb"));
        add_rb->setChecked(true);

        selection_vl->addWidget(add_rb);

        replace_rb = new QRadioButton(verticalLayoutWidget_3);
        replace_rb->setObjectName(QString::fromUtf8("replace_rb"));

        selection_vl->addWidget(replace_rb);

        subtract_rb = new QRadioButton(verticalLayoutWidget_3);
        subtract_rb->setObjectName(QString::fromUtf8("subtract_rb"));

        selection_vl->addWidget(subtract_rb);

        reselect_rb = new QRadioButton(verticalLayoutWidget_3);
        reselect_rb->setObjectName(QString::fromUtf8("reselect_rb"));

        selection_vl->addWidget(reselect_rb);


        verticalLayout_3->addWidget(selection_gb);

        display_gb = new QGroupBox(centralwidget);
        display_gb->setObjectName(QString::fromUtf8("display_gb"));
        verticalLayoutWidget = new QWidget(display_gb);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 160, 342));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        displayVol_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg = new QButtonGroup(MainWindow);
        displayCheckBox_bg->setObjectName(QString::fromUtf8("displayCheckBox_bg"));
        displayCheckBox_bg->setExclusive(false);
        displayCheckBox_bg->addButton(displayVol_cb);
        displayVol_cb->setObjectName(QString::fromUtf8("displayVol_cb"));
        displayVol_cb->setChecked(true);

        verticalLayout_4->addWidget(displayVol_cb);

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

        displayFac_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayFac_cb);
        displayFac_cb->setObjectName(QString::fromUtf8("displayFac_cb"));

        verticalLayout_4->addWidget(displayFac_cb);

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

        displayEdg_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayEdg_cb);
        displayEdg_cb->setObjectName(QString::fromUtf8("displayEdg_cb"));

        verticalLayout_4->addWidget(displayEdg_cb);

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

        displayNod_cb = new QCheckBox(verticalLayoutWidget);
        displayCheckBox_bg->addButton(displayNod_cb);
        displayNod_cb->setObjectName(QString::fromUtf8("displayNod_cb"));

        verticalLayout_4->addWidget(displayNod_cb);

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

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 5);

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
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        selection_gb->setTitle(QCoreApplication::translate("MainWindow", "Selection", nullptr));
        add_rb->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        replace_rb->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        subtract_rb->setText(QCoreApplication::translate("MainWindow", "Subtract", nullptr));
        reselect_rb->setText(QCoreApplication::translate("MainWindow", "Reselect", nullptr));
        display_gb->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
        displayVol_cb->setText(QCoreApplication::translate("MainWindow", "Volumes", nullptr));
        displayVol_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Surface", nullptr));
        displayVol_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Surface with edges", nullptr));
        displayVol_combo->setItemText(2, QCoreApplication::translate("MainWindow", "Wireframe", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        displayFac_cb->setText(QCoreApplication::translate("MainWindow", "Faces", nullptr));
        displayFac_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Surface", nullptr));
        displayFac_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Surface with edges", nullptr));
        displayFac_combo->setItemText(2, QCoreApplication::translate("MainWindow", "Shrink", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        displayEdg_cb->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        displayEdg_combo->setItemText(0, QCoreApplication::translate("MainWindow", "Lines", nullptr));
        displayEdg_combo->setItemText(1, QCoreApplication::translate("MainWindow", "Shrink", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Transparency", nullptr));
        displayNod_cb->setText(QCoreApplication::translate("MainWindow", "Nodes", nullptr));
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
