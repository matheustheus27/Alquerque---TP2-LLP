/********************************************************************************
** Form generated from reading UI file 'Alquerque.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALQUERQUE_H
#define UI_ALQUERQUE_H

#include <Hole.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Alquerque
{
public:
    QAction *actionNovo;
    QAction *actionSair;
    QAction *actionAjuda;
    QWidget *centralwidget;
    Hole *hole22;
    Hole *hole12;
    Hole *hole10;
    Hole *hole00;
    Hole *hole24;
    Hole *hole41;
    Hole *hole13;
    Hole *hole04;
    Hole *hole32;
    Hole *hole44;
    Hole *hole43;
    Hole *hole31;
    Hole *hole42;
    Hole *hole40;
    Hole *hole14;
    Hole *hole33;
    Hole *hole11;
    Hole *hole02;
    Hole *hole30;
    Hole *hole01;
    Hole *hole21;
    Hole *hole20;
    Hole *hole23;
    Hole *hole34;
    Hole *hole03;
    QPushButton *restart;
    QPushButton *help;
    QPushButton *exit;
    QPushButton *playerTurn;
    QPushButton *playerTurnEnd;
    QMenuBar *menubar;
    QMenu *menuJogo;
    QMenu *menuSobre;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Alquerque)
    {
        if (Alquerque->objectName().isEmpty())
            Alquerque->setObjectName(QString::fromUtf8("Alquerque"));
        Alquerque->resize(500, 600);
        Alquerque->setMinimumSize(QSize(500, 600));
        Alquerque->setMaximumSize(QSize(500, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8(":/GameFont")});
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        Alquerque->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon"), QSize(), QIcon::Normal, QIcon::Off);
        Alquerque->setWindowIcon(icon);
        Alquerque->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: rgb(34, 34, 34);\n"
"	font: 9pt \":/GameFont\";\n"
"}"));
        Alquerque->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionNovo = new QAction(Alquerque);
        actionNovo->setObjectName(QString::fromUtf8("actionNovo"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/InRestart"), QSize(), QIcon::Normal, QIcon::Off);
        actionNovo->setIcon(icon1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("04b")});
        actionNovo->setFont(font1);
        actionSair = new QAction(Alquerque);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/InExit"), QSize(), QIcon::Normal, QIcon::Off);
        actionSair->setIcon(icon2);
        actionSair->setFont(font1);
        actionAjuda = new QAction(Alquerque);
        actionAjuda->setObjectName(QString::fromUtf8("actionAjuda"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/InHelp"), QSize(), QIcon::Normal, QIcon::Off);
        actionAjuda->setIcon(icon3);
        actionAjuda->setFont(font1);
        centralwidget = new QWidget(Alquerque);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(500, 600));
        centralwidget->setMaximumSize(QSize(500, 600));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background: url(':/GameBoard');\n"
"	font: 9pt \":/GameFont\";\n"
"}"));
        hole22 = new Hole(centralwidget);
        hole22->setObjectName(QString::fromUtf8("hole22"));
        hole22->setGeometry(QRect(215, 265, 70, 70));
        hole22->setMinimumSize(QSize(70, 70));
        hole22->setMaximumSize(QSize(70, 70));
        hole22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Empty"), QSize(), QIcon::Normal, QIcon::Off);
        hole22->setIcon(icon4);
        hole22->setIconSize(QSize(50, 50));
        hole22->setFlat(true);
        hole22->setProperty("row", QVariant(2));
        hole22->setProperty("col", QVariant(2));
        hole12 = new Hole(centralwidget);
        hole12->setObjectName(QString::fromUtf8("hole12"));
        hole12->setGeometry(QRect(218, 170, 70, 70));
        hole12->setMinimumSize(QSize(70, 70));
        hole12->setMaximumSize(QSize(70, 70));
        hole12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole12->setIcon(icon4);
        hole12->setIconSize(QSize(50, 50));
        hole12->setFlat(true);
        hole12->setProperty("row", QVariant(1));
        hole12->setProperty("col", QVariant(2));
        hole10 = new Hole(centralwidget);
        hole10->setObjectName(QString::fromUtf8("hole10"));
        hole10->setGeometry(QRect(26, 170, 70, 70));
        hole10->setMinimumSize(QSize(70, 70));
        hole10->setMaximumSize(QSize(70, 70));
        hole10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole10->setIcon(icon4);
        hole10->setIconSize(QSize(50, 50));
        hole10->setFlat(true);
        hole10->setProperty("row", QVariant(1));
        hole10->setProperty("col", QVariant(0));
        hole00 = new Hole(centralwidget);
        hole00->setObjectName(QString::fromUtf8("hole00"));
        hole00->setGeometry(QRect(24, 70, 70, 70));
        hole00->setMinimumSize(QSize(70, 70));
        hole00->setMaximumSize(QSize(70, 70));
        hole00->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole00->setIcon(icon4);
        hole00->setIconSize(QSize(50, 50));
        hole00->setFlat(true);
        hole00->setProperty("row", QVariant(0));
        hole00->setProperty("col", QVariant(0));
        hole24 = new Hole(centralwidget);
        hole24->setObjectName(QString::fromUtf8("hole24"));
        hole24->setGeometry(QRect(407, 265, 70, 70));
        hole24->setMinimumSize(QSize(70, 70));
        hole24->setMaximumSize(QSize(70, 70));
        hole24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole24->setIcon(icon4);
        hole24->setIconSize(QSize(50, 50));
        hole24->setFlat(true);
        hole24->setProperty("row", QVariant(2));
        hole24->setProperty("col", QVariant(4));
        hole41 = new Hole(centralwidget);
        hole41->setObjectName(QString::fromUtf8("hole41"));
        hole41->setGeometry(QRect(122, 450, 70, 70));
        hole41->setMinimumSize(QSize(70, 70));
        hole41->setMaximumSize(QSize(70, 70));
        hole41->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole41->setIcon(icon4);
        hole41->setIconSize(QSize(50, 50));
        hole41->setFlat(true);
        hole41->setProperty("row", QVariant(4));
        hole41->setProperty("col", QVariant(1));
        hole13 = new Hole(centralwidget);
        hole13->setObjectName(QString::fromUtf8("hole13"));
        hole13->setGeometry(QRect(314, 170, 70, 70));
        hole13->setMinimumSize(QSize(70, 70));
        hole13->setMaximumSize(QSize(70, 70));
        hole13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole13->setIcon(icon4);
        hole13->setIconSize(QSize(50, 50));
        hole13->setFlat(true);
        hole13->setProperty("row", QVariant(1));
        hole13->setProperty("col", QVariant(3));
        hole04 = new Hole(centralwidget);
        hole04->setObjectName(QString::fromUtf8("hole04"));
        hole04->setGeometry(QRect(408, 70, 70, 70));
        hole04->setMinimumSize(QSize(70, 70));
        hole04->setMaximumSize(QSize(70, 70));
        hole04->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole04->setIcon(icon4);
        hole04->setIconSize(QSize(50, 50));
        hole04->setFlat(true);
        hole04->setProperty("row", QVariant(0));
        hole04->setProperty("col", QVariant(4));
        hole32 = new Hole(centralwidget);
        hole32->setObjectName(QString::fromUtf8("hole32"));
        hole32->setGeometry(QRect(218, 360, 70, 70));
        hole32->setMinimumSize(QSize(70, 70));
        hole32->setMaximumSize(QSize(70, 70));
        hole32->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole32->setIcon(icon4);
        hole32->setIconSize(QSize(50, 50));
        hole32->setFlat(true);
        hole32->setProperty("row", QVariant(3));
        hole32->setProperty("col", QVariant(2));
        hole44 = new Hole(centralwidget);
        hole44->setObjectName(QString::fromUtf8("hole44"));
        hole44->setGeometry(QRect(410, 450, 70, 70));
        hole44->setMinimumSize(QSize(70, 70));
        hole44->setMaximumSize(QSize(70, 70));
        hole44->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole44->setIcon(icon4);
        hole44->setIconSize(QSize(50, 50));
        hole44->setFlat(true);
        hole44->setProperty("row", QVariant(4));
        hole44->setProperty("col", QVariant(4));
        hole43 = new Hole(centralwidget);
        hole43->setObjectName(QString::fromUtf8("hole43"));
        hole43->setGeometry(QRect(314, 450, 70, 70));
        hole43->setMinimumSize(QSize(70, 70));
        hole43->setMaximumSize(QSize(70, 70));
        hole43->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole43->setIcon(icon4);
        hole43->setIconSize(QSize(50, 50));
        hole43->setFlat(true);
        hole43->setProperty("row", QVariant(4));
        hole43->setProperty("col", QVariant(3));
        hole31 = new Hole(centralwidget);
        hole31->setObjectName(QString::fromUtf8("hole31"));
        hole31->setGeometry(QRect(122, 360, 70, 70));
        hole31->setMinimumSize(QSize(70, 70));
        hole31->setMaximumSize(QSize(70, 70));
        hole31->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole31->setIcon(icon4);
        hole31->setIconSize(QSize(50, 50));
        hole31->setFlat(true);
        hole31->setProperty("row", QVariant(3));
        hole31->setProperty("col", QVariant(1));
        hole42 = new Hole(centralwidget);
        hole42->setObjectName(QString::fromUtf8("hole42"));
        hole42->setGeometry(QRect(218, 450, 70, 70));
        hole42->setMinimumSize(QSize(70, 70));
        hole42->setMaximumSize(QSize(70, 70));
        hole42->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole42->setIcon(icon4);
        hole42->setIconSize(QSize(50, 50));
        hole42->setFlat(true);
        hole42->setProperty("row", QVariant(4));
        hole42->setProperty("col", QVariant(2));
        hole40 = new Hole(centralwidget);
        hole40->setObjectName(QString::fromUtf8("hole40"));
        hole40->setGeometry(QRect(26, 450, 70, 70));
        hole40->setMinimumSize(QSize(70, 70));
        hole40->setMaximumSize(QSize(70, 70));
        hole40->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole40->setIcon(icon4);
        hole40->setIconSize(QSize(50, 50));
        hole40->setFlat(true);
        hole40->setProperty("row", QVariant(4));
        hole40->setProperty("col", QVariant(0));
        hole14 = new Hole(centralwidget);
        hole14->setObjectName(QString::fromUtf8("hole14"));
        hole14->setGeometry(QRect(410, 170, 70, 70));
        hole14->setMinimumSize(QSize(70, 70));
        hole14->setMaximumSize(QSize(70, 70));
        hole14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole14->setIcon(icon4);
        hole14->setIconSize(QSize(50, 50));
        hole14->setFlat(true);
        hole14->setProperty("row", QVariant(1));
        hole14->setProperty("col", QVariant(4));
        hole33 = new Hole(centralwidget);
        hole33->setObjectName(QString::fromUtf8("hole33"));
        hole33->setGeometry(QRect(314, 360, 70, 70));
        hole33->setMinimumSize(QSize(70, 70));
        hole33->setMaximumSize(QSize(70, 70));
        hole33->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole33->setIcon(icon4);
        hole33->setIconSize(QSize(50, 50));
        hole33->setFlat(true);
        hole33->setProperty("row", QVariant(3));
        hole33->setProperty("col", QVariant(3));
        hole11 = new Hole(centralwidget);
        hole11->setObjectName(QString::fromUtf8("hole11"));
        hole11->setGeometry(QRect(122, 170, 70, 70));
        hole11->setMinimumSize(QSize(70, 70));
        hole11->setMaximumSize(QSize(70, 70));
        hole11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole11->setIcon(icon4);
        hole11->setIconSize(QSize(50, 50));
        hole11->setFlat(true);
        hole11->setProperty("row", QVariant(1));
        hole11->setProperty("col", QVariant(1));
        hole02 = new Hole(centralwidget);
        hole02->setObjectName(QString::fromUtf8("hole02"));
        hole02->setGeometry(QRect(216, 70, 70, 70));
        hole02->setMinimumSize(QSize(70, 70));
        hole02->setMaximumSize(QSize(70, 70));
        hole02->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole02->setIcon(icon4);
        hole02->setIconSize(QSize(50, 50));
        hole02->setFlat(true);
        hole02->setProperty("row", QVariant(0));
        hole02->setProperty("col", QVariant(2));
        hole30 = new Hole(centralwidget);
        hole30->setObjectName(QString::fromUtf8("hole30"));
        hole30->setGeometry(QRect(26, 360, 70, 70));
        hole30->setMinimumSize(QSize(70, 70));
        hole30->setMaximumSize(QSize(70, 70));
        hole30->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole30->setIcon(icon4);
        hole30->setIconSize(QSize(50, 50));
        hole30->setFlat(true);
        hole30->setProperty("row", QVariant(3));
        hole30->setProperty("col", QVariant(0));
        hole01 = new Hole(centralwidget);
        hole01->setObjectName(QString::fromUtf8("hole01"));
        hole01->setGeometry(QRect(120, 70, 70, 70));
        hole01->setMinimumSize(QSize(70, 70));
        hole01->setMaximumSize(QSize(70, 70));
        hole01->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole01->setIcon(icon4);
        hole01->setIconSize(QSize(50, 50));
        hole01->setFlat(true);
        hole01->setProperty("row", QVariant(0));
        hole01->setProperty("col", QVariant(1));
        hole21 = new Hole(centralwidget);
        hole21->setObjectName(QString::fromUtf8("hole21"));
        hole21->setGeometry(QRect(119, 265, 70, 70));
        hole21->setMinimumSize(QSize(70, 70));
        hole21->setMaximumSize(QSize(70, 70));
        hole21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole21->setIcon(icon4);
        hole21->setIconSize(QSize(50, 50));
        hole21->setFlat(true);
        hole21->setProperty("row", QVariant(2));
        hole21->setProperty("col", QVariant(1));
        hole20 = new Hole(centralwidget);
        hole20->setObjectName(QString::fromUtf8("hole20"));
        hole20->setGeometry(QRect(23, 265, 70, 70));
        hole20->setMinimumSize(QSize(70, 70));
        hole20->setMaximumSize(QSize(70, 70));
        hole20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole20->setIcon(icon4);
        hole20->setIconSize(QSize(50, 50));
        hole20->setFlat(true);
        hole20->setProperty("row", QVariant(2));
        hole20->setProperty("col", QVariant(0));
        hole23 = new Hole(centralwidget);
        hole23->setObjectName(QString::fromUtf8("hole23"));
        hole23->setGeometry(QRect(311, 265, 70, 70));
        hole23->setMinimumSize(QSize(70, 70));
        hole23->setMaximumSize(QSize(70, 70));
        hole23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole23->setIcon(icon4);
        hole23->setIconSize(QSize(50, 50));
        hole23->setFlat(true);
        hole23->setProperty("row", QVariant(2));
        hole23->setProperty("col", QVariant(3));
        hole34 = new Hole(centralwidget);
        hole34->setObjectName(QString::fromUtf8("hole34"));
        hole34->setGeometry(QRect(410, 360, 70, 70));
        hole34->setMinimumSize(QSize(70, 70));
        hole34->setMaximumSize(QSize(70, 70));
        hole34->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole34->setIcon(icon4);
        hole34->setIconSize(QSize(50, 50));
        hole34->setFlat(true);
        hole34->setProperty("row", QVariant(3));
        hole34->setProperty("col", QVariant(4));
        hole03 = new Hole(centralwidget);
        hole03->setObjectName(QString::fromUtf8("hole03"));
        hole03->setGeometry(QRect(312, 70, 70, 70));
        hole03->setMinimumSize(QSize(70, 70));
        hole03->setMaximumSize(QSize(70, 70));
        hole03->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        hole03->setIcon(icon4);
        hole03->setIconSize(QSize(50, 50));
        hole03->setFlat(true);
        hole03->setProperty("row", QVariant(0));
        hole03->setProperty("col", QVariant(3));
        restart = new QPushButton(centralwidget);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setGeometry(QRect(370, 10, 30, 30));
        restart->setMinimumSize(QSize(30, 30));
        restart->setMaximumSize(QSize(30, 30));
        restart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        restart->setIcon(icon1);
        restart->setIconSize(QSize(20, 20));
        restart->setFlat(true);
        help = new QPushButton(centralwidget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(400, 10, 30, 30));
        help->setMinimumSize(QSize(30, 30));
        help->setMaximumSize(QSize(30, 30));
        help->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        help->setIcon(icon3);
        help->setIconSize(QSize(20, 20));
        help->setFlat(true);
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(430, 10, 30, 30));
        exit->setMinimumSize(QSize(30, 30));
        exit->setMaximumSize(QSize(30, 30));
        exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        exit->setIcon(icon2);
        exit->setIconSize(QSize(20, 20));
        exit->setFlat(true);
        playerTurn = new QPushButton(centralwidget);
        playerTurn->setObjectName(QString::fromUtf8("playerTurn"));
        playerTurn->setGeometry(QRect(0, 530, 511, 41));
        playerTurn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/RedTurn"), QSize(), QIcon::Normal, QIcon::Off);
        playerTurn->setIcon(icon5);
        playerTurn->setIconSize(QSize(400, 80));
        playerTurn->setFlat(true);
        playerTurnEnd = new QPushButton(centralwidget);
        playerTurnEnd->setObjectName(QString::fromUtf8("playerTurnEnd"));
        playerTurnEnd->setGeometry(QRect(180, 30, 141, 31));
        playerTurnEnd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/RedEnd"), QSize(), QIcon::Normal, QIcon::Off);
        playerTurnEnd->setIcon(icon6);
        playerTurnEnd->setIconSize(QSize(100, 100));
        playerTurnEnd->setFlat(true);
        Alquerque->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Alquerque);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 17));
        menubar->setFont(font1);
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"	background-color: rgb(89, 89, 89);\n"
"}"));
        menuJogo = new QMenu(menubar);
        menuJogo->setObjectName(QString::fromUtf8("menuJogo"));
        menuJogo->setFont(font1);
        menuJogo->setStyleSheet(QString::fromUtf8("QMenu{\n"
"	background-color: rgb(89, 89, 89);\n"
"}"));
        menuSobre = new QMenu(menubar);
        menuSobre->setObjectName(QString::fromUtf8("menuSobre"));
        menuSobre->setFont(font1);
        menuSobre->setStyleSheet(QString::fromUtf8("QMenu{\n"
"	background-color: rgb(89, 89, 89);\n"
"}"));
        Alquerque->setMenuBar(menubar);
        statusbar = new QStatusBar(Alquerque);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Alquerque->setStatusBar(statusbar);

        menubar->addAction(menuJogo->menuAction());
        menubar->addAction(menuSobre->menuAction());
        menuJogo->addAction(actionNovo);
        menuJogo->addAction(actionSair);
        menuSobre->addAction(actionAjuda);

        retranslateUi(Alquerque);

        QMetaObject::connectSlotsByName(Alquerque);
    } // setupUi

    void retranslateUi(QMainWindow *Alquerque)
    {
        Alquerque->setWindowTitle(QCoreApplication::translate("Alquerque", "Alquerque", nullptr));
        actionNovo->setText(QCoreApplication::translate("Alquerque", "Reiniciar", nullptr));
        actionSair->setText(QCoreApplication::translate("Alquerque", "Sair", nullptr));
        actionAjuda->setText(QCoreApplication::translate("Alquerque", "Ajuda", nullptr));
        restart->setText(QString());
        help->setText(QString());
        exit->setText(QString());
        menuJogo->setTitle(QCoreApplication::translate("Alquerque", "Jogo", nullptr));
        menuSobre->setTitle(QCoreApplication::translate("Alquerque", "Sobre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Alquerque: public Ui_Alquerque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALQUERQUE_H
