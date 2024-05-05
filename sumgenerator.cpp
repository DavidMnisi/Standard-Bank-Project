#include "sumgenerator.h"
#include "ui_sumgenerator.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QMessageBox>

SumGenerator::SumGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SumGenerator), score(0), totalAttempts(0), currentExpressionIndex(0) //initialize variables
{
    ui->setupUi(this);
    connect(ui->btnSubmit, &QPushButton::clicked, this, &SumGenerator::submitAnswer);
    connect(ui->btnExit, &QPushButton::clicked, this, &QApplication::quit);
    connect(ui->actionContext,&QAction::triggered, this, &SumGenerator::showHelp);
    connect(ui->actionAbou,&QAction::triggered, this, &SumGenerator::showAbout);
    connect(ui->actionRestart,&QAction::triggered, this, &SumGenerator::restartGame);
    connect(ui->actionExit,&QAction::triggered, this, &SumGenerator::exitGame);
    connect(ui->actionRating,&QAction::triggered, this, &SumGenerator::showRating);
    connect(ui->actionCSS,&QAction::triggered, this, &SumGenerator::showCredits);
    generateSum();
}

//credits for materials used
void SumGenerator::showCredits()
{
    QString credits;
    credits = "AMOLED Style Sheet for QT Applications  \n Author: Jaime A. Quiroga P. \n Company: GTRONICK \n Last updated: 01/10/2021, 15:49. \n Available at: https://github.com/GTRONICK/QSS/blob/master/AMOLED.qss\n\nIcon:\nAvailable at: https://www.vectorstock.com/royalty-free-vector/math-pi-creative-light-bulb-mathematics-logo-vector-30008842";
    QMessageBox::information(this, "Credits", credits);
}

//Calculate rating according to mark
void SumGenerator::showRating()
{
    QString rating;
    double percent = static_cast<double>(score) / totalAttempts * 100;
    if (percent >= 80.0 && percent <=100.00)
    {
        rating = "A+";
    }
    else if (percent >= 70.0 && percent <80.00)
    {
        rating = "A";
    }
    else if (percent >= 60.0 && percent <70.00)
    {
        rating = "B";
    }
    else if (percent >= 50.0 && percent <60.00)
    {
        rating = "C";
    }
    else if (percent >= 40.0 && percent <50.00)
    {
        rating = "D";
    }
    else if (percent >= 30.0 && percent <40.00)
    {
        rating = "E";
    }
    else if (percent >= 0.0 && percent <30.00)
    {
        rating = "F";
    }

    QMessageBox::information(this, "Rating", "Your rating is: " + rating);
}

void SumGenerator::updatePercentLabel() //Calculate percentage
{
    qDebug() << totalAttempts;
    double percentage = totalAttempts > 0 ? static_cast<double>(score)/totalAttempts * 100 : 0.0; //ternary operator to calculate percentage

    //Update label
    ui->lblPercent->setText("Percentage: "+ QString::number(percentage, 'f', 2) + "%"); //format to 2 decimal places

}

void SumGenerator::restartGame() // Restart game
{
    //Reset variables to zero
    score = 0;
    totalAttempts = 0;
    currentExpressionIndex = 0;

    //enable submit button again
    ui->btnSubmit->setEnabled(true);

    //create new expressions
    expressions.clear();

    //Generate 10 random sums
    for (int i = 0; i < 10; ++i)
    {
        QString sign; //holds operator
        int firstNum = 0, secondNum = 0;

        //Random selection of sign from 4
        int signIndex = QRandomGenerator::global()->bounded(4);
        switch(signIndex)
        {
        case 0: //Add
            sign = "+";
            firstNum = QRandomGenerator::global()->bounded(50);
            secondNum = QRandomGenerator::global()->bounded(50);
            break;
        case 1: //subtract
            sign = "-";
            firstNum = QRandomGenerator::global()->bounded(50);
            secondNum = QRandomGenerator::global()->bounded(firstNum); //Makes sure second number is always less than first number
            break;
        case 2: //Multiply
            sign = "x";
            firstNum = QRandomGenerator::global()->bounded(13);
            secondNum = QRandomGenerator::global()->bounded(13);
            break;
        case 3: //Divide
            sign = "/";
            secondNum = QRandomGenerator::global()->bounded(12)+1;
            firstNum = secondNum * QRandomGenerator::global()->bounded(1, 13) ; //Generate a number that is divisble by second number
            break;
        }
        //store expresions in QList as QString
        expressions.append(QString::number(firstNum) + " " + sign + " " + QString::number(secondNum));
    }
    //Update labels on form accordingly
    updateLableScore();
    updatePercentLabel();
    displayNextExpression();

}

void SumGenerator::exitGame() //To exit app
{
    QApplication::quit();
}

void SumGenerator::showHelp() //Help dialog
{
    QMessageBox::information(this, "Help", "This arithmetic game presents expressions for you to solve. Enter your answer and select submit to validate");
}

void SumGenerator::showAbout() //About
{
    QMessageBox::information(this, "About", "This is a simple arithmetic game for you to check your arithmetic skills");
}

void SumGenerator::updateLableScore()
{
    //Update the label score
    ui->lblScore->setText("Score: " + QString::number(score)+ " correct out of " + QString::number(totalAttempts) +" sum(s)");
}

void SumGenerator::generateSum()
{
    //Generate 10 random sums
    for (int i = 0; i < 10; ++i)
    {
        QString sign; //holds operator
        int firstNum = 0, secondNum = 0;

        //Random selection of sign from 4
        int signIndex = QRandomGenerator::global()->bounded(4);
        switch(signIndex)
        {
            case 0: //Add
                sign = "+";
                firstNum = QRandomGenerator::global()->bounded(50);
                secondNum = QRandomGenerator::global()->bounded(50);
                break;
            case 1: //subtract
                sign = "-";
                firstNum = QRandomGenerator::global()->bounded(50);
                secondNum = QRandomGenerator::global()->bounded(firstNum); //Makes sure second number is always less than first number
                break;
            case 2: //Multiply
                sign = "x";
                firstNum = QRandomGenerator::global()->bounded(13);
                secondNum = QRandomGenerator::global()->bounded(13);
                break;
            case 3: //Divide
                sign = "/";
                secondNum = QRandomGenerator::global()->bounded(12)+1;
                firstNum = secondNum * QRandomGenerator::global()->bounded(1, 13) ; //Generate a number that is divisble by second number
                break;
        }
        //stores expressions in QList
        expressions.append(QString::number(firstNum) + " " + sign + " " + QString::number(secondNum));
    }
    displayNextExpression(); //Display expression
}

void SumGenerator::displayNextExpression() //Function to display expression stored in QList of expressions
{
    QString expression = expressions[currentExpressionIndex++]; //Get current expression
    ui->lblExpression->setText(expression);
    ui->lineEditAnswer->clear();
    ui->lineEditAnswer->setFocus();
}

void SumGenerator::submitAnswer()
{

    QString userInput = ui->lineEditAnswer->text();
    //Validate if user input is in correct integer format
    bool ok;
    int userAns = userInput.toInt(&ok); //uses extra toInt() argument that returns boolean
    //Validate input until user enters correct data
    if (!ok)
    {
        QMessageBox::warning(this, "Inavlid input", "Invalid input. Enter a valid integer");
        ui->lineEditAnswer->clear();
        return;
    }

    //Split expression that was stored
    QStringList parts = ui->lblExpression->text().split(" "); //split by space
    int num1 = parts[0].toInt(); //first number
    QString sign = parts[1]; //sign
    int num2 = parts[2].toInt(); //last number

    //Calulate correct answer using split data

    if (sign == "+")
    {
        rightAnswer = num1 + num2;
    }
    else if (sign == "-")
    {
        rightAnswer = num1 - num2;
    }
    else if (sign == "x")
    {
        rightAnswer = num1 * num2;
    }
    else if (sign == "/")
    {
        rightAnswer = num1 / num2;
    }

    //checkif user entered correct answer
    if(userAns == rightAnswer)
    {
        QMessageBox::information(this, "Result", "Correct!");
        score++; //increase score if correct
    }
    else
    {
        QMessageBox::information(this, "Result", "Incorrect. The correct answer is: " + QString::number(rightAnswer)); //displays right answer if user entered wrong answer
    }
    totalAttempts++; //track of how many questions have been asked
    updateLableScore();

    //Check if there are still sums in QList
    if (totalAttempts < 10)
    {
        displayNextExpression();

    }
    else
    {
        //End game
        QMessageBox::information(this, "Game Over", "Final Score: " + QString::number(score) + "/" + QString::number(totalAttempts)); //After 10 questions
        ui->btnSubmit->setEnabled(false); //disable submit button
    }

    //Update percent label after one attempt
    if (totalAttempts > 0)
    {
        updatePercentLabel();
    }
}



SumGenerator::~SumGenerator()
{
    delete ui;
}






