/********************************************************************************
** Form generated from reading UI file 'sumgenerator.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMGENERATOR_H
#define UI_SUMGENERATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SumGenerator
{
public:
    QAction *actionContext;
    QAction *actionAbou;
    QAction *actionRestart;
    QAction *actionExit;
    QAction *actionRating;
    QAction *actionCSS;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblScore;
    QLineEdit *lineEditAnswer;
    QPushButton *btnSubmit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblSolve;
    QLabel *lblExpression;
    QPushButton *btnExit;
    QLabel *lblPercent;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QMenu *menuFile;
    QMenu *menuCredits;

    void setupUi(QMainWindow *SumGenerator)
    {
        if (SumGenerator->objectName().isEmpty())
            SumGenerator->setObjectName("SumGenerator");
        SumGenerator->resize(347, 148);
        SumGenerator->setStyleSheet(QString::fromUtf8(""));
        actionContext = new QAction(SumGenerator);
        actionContext->setObjectName("actionContext");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/info.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionContext->setIcon(icon);
        actionAbou = new QAction(SumGenerator);
        actionAbou->setObjectName("actionAbou");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbou->setIcon(icon1);
        actionRestart = new QAction(SumGenerator);
        actionRestart->setObjectName("actionRestart");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/restart.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon2);
        actionExit = new QAction(SumGenerator);
        actionExit->setObjectName("actionExit");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionRating = new QAction(SumGenerator);
        actionRating->setObjectName("actionRating");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/rating.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRating->setIcon(icon4);
        actionCSS = new QAction(SumGenerator);
        actionCSS->setObjectName("actionCSS");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/credit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCSS->setIcon(icon5);
        centralwidget = new QWidget(SumGenerator);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lblScore = new QLabel(centralwidget);
        lblScore->setObjectName("lblScore");

        horizontalLayout_3->addWidget(lblScore);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        lineEditAnswer = new QLineEdit(centralwidget);
        lineEditAnswer->setObjectName("lineEditAnswer");

        gridLayout->addWidget(lineEditAnswer, 1, 0, 1, 1);

        btnSubmit = new QPushButton(centralwidget);
        btnSubmit->setObjectName("btnSubmit");

        gridLayout->addWidget(btnSubmit, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblSolve = new QLabel(centralwidget);
        lblSolve->setObjectName("lblSolve");

        horizontalLayout_2->addWidget(lblSolve);

        lblExpression = new QLabel(centralwidget);
        lblExpression->setObjectName("lblExpression");

        horizontalLayout_2->addWidget(lblExpression);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        btnExit = new QPushButton(centralwidget);
        btnExit->setObjectName("btnExit");

        gridLayout->addWidget(btnExit, 2, 0, 1, 2);

        lblPercent = new QLabel(centralwidget);
        lblPercent->setObjectName("lblPercent");

        gridLayout->addWidget(lblPercent, 3, 1, 1, 1);

        SumGenerator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SumGenerator);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 347, 22));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuCredits = new QMenu(menubar);
        menuCredits->setObjectName("menuCredits");
        SumGenerator->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuCredits->menuAction());
        menuHelp->addAction(actionContext);
        menuHelp->addAction(actionAbou);
        menuFile->addAction(actionRating);
        menuFile->addAction(actionRestart);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuCredits->addAction(actionCSS);

        retranslateUi(SumGenerator);

        QMetaObject::connectSlotsByName(SumGenerator);
    } // setupUi

    void retranslateUi(QMainWindow *SumGenerator)
    {
        SumGenerator->setWindowTitle(QCoreApplication::translate("SumGenerator", "SumGenerator", nullptr));
        actionContext->setText(QCoreApplication::translate("SumGenerator", "Context Help", nullptr));
        actionAbou->setText(QCoreApplication::translate("SumGenerator", "About", nullptr));
        actionRestart->setText(QCoreApplication::translate("SumGenerator", "Restart", nullptr));
        actionExit->setText(QCoreApplication::translate("SumGenerator", "Exit", nullptr));
        actionRating->setText(QCoreApplication::translate("SumGenerator", "Rating", nullptr));
        actionCSS->setText(QCoreApplication::translate("SumGenerator", "Styling", nullptr));
        lblScore->setText(QCoreApplication::translate("SumGenerator", "Score: 0/0", nullptr));
        btnSubmit->setText(QCoreApplication::translate("SumGenerator", "Submit", nullptr));
        lblSolve->setText(QCoreApplication::translate("SumGenerator", "Solve the following sum: ", nullptr));
        lblExpression->setText(QCoreApplication::translate("SumGenerator", "TextLabel", nullptr));
        btnExit->setText(QCoreApplication::translate("SumGenerator", "Exit", nullptr));
        lblPercent->setText(QString());
        menuHelp->setTitle(QCoreApplication::translate("SumGenerator", "Help", nullptr));
        menuFile->setTitle(QCoreApplication::translate("SumGenerator", "Game", nullptr));
        menuCredits->setTitle(QCoreApplication::translate("SumGenerator", "Credits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SumGenerator: public Ui_SumGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMGENERATOR_H
