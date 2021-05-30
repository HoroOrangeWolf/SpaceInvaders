#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
/**
 * @class Score
 * Klasa przechowująca informacje o punktach zdobytych przez gracza.
 */

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent=0);
    ~Score();
    void increase();
    int getScore();
    void setScore(int score);
    static Score * getScores();
private:
    int score; /**< Liczba punktów zdobytych przez gracza. */
    static Score *scores; /**< Obiekt przechowujący punkty gracza, zainicjalizowany wartością początkową NULL. */
};




#endif // SCORE_H
