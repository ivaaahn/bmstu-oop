/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "constants.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;

    QVBoxLayout *cabin_layout;
    QVBoxLayout *floors_layout;

    QLabel *cabin_label;
    QLabel *floor_label;

    std::vector<QPushButton *> cabin_buttons;
    std::vector<QPushButton *> floor_buttons;

    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(230, 745);
        MainWindow->setMinimumSize(QSize(230, 745));
        MainWindow->setMaximumSize(QSize(230, 745));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));


        cabin_layout = new QVBoxLayout();
        cabin_layout->setObjectName(QString::fromUtf8("cabin_layout"));
        cabin_label = new QLabel(centralwidget);
        cabin_label->setObjectName(QString::fromUtf8("cabin_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code Retina"));
        font.setPointSize(16);
        cabin_label->setFont(font);
        cabin_label->setAlignment(Qt::AlignCenter);

        cabin_layout->addWidget(cabin_label);

        QFont btn_font;
        btn_font.setFamily(QString::fromUtf8("Chandas"));
        btn_font.setPointSize(14);

        for (int i = 0; i < NUM_OF_FLOORS; ++i)
        {
            auto btn = new QPushButton(centralwidget);
            btn->setMinimumSize(QSize(70, 60));
            btn->setMaximumSize(QSize(70, 60));
            btn->setFont(btn_font);

            cabin_buttons.push_back(btn);
        }

        for (auto it = cabin_buttons.rbegin(); it != cabin_buttons.rend(); ++it)
        {
            cabin_layout->addWidget(*it);
        }

        horizontalLayout->addLayout(cabin_layout);

        floors_layout = new QVBoxLayout();
        floors_layout->setObjectName(QString::fromUtf8("floors_layout"));
        floor_label = new QLabel(centralwidget);
        floor_label->setObjectName(QString::fromUtf8("floor_label"));
        floor_label->setFont(font);
        floor_label->setAlignment(Qt::AlignCenter);

        floors_layout->addWidget(floor_label);

        for (int i = 0; i < NUM_OF_FLOORS; ++i)
        {
            auto btn = new QPushButton(centralwidget);
            btn->setMinimumSize(QSize(70, 60));
            btn->setMaximumSize(QSize(70, 60));
            btn->setFont(btn_font);

            floor_buttons.push_back(btn);
        }

        for (auto it = floor_buttons.rbegin(); it != floor_buttons.rend(); ++it)
        {
            floors_layout->addWidget(*it);
        }

        horizontalLayout->addLayout(floors_layout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "lab_04", nullptr));
        cabin_label->setText(
                QApplication::translate("MainWindow", "\320\232\320\260\320\261\320\270\320\275\320\260", nullptr));
        floor_label->setText(
                QApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266\320\270", nullptr));

        for (int i = 0; i < NUM_OF_FLOORS; ++i)
        {
            floor_buttons[i]->setText(
                    QApplication::translate("MainWindow", QString::number(i + 1).toUtf8().data(), nullptr));
            cabin_buttons[i]->setText(
                    QApplication::translate("MainWindow", QString::number(i + 1).toUtf8().data(), nullptr));
        }

    } // retranslateUi

};

namespace Ui
{
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
