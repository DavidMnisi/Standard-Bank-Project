#ifndef SUMGENERATOR_H
#define SUMGENERATOR_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRandomGenerator>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class SumGenerator;
}
QT_END_NAMESPACE

class SumGenerator : public QMainWindow
{
    Q_OBJECT

public:
    SumGenerator(QWidget *parent = nullptr);
    ~SumGenerator();

private slots:
    void generateSum(); //to gnerate the sum
    void submitAnswer();
    void displayNextExpression();

    //Menu actions
    void showAbout();
    void showHelp();
    void restartGame();
    void exitGame();
    void showRating();
    void showCredits();

private:
    Ui::SumGenerator *ui;

    QStringList expressions;
    int rightAnswer;
    int score;
    int totalAttempts;
    int currentExpressionIndex;
    void updateLableScore();
    void updatePercentLabel();

};
#endif // SUMGENERATOR_H
