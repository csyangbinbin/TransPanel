/********************************************************************************
** Form generated from reading UI file 'transpanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSPANEL_H
#define UI_TRANSPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransPanelClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_monwnd;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_si_devtime;
    QLabel *label_si_icaoaddr;
    QLabel *label_si_ID;
    QLabel *label_si_satcount;
    QLabel *label_si_lon;
    QLabel *label_si_lat;
    QLabel *label_si_alt;
    QLabel *label_si_revcount;
    QLabel *label_si_tmp;
    QLabel *label_si_hpa;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_zi_frp;
    QLabel *label_zi_loc;
    QLabel *label_zi_tmp;
    QLabel *label_zi_hpa;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_jh_emit;
    QLabel *label_jh_emit_test;
    QLabel *label_jh_nor_emit;
    QLabel *label_jh_upload;
    QLabel *label_jh_rcv_upload;
    QLabel *label_jh_out_loc;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_21;
    QLineEdit *lineEdit_icaoaddr;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_22;
    QLineEdit *lineEdit_trID;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_23;
    QLineEdit *lineEdit_ply;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_serial_set;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_serialport;
    QPushButton *pushButton_com_open;
    QGroupBox *groupBox_control_panel;
    QGridLayout *gridLayout;
    QPushButton *pushButton_emit;
    QPushButton *pushButton_emit_test;
    QPushButton *pushButton_connect_test;
    QPushButton *pushButton_emit_mode;
    QPushButton *pushButton_save_cfg;
    QPushButton *pushButton_rcv_upload;
    QPushButton *pushButton_help;
    QPushButton *pushButton_rcv_upload_mode;
    QPushButton *pushButton_about;
    QPushButton *pushButton_gps_source;
    QPushButton *pushButton_exit;
    QGroupBox *groupBox_info;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_info_show;
    QLabel *label_msg_info;

    void setupUi(QDialog *TransPanelClass)
    {
        if (TransPanelClass->objectName().isEmpty())
            TransPanelClass->setObjectName(QString::fromUtf8("TransPanelClass"));
        TransPanelClass->resize(912, 532);
        verticalLayout_3 = new QVBoxLayout(TransPanelClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_monwnd = new QGroupBox(TransPanelClass);
        groupBox_monwnd->setObjectName(QString::fromUtf8("groupBox_monwnd"));
        groupBox_monwnd->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(groupBox_monwnd);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget = new QTabWidget(groupBox_monwnd);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(129, 129, 129);\n"
"color:white ;\n"
"font: 75 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_8 = new QVBoxLayout(groupBox_5);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_si_devtime = new QLabel(groupBox_5);
        label_si_devtime->setObjectName(QString::fromUtf8("label_si_devtime"));

        verticalLayout_8->addWidget(label_si_devtime);

        label_si_icaoaddr = new QLabel(groupBox_5);
        label_si_icaoaddr->setObjectName(QString::fromUtf8("label_si_icaoaddr"));

        verticalLayout_8->addWidget(label_si_icaoaddr);

        label_si_ID = new QLabel(groupBox_5);
        label_si_ID->setObjectName(QString::fromUtf8("label_si_ID"));

        verticalLayout_8->addWidget(label_si_ID);

        label_si_satcount = new QLabel(groupBox_5);
        label_si_satcount->setObjectName(QString::fromUtf8("label_si_satcount"));

        verticalLayout_8->addWidget(label_si_satcount);

        label_si_lon = new QLabel(groupBox_5);
        label_si_lon->setObjectName(QString::fromUtf8("label_si_lon"));

        verticalLayout_8->addWidget(label_si_lon);

        label_si_lat = new QLabel(groupBox_5);
        label_si_lat->setObjectName(QString::fromUtf8("label_si_lat"));

        verticalLayout_8->addWidget(label_si_lat);

        label_si_alt = new QLabel(groupBox_5);
        label_si_alt->setObjectName(QString::fromUtf8("label_si_alt"));

        verticalLayout_8->addWidget(label_si_alt);

        label_si_revcount = new QLabel(groupBox_5);
        label_si_revcount->setObjectName(QString::fromUtf8("label_si_revcount"));

        verticalLayout_8->addWidget(label_si_revcount);

        label_si_tmp = new QLabel(groupBox_5);
        label_si_tmp->setObjectName(QString::fromUtf8("label_si_tmp"));

        verticalLayout_8->addWidget(label_si_tmp);

        label_si_hpa = new QLabel(groupBox_5);
        label_si_hpa->setObjectName(QString::fromUtf8("label_si_hpa"));

        verticalLayout_8->addWidget(label_si_hpa);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);


        horizontalLayout_3->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_zi_frp = new QLabel(groupBox_6);
        label_zi_frp->setObjectName(QString::fromUtf8("label_zi_frp"));

        verticalLayout_9->addWidget(label_zi_frp);

        label_zi_loc = new QLabel(groupBox_6);
        label_zi_loc->setObjectName(QString::fromUtf8("label_zi_loc"));

        verticalLayout_9->addWidget(label_zi_loc);

        label_zi_tmp = new QLabel(groupBox_6);
        label_zi_tmp->setObjectName(QString::fromUtf8("label_zi_tmp"));

        verticalLayout_9->addWidget(label_zi_tmp);

        label_zi_hpa = new QLabel(groupBox_6);
        label_zi_hpa->setObjectName(QString::fromUtf8("label_zi_hpa"));

        verticalLayout_9->addWidget(label_zi_hpa);

        verticalSpacer_3 = new QSpacerItem(20, 224, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);


        horizontalLayout_3->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_10 = new QVBoxLayout(groupBox_7);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_jh_emit = new QLabel(groupBox_7);
        label_jh_emit->setObjectName(QString::fromUtf8("label_jh_emit"));

        verticalLayout_10->addWidget(label_jh_emit);

        label_jh_emit_test = new QLabel(groupBox_7);
        label_jh_emit_test->setObjectName(QString::fromUtf8("label_jh_emit_test"));

        verticalLayout_10->addWidget(label_jh_emit_test);

        label_jh_nor_emit = new QLabel(groupBox_7);
        label_jh_nor_emit->setObjectName(QString::fromUtf8("label_jh_nor_emit"));

        verticalLayout_10->addWidget(label_jh_nor_emit);

        label_jh_upload = new QLabel(groupBox_7);
        label_jh_upload->setObjectName(QString::fromUtf8("label_jh_upload"));

        verticalLayout_10->addWidget(label_jh_upload);

        label_jh_rcv_upload = new QLabel(groupBox_7);
        label_jh_rcv_upload->setObjectName(QString::fromUtf8("label_jh_rcv_upload"));

        verticalLayout_10->addWidget(label_jh_rcv_upload);

        label_jh_out_loc = new QLabel(groupBox_7);
        label_jh_out_loc->setObjectName(QString::fromUtf8("label_jh_out_loc"));

        verticalLayout_10->addWidget(label_jh_out_loc);

        verticalSpacer_4 = new QSpacerItem(20, 172, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_4);


        horizontalLayout_3->addWidget(groupBox_7);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_8 = new QHBoxLayout(tab_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_6 = new QVBoxLayout(groupBox_8);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_5->addWidget(label_21);

        lineEdit_icaoaddr = new QLineEdit(groupBox_8);
        lineEdit_icaoaddr->setObjectName(QString::fromUtf8("lineEdit_icaoaddr"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_icaoaddr->sizePolicy().hasHeightForWidth());
        lineEdit_icaoaddr->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_icaoaddr);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_22 = new QLabel(groupBox_8);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_6->addWidget(label_22);

        lineEdit_trID = new QLineEdit(groupBox_8);
        lineEdit_trID->setObjectName(QString::fromUtf8("lineEdit_trID"));
        sizePolicy.setHeightForWidth(lineEdit_trID->sizePolicy().hasHeightForWidth());
        lineEdit_trID->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_trID);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_9->addWidget(label_23);

        lineEdit_ply = new QLineEdit(groupBox_8);
        lineEdit_ply->setObjectName(QString::fromUtf8("lineEdit_ply"));
        sizePolicy.setHeightForWidth(lineEdit_ply->sizePolicy().hasHeightForWidth());
        lineEdit_ply->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(lineEdit_ply);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_7->addWidget(groupBox_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        horizontalLayout_7->addLayout(verticalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);


        horizontalLayout->addWidget(groupBox_monwnd);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_serial_set = new QGroupBox(TransPanelClass);
        groupBox_serial_set->setObjectName(QString::fromUtf8("groupBox_serial_set"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_serial_set->sizePolicy().hasHeightForWidth());
        groupBox_serial_set->setSizePolicy(sizePolicy1);
        groupBox_serial_set->setMinimumSize(QSize(0, 80));
        verticalLayout_4 = new QVBoxLayout(groupBox_serial_set);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        comboBox_serialport = new QComboBox(groupBox_serial_set);
        comboBox_serialport->setObjectName(QString::fromUtf8("comboBox_serialport"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_serialport->sizePolicy().hasHeightForWidth());
        comboBox_serialport->setSizePolicy(sizePolicy2);
        comboBox_serialport->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(comboBox_serialport);

        pushButton_com_open = new QPushButton(groupBox_serial_set);
        pushButton_com_open->setObjectName(QString::fromUtf8("pushButton_com_open"));
        sizePolicy.setHeightForWidth(pushButton_com_open->sizePolicy().hasHeightForWidth());
        pushButton_com_open->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_com_open);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox_serial_set);

        groupBox_control_panel = new QGroupBox(TransPanelClass);
        groupBox_control_panel->setObjectName(QString::fromUtf8("groupBox_control_panel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_control_panel->sizePolicy().hasHeightForWidth());
        groupBox_control_panel->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(groupBox_control_panel);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_emit = new QPushButton(groupBox_control_panel);
        pushButton_emit->setObjectName(QString::fromUtf8("pushButton_emit"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_emit->sizePolicy().hasHeightForWidth());
        pushButton_emit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_emit, 0, 0, 1, 1);

        pushButton_emit_test = new QPushButton(groupBox_control_panel);
        pushButton_emit_test->setObjectName(QString::fromUtf8("pushButton_emit_test"));
        sizePolicy4.setHeightForWidth(pushButton_emit_test->sizePolicy().hasHeightForWidth());
        pushButton_emit_test->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_emit_test, 1, 0, 1, 1);

        pushButton_connect_test = new QPushButton(groupBox_control_panel);
        pushButton_connect_test->setObjectName(QString::fromUtf8("pushButton_connect_test"));
        sizePolicy4.setHeightForWidth(pushButton_connect_test->sizePolicy().hasHeightForWidth());
        pushButton_connect_test->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_connect_test, 1, 1, 1, 1);

        pushButton_emit_mode = new QPushButton(groupBox_control_panel);
        pushButton_emit_mode->setObjectName(QString::fromUtf8("pushButton_emit_mode"));
        sizePolicy4.setHeightForWidth(pushButton_emit_mode->sizePolicy().hasHeightForWidth());
        pushButton_emit_mode->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_emit_mode, 2, 0, 1, 1);

        pushButton_save_cfg = new QPushButton(groupBox_control_panel);
        pushButton_save_cfg->setObjectName(QString::fromUtf8("pushButton_save_cfg"));
        sizePolicy4.setHeightForWidth(pushButton_save_cfg->sizePolicy().hasHeightForWidth());
        pushButton_save_cfg->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_save_cfg, 2, 1, 1, 1);

        pushButton_rcv_upload = new QPushButton(groupBox_control_panel);
        pushButton_rcv_upload->setObjectName(QString::fromUtf8("pushButton_rcv_upload"));
        sizePolicy4.setHeightForWidth(pushButton_rcv_upload->sizePolicy().hasHeightForWidth());
        pushButton_rcv_upload->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_rcv_upload, 3, 0, 1, 1);

        pushButton_help = new QPushButton(groupBox_control_panel);
        pushButton_help->setObjectName(QString::fromUtf8("pushButton_help"));
        sizePolicy4.setHeightForWidth(pushButton_help->sizePolicy().hasHeightForWidth());
        pushButton_help->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_help, 3, 1, 1, 1);

        pushButton_rcv_upload_mode = new QPushButton(groupBox_control_panel);
        pushButton_rcv_upload_mode->setObjectName(QString::fromUtf8("pushButton_rcv_upload_mode"));
        sizePolicy4.setHeightForWidth(pushButton_rcv_upload_mode->sizePolicy().hasHeightForWidth());
        pushButton_rcv_upload_mode->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_rcv_upload_mode, 4, 0, 1, 1);

        pushButton_about = new QPushButton(groupBox_control_panel);
        pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));
        sizePolicy4.setHeightForWidth(pushButton_about->sizePolicy().hasHeightForWidth());
        pushButton_about->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_about, 4, 1, 1, 1);

        pushButton_gps_source = new QPushButton(groupBox_control_panel);
        pushButton_gps_source->setObjectName(QString::fromUtf8("pushButton_gps_source"));
        sizePolicy4.setHeightForWidth(pushButton_gps_source->sizePolicy().hasHeightForWidth());
        pushButton_gps_source->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_gps_source, 5, 0, 1, 1);

        pushButton_exit = new QPushButton(groupBox_control_panel);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        sizePolicy4.setHeightForWidth(pushButton_exit->sizePolicy().hasHeightForWidth());
        pushButton_exit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_exit, 5, 1, 1, 1);


        verticalLayout->addWidget(groupBox_control_panel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        groupBox_info = new QGroupBox(TransPanelClass);
        groupBox_info->setObjectName(QString::fromUtf8("groupBox_info"));
        sizePolicy2.setHeightForWidth(groupBox_info->sizePolicy().hasHeightForWidth());
        groupBox_info->setSizePolicy(sizePolicy2);
        groupBox_info->setMinimumSize(QSize(0, 50));
        groupBox_info->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(groupBox_info);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_info_show = new QLabel(groupBox_info);
        label_info_show->setObjectName(QString::fromUtf8("label_info_show"));

        horizontalLayout_4->addWidget(label_info_show);

        label_msg_info = new QLabel(groupBox_info);
        label_msg_info->setObjectName(QString::fromUtf8("label_msg_info"));

        horizontalLayout_4->addWidget(label_msg_info);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 2);

        verticalLayout_2->addWidget(groupBox_info);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(TransPanelClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TransPanelClass);
    } // setupUi

    void retranslateUi(QDialog *TransPanelClass)
    {
        TransPanelClass->setWindowTitle(QApplication::translate("TransPanelClass", "ADS-B Trans Monitor V0.1 (\346\265\213\350\257\225\347\211\210)", 0, QApplication::UnicodeUTF8));
        groupBox_monwnd->setTitle(QApplication::translate("TransPanelClass", "\347\233\221\350\247\206\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("TransPanelClass", "\347\263\273\347\273\237\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_si_devtime->setText(QApplication::translate("TransPanelClass", "\350\256\276\345\244\207\346\227\266\351\227\264:\346\234\252\347\237\245", 0, QApplication::UnicodeUTF8));
        label_si_icaoaddr->setText(QApplication::translate("TransPanelClass", "ICAO\345\234\260\345\235\200:---", 0, QApplication::UnicodeUTF8));
        label_si_ID->setText(QApplication::translate("TransPanelClass", "ID\345\217\267\347\240\201:---", 0, QApplication::UnicodeUTF8));
        label_si_satcount->setText(QApplication::translate("TransPanelClass", "\346\220\234\346\230\237\344\270\252\346\225\260:---", 0, QApplication::UnicodeUTF8));
        label_si_lon->setText(QApplication::translate("TransPanelClass", "\347\273\217\345\272\246:---", 0, QApplication::UnicodeUTF8));
        label_si_lat->setText(QApplication::translate("TransPanelClass", "\347\272\254\345\272\246:---", 0, QApplication::UnicodeUTF8));
        label_si_alt->setText(QApplication::translate("TransPanelClass", "\351\253\230\345\272\246:---", 0, QApplication::UnicodeUTF8));
        label_si_revcount->setText(QApplication::translate("TransPanelClass", "\346\216\245\346\224\266\351\207\217:---", 0, QApplication::UnicodeUTF8));
        label_si_tmp->setText(QApplication::translate("TransPanelClass", "\346\270\251\345\272\246:---", 0, QApplication::UnicodeUTF8));
        label_si_hpa->setText(QApplication::translate("TransPanelClass", "\346\260\224\345\216\213:---", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("TransPanelClass", "\347\273\204\344\273\266\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_zi_frp->setText(QApplication::translate("TransPanelClass", "\351\242\221\347\216\207\346\272\220\345\267\262\351\224\201\345\256\232", 0, QApplication::UnicodeUTF8));
        label_zi_loc->setText(QApplication::translate("TransPanelClass", "\345\256\232\344\275\215\347\263\273\347\273\237\345\274\202\345\270\270", 0, QApplication::UnicodeUTF8));
        label_zi_tmp->setText(QApplication::translate("TransPanelClass", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\250\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_zi_hpa->setText(QApplication::translate("TransPanelClass", "\346\260\224\345\216\213\344\274\240\346\204\237\345\231\250\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("TransPanelClass", "\344\272\244\344\272\222\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_jh_emit->setText(QApplication::translate("TransPanelClass", "\345\217\221\345\260\204\345\267\262\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        label_jh_emit_test->setText(QApplication::translate("TransPanelClass", "\345\217\221\345\260\204\346\265\213\350\257\225\345\220\257\345\212\250", 0, QApplication::UnicodeUTF8));
        label_jh_nor_emit->setText(QApplication::translate("TransPanelClass", "\346\255\243\345\270\270\345\217\221\345\260\204\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_jh_upload->setText(QApplication::translate("TransPanelClass", "\346\216\245\346\224\266\344\270\212\344\274\240\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        label_jh_rcv_upload->setText(QApplication::translate("TransPanelClass", "\346\216\245\346\224\266\345\216\237\345\247\213\344\270\212\344\274\240", 0, QApplication::UnicodeUTF8));
        label_jh_out_loc->setText(QApplication::translate("TransPanelClass", "\344\275\277\347\224\250\345\244\226\351\203\250\345\256\232\344\275\215\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TransPanelClass", "\347\212\266\346\200\201\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("TransPanelClass", "\345\217\202\346\225\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("TransPanelClass", "ICAO\345\217\267\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("TransPanelClass", "\346\240\207\350\257\206\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("TransPanelClass", "\351\242\221\347\216\207\346\272\220(MHz):", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TransPanelClass", "\345\217\202\346\225\260\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox_serial_set->setTitle(QApplication::translate("TransPanelClass", "\344\270\262\345\217\243\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_com_open->setText(QApplication::translate("TransPanelClass", "\346\211\223\345\274\200\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        groupBox_control_panel->setTitle(QApplication::translate("TransPanelClass", "\346\216\247\345\210\266\351\235\242\346\235\277", 0, QApplication::UnicodeUTF8));
        pushButton_emit->setText(QApplication::translate("TransPanelClass", "\345\274\200\345\220\257\345\217\221\345\260\204", 0, QApplication::UnicodeUTF8));
        pushButton_emit_test->setText(QApplication::translate("TransPanelClass", "\345\217\221\345\260\204\346\265\213\350\257\225\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        pushButton_connect_test->setText(QApplication::translate("TransPanelClass", "\350\277\236\346\216\245\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
        pushButton_emit_mode->setText(QApplication::translate("TransPanelClass", "\345\220\214\346\255\245\345\217\221\345\260\204\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        pushButton_save_cfg->setText(QApplication::translate("TransPanelClass", "\344\277\235\345\255\230\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_rcv_upload->setText(QApplication::translate("TransPanelClass", "\346\216\245\346\224\266\344\270\212\344\274\240\345\274\200\345\220\257", 0, QApplication::UnicodeUTF8));
        pushButton_help->setText(QApplication::translate("TransPanelClass", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        pushButton_rcv_upload_mode->setText(QApplication::translate("TransPanelClass", "\346\216\245\346\224\266\350\247\243\347\240\201\344\270\212\344\274\240", 0, QApplication::UnicodeUTF8));
        pushButton_about->setText(QApplication::translate("TransPanelClass", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        pushButton_gps_source->setText(QApplication::translate("TransPanelClass", "\344\275\277\347\224\250\345\206\205\351\203\250\345\256\232\344\275\215", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QApplication::translate("TransPanelClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        groupBox_info->setTitle(QApplication::translate("TransPanelClass", "\344\277\241\346\201\257\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        label_info_show->setText(QApplication::translate("TransPanelClass", "---", 0, QApplication::UnicodeUTF8));
        label_msg_info->setText(QApplication::translate("TransPanelClass", "<html><head/><body><p>| \346\212\245\346\226\207\347\212\266\346\200\201&gt; \351\224\231\350\257\257\346\212\245\346\226\207:---  \345\205\250\351\203\250\346\212\245\346\226\207:---</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TransPanelClass: public Ui_TransPanelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSPANEL_H
