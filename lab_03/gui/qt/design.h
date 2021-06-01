/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGN_H
#define DESIGN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QPushButton *left_btn;
    QPushButton *load_model_btn;
    QPushButton *down_btn;
    QPushButton *right_btn;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QFrame *move_label;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *dy_box;
    QDoubleSpinBox *dz_box;
    QDoubleSpinBox *dx_box;
    QPushButton *move_btn;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *ky_box;
    QDoubleSpinBox *kx_box;
    QLabel *label_6;
    QDoubleSpinBox *kz_box;
    QPushButton *scale_btn;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QDoubleSpinBox *ay_box;
    QDoubleSpinBox *ax_box;
    QDoubleSpinBox *az_box;
    QLabel *label_10;
    QPushButton *rotate_btn;
    QLabel *label_11;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QComboBox *model_choose;
    QPushButton *remove_model_btn;
    QPushButton *clear_scene_btn;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QComboBox *camera_choose;
    QPushButton *remove_camera_btn;
    QPushButton *add_camera_btn;
    QGraphicsView *graphicsView;
    QPushButton *up_btn;
    QPushButton *load_camera_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1345, 863);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(114, 159, 207, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(220, 222, 218, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(93, 94, 91, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(124, 126, 121, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush6(QColor(186, 189, 182, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        left_btn = new QPushButton(centralwidget);
        left_btn->setObjectName(QString::fromUtf8("left_btn"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        left_btn->setFont(font);

        gridLayout_3->addWidget(left_btn, 2, 0, 1, 1);

        load_model_btn = new QPushButton(centralwidget);
        load_model_btn->setObjectName(QString::fromUtf8("load_model_btn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(10);
        load_model_btn->setFont(font1);

        gridLayout_3->addWidget(load_model_btn, 2, 2, 1, 2);

        down_btn = new QPushButton(centralwidget);
        down_btn->setObjectName(QString::fromUtf8("down_btn"));
        down_btn->setFont(font);

        gridLayout_3->addWidget(down_btn, 2, 6, 1, 1);

        right_btn = new QPushButton(centralwidget);
        right_btn->setObjectName(QString::fromUtf8("right_btn"));
        right_btn->setFont(font);

        gridLayout_3->addWidget(right_btn, 2, 7, 1, 1);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFont(font);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        move_label = new QFrame(frame_4);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move_label->sizePolicy().hasHeightForWidth());
        move_label->setSizePolicy(sizePolicy1);
        move_label->setFont(font);
        move_label->setFrameShape(QFrame::StyledPanel);
        move_label->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(move_label);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(move_label);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        label_3->setFont(font2);

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(move_label);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(move_label);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        dy_box = new QDoubleSpinBox(move_label);
        dy_box->setObjectName(QString::fromUtf8("dy_box"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(11);
        dy_box->setFont(font3);
        dy_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        dy_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dy_box->setMinimum(-10000000000000000000000.000000000000000);
        dy_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_5->addWidget(dy_box, 1, 1, 1, 1);

        dz_box = new QDoubleSpinBox(move_label);
        dz_box->setObjectName(QString::fromUtf8("dz_box"));
        dz_box->setFont(font3);
        dz_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        dz_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dz_box->setMinimum(-99999999999999991611392.000000000000000);
        dz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(dz_box, 2, 1, 1, 1);

        dx_box = new QDoubleSpinBox(move_label);
        dx_box->setObjectName(QString::fromUtf8("dx_box"));
        dx_box->setFont(font3);
        dx_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        dx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dx_box->setMinimum(-10000000000000000.000000000000000);
        dx_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(dx_box, 0, 1, 1, 1);

        move_btn = new QPushButton(move_label);
        move_btn->setObjectName(QString::fromUtf8("move_btn"));
        move_btn->setFont(font);

        gridLayout_5->addWidget(move_btn, 3, 0, 1, 2);


        verticalLayout->addWidget(move_label);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        ky_box = new QDoubleSpinBox(frame_2);
        ky_box->setObjectName(QString::fromUtf8("ky_box"));
        ky_box->setFont(font3);
        ky_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ky_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ky_box->setMinimum(0.000000000000000);
        ky_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_6->addWidget(ky_box, 1, 1, 1, 1);

        kx_box = new QDoubleSpinBox(frame_2);
        kx_box->setObjectName(QString::fromUtf8("kx_box"));
        kx_box->setFont(font3);
        kx_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        kx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kx_box->setMinimum(0.000000000000000);
        kx_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_6->addWidget(kx_box, 0, 1, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        kz_box = new QDoubleSpinBox(frame_2);
        kz_box->setObjectName(QString::fromUtf8("kz_box"));
        kz_box->setFont(font3);
        kz_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        kz_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kz_box->setMinimum(0.000000000000000);
        kz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_6->addWidget(kz_box, 2, 1, 1, 1);

        scale_btn = new QPushButton(frame_2);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        scale_btn->setFont(font);

        gridLayout_6->addWidget(scale_btn, 3, 0, 1, 2);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFont(font);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        gridLayout_7->addWidget(label_12, 1, 0, 1, 1);

        ay_box = new QDoubleSpinBox(frame_3);
        ay_box->setObjectName(QString::fromUtf8("ay_box"));
        ay_box->setFont(font3);
        ay_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ay_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ay_box->setMinimum(-10000000000000000000000.000000000000000);
        ay_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_7->addWidget(ay_box, 1, 1, 1, 1);

        ax_box = new QDoubleSpinBox(frame_3);
        ax_box->setObjectName(QString::fromUtf8("ax_box"));
        ax_box->setFont(font3);
        ax_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ax_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ax_box->setMinimum(-10000000000000000.000000000000000);
        ax_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(ax_box, 0, 1, 1, 1);

        az_box = new QDoubleSpinBox(frame_3);
        az_box->setObjectName(QString::fromUtf8("az_box"));
        az_box->setFont(font3);
        az_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        az_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        az_box->setMinimum(-99999999999999991611392.000000000000000);
        az_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(az_box, 2, 1, 1, 1);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        gridLayout_7->addWidget(label_10, 2, 0, 1, 1);

        rotate_btn = new QPushButton(frame_3);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        rotate_btn->setFont(font);

        gridLayout_7->addWidget(rotate_btn, 3, 0, 1, 2);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);


        verticalLayout->addWidget(frame_3);

        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        model_choose = new QComboBox(frame);
        model_choose->setObjectName(QString::fromUtf8("model_choose"));
        model_choose->setFont(font);

        verticalLayout_2->addWidget(model_choose);

        remove_model_btn = new QPushButton(frame);
        remove_model_btn->setObjectName(QString::fromUtf8("remove_model_btn"));
        remove_model_btn->setFont(font);

        verticalLayout_2->addWidget(remove_model_btn);

        clear_scene_btn = new QPushButton(frame);
        clear_scene_btn->setObjectName(QString::fromUtf8("clear_scene_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clear_scene_btn->sizePolicy().hasHeightForWidth());
        clear_scene_btn->setSizePolicy(sizePolicy2);
        clear_scene_btn->setFont(font);

        verticalLayout_2->addWidget(clear_scene_btn);


        verticalLayout->addWidget(frame);

        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFont(font);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        camera_choose = new QComboBox(frame_5);
        camera_choose->setObjectName(QString::fromUtf8("camera_choose"));
        camera_choose->setFont(font);

        verticalLayout_3->addWidget(camera_choose);

        remove_camera_btn = new QPushButton(frame_5);
        remove_camera_btn->setObjectName(QString::fromUtf8("remove_camera_btn"));
        remove_camera_btn->setFont(font);

        verticalLayout_3->addWidget(remove_camera_btn);


        verticalLayout->addWidget(frame_5);


        gridLayout_3->addWidget(frame_4, 0, 8, 1, 1, Qt::AlignTop);

        add_camera_btn = new QPushButton(centralwidget);
        add_camera_btn->setObjectName(QString::fromUtf8("add_camera_btn"));
        add_camera_btn->setFont(font1);

        gridLayout_3->addWidget(add_camera_btn, 2, 5, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFont(font);

        gridLayout_3->addWidget(graphicsView, 0, 0, 1, 8);

        up_btn = new QPushButton(centralwidget);
        up_btn->setObjectName(QString::fromUtf8("up_btn"));
        up_btn->setFont(font);

        gridLayout_3->addWidget(up_btn, 2, 1, 1, 1);

        load_camera_btn = new QPushButton(centralwidget);
        load_camera_btn->setObjectName(QString::fromUtf8("load_camera_btn"));
        load_camera_btn->setFont(font1);

        gridLayout_3->addWidget(load_camera_btn, 2, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(graphicsView, dx_box);
        QWidget::setTabOrder(dx_box, dy_box);
        QWidget::setTabOrder(dy_box, dz_box);
        QWidget::setTabOrder(dz_box, move_btn);
        QWidget::setTabOrder(move_btn, kx_box);
        QWidget::setTabOrder(kx_box, ky_box);
        QWidget::setTabOrder(ky_box, kz_box);
        QWidget::setTabOrder(kz_box, scale_btn);
        QWidget::setTabOrder(scale_btn, ax_box);
        QWidget::setTabOrder(ax_box, ay_box);
        QWidget::setTabOrder(ay_box, az_box);
        QWidget::setTabOrder(az_box, rotate_btn);
        QWidget::setTabOrder(rotate_btn, model_choose);
        QWidget::setTabOrder(model_choose, remove_model_btn);
        QWidget::setTabOrder(remove_model_btn, camera_choose);
        QWidget::setTabOrder(camera_choose, remove_camera_btn);
        QWidget::setTabOrder(remove_camera_btn, left_btn);
        QWidget::setTabOrder(left_btn, up_btn);
        QWidget::setTabOrder(up_btn, load_model_btn);
        QWidget::setTabOrder(load_model_btn, add_camera_btn);
        QWidget::setTabOrder(add_camera_btn, down_btn);
        QWidget::setTabOrder(down_btn, right_btn);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab 03", nullptr));
        left_btn->setText(QApplication::translate("MainWindow", "\342\227\200", nullptr));
        load_model_btn->setText(QApplication::translate("MainWindow", "Load model", nullptr));
        down_btn->setText(QApplication::translate("MainWindow", "\342\254\207", nullptr));
        right_btn->setText(QApplication::translate("MainWindow", "\342\226\266", nullptr));
        label_3->setText(QApplication::translate("MainWindow", " dz", nullptr));
        label_2->setText(QApplication::translate("MainWindow", " dy", nullptr));
        label->setText(QApplication::translate("MainWindow", " dx", nullptr));
        move_btn->setText(QApplication::translate("MainWindow", "Move", nullptr));
        label_5->setText(QApplication::translate("MainWindow", " ky", nullptr));
        label_4->setText(QApplication::translate("MainWindow", " kx", nullptr));
        label_6->setText(QApplication::translate("MainWindow", " kz", nullptr));
        scale_btn->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "ay", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "az", nullptr));
        rotate_btn->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "ax", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Model", nullptr));
        remove_model_btn->setText(QApplication::translate("MainWindow", "Remove", nullptr));
        clear_scene_btn->setText(QApplication::translate("MainWindow", "Clear scene", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Camera", nullptr));
        remove_camera_btn->setText(QApplication::translate("MainWindow", "Remove", nullptr));
        add_camera_btn->setText(QApplication::translate("MainWindow", "Add Camera", nullptr));
        up_btn->setText(QApplication::translate("MainWindow", "\342\254\206", nullptr));
        load_camera_btn->setText(QApplication::translate("MainWindow", "Load camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGN_H
