#include "score.h"
/**
  * @file score.h
  * Plik nagłówkowy klasy Score, przechowującej informacje o liczbie punktów gracza.
  */
#include <QFont>
/**
 * @brief Score::Score
 * Konstruktor klasy Score. Ustawia początkową liczbę punktów oraz sposób prezentacji punktów.
 * @param parent Obiekt QGraphicsItem
 */

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

    score = 0;
    setPlainText(QString("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    scores = this;
}
/**
 * @brief Score::~Score
 * Destruktor klasy Score. Usuwa obiekt przechowujący punkty.
 */

Score::~Score()
{
    scores = NULL;
}
/**
 * @brief Score::increase
 * Zwiększenie liczby puktów i zmiana elementu wyświetlanego.
 */



void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+ QString::number(score));

}
/**
 * @brief Score::getScore
 * Pobieranie liczby punktów zdobytych przez gracza.
 * @return Całkowita liczba punktów gracza.
 */

int Score::getScore()
{
    return score;
}
/**
 * @brief Score::setScore
 * Ustawienie liczby punktów gracza.
 * @param score Liczba całkowita - liczba punktów.
 */

void Score::setScore(int score)
{
    this->score = score;
    setPlainText(QString("Score: ")+ QString::number(score));
}
/**
 * @brief Score::getScores
 * Pobranie obiektu przechowującego liczbę punktów z graficzną reprezentacją.
 * @return Obiekt Score - graficzna reprezentacja liczby punktów.
 */

Score *Score::getScores()
{
    return scores;
}

Score * Score::scores = NULL;
