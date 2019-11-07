/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_interface;
    QLineEdit *lineEdit_BSSID;
    QLineEdit *lineEdit_CH;
    QPushButton *pushButton_scan;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QToolButton *toolButton_directory_slecter;
    QComboBox *comboBox_directory_path;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton_handshake_select;
    QComboBox *comboBox_handshake_path;
    QPushButton *pushButton_crack;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *textEdit_AP;
    QTextEdit *textEdit_STATION;
    QTextEdit *textEdit_handshake;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(920, 696);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_interface = new QLineEdit(centralWidget);
        lineEdit_interface->setObjectName(QStringLiteral("lineEdit_interface"));

        horizontalLayout_3->addWidget(lineEdit_interface);

        lineEdit_BSSID = new QLineEdit(centralWidget);
        lineEdit_BSSID->setObjectName(QStringLiteral("lineEdit_BSSID"));

        horizontalLayout_3->addWidget(lineEdit_BSSID);

        lineEdit_CH = new QLineEdit(centralWidget);
        lineEdit_CH->setObjectName(QStringLiteral("lineEdit_CH"));

        horizontalLayout_3->addWidget(lineEdit_CH);

        pushButton_scan = new QPushButton(centralWidget);
        pushButton_scan->setObjectName(QStringLiteral("pushButton_scan"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_scan->sizePolicy().hasHeightForWidth());
        pushButton_scan->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_scan);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(40);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(89, 27));
        label_2->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(label_2);

        toolButton_directory_slecter = new QToolButton(centralWidget);
        toolButton_directory_slecter->setObjectName(QStringLiteral("toolButton_directory_slecter"));

        horizontalLayout_2->addWidget(toolButton_directory_slecter);

        comboBox_directory_path = new QComboBox(centralWidget);
        comboBox_directory_path->setObjectName(QStringLiteral("comboBox_directory_path"));

        horizontalLayout_2->addWidget(comboBox_directory_path);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(40);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(89, 27));

        horizontalLayout->addWidget(label);

        toolButton_handshake_select = new QToolButton(centralWidget);
        toolButton_handshake_select->setObjectName(QStringLiteral("toolButton_handshake_select"));

        horizontalLayout->addWidget(toolButton_handshake_select);

        comboBox_handshake_path = new QComboBox(centralWidget);
        comboBox_handshake_path->setObjectName(QStringLiteral("comboBox_handshake_path"));

        horizontalLayout->addWidget(comboBox_handshake_path);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        pushButton_crack = new QPushButton(centralWidget);
        pushButton_crack->setObjectName(QStringLiteral("pushButton_crack"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_crack->sizePolicy().hasHeightForWidth());
        pushButton_crack->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(pushButton_crack);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        textEdit_AP = new QTextEdit(centralWidget);
        textEdit_AP->setObjectName(QStringLiteral("textEdit_AP"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_AP->sizePolicy().hasHeightForWidth());
        textEdit_AP->setSizePolicy(sizePolicy4);

        horizontalLayout_5->addWidget(textEdit_AP);

        textEdit_STATION = new QTextEdit(centralWidget);
        textEdit_STATION->setObjectName(QStringLiteral("textEdit_STATION"));
        sizePolicy4.setHeightForWidth(textEdit_STATION->sizePolicy().hasHeightForWidth());
        textEdit_STATION->setSizePolicy(sizePolicy4);
        textEdit_STATION->setPlaceholderText(QStringLiteral(""));

        horizontalLayout_5->addWidget(textEdit_STATION);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_5);

        textEdit_handshake = new QTextEdit(centralWidget);
        textEdit_handshake->setObjectName(QStringLiteral("textEdit_handshake"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(textEdit_handshake->sizePolicy().hasHeightForWidth());
        textEdit_handshake->setSizePolicy(sizePolicy5);
        textEdit_handshake->setMaximumSize(QSize(16777215, 200));

        verticalLayout_2->addWidget(textEdit_handshake);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 920, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lineEdit_interface->setText(QString());
        lineEdit_interface->setPlaceholderText(QString());
        pushButton_scan->setText(QApplication::translate("MainWindow", "scan", 0));
        label_2->setText(QApplication::translate("MainWindow", "DICTIONARY", 0));
        toolButton_directory_slecter->setText(QApplication::translate("MainWindow", "...", 0));
        label->setText(QApplication::translate("MainWindow", "HANDSHAKE", 0));
        toolButton_handshake_select->setText(QApplication::translate("MainWindow", "...", 0));
        pushButton_crack->setText(QApplication::translate("MainWindow", "crack", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
