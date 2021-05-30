#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <enemydata.h>
#include <QMovie>
#include <QVector2D>
#include <QMediaPlayer>
#include <QSound>
#include <QUrl>

/**
 * @class GameSettings
 * Klasa odpowiedzialna za ustawienia rozgrywki, takie jak tło, ścieżka dźwiękowa, wektor poruszania się pocisku przeciwnika,
 * wektor poruszania się pocisku gracza oraz lista przeciwników w rozgrywce.
 */
class GameSettings
{
public:
    GameSettings();
    QVector2D getVectorship() const;
    void setVectorship(const QVector2D &value);

    QVector2D getVectorenemy() const;
    void setVectorenemy(const QVector2D &value);

    QMovie *getMovie() const;
    void setMovie(QMovie *value);

    std::list<EnemyData> getEnemydata() const;

    void addEnemy(EnemyData enemy);

    int getLevel() const;
    void setLevel(int value);
    QUrl getBackgroundSound() const;
    void setBackgroundSound(QUrl value);

private:
    //Background
    QMovie *movie = NULL; /**< Obiekt tła rozgrywki. */

    //EnemyData
    std::list<EnemyData> enemydata; /**< Lista przeciwników. */

    //Vector poruszania sie pocisku przeciwnika
    QVector2D vectorenemy; /**< Wektor poruszania się pocisku przeciwnika. */

    //Vector poruszania sie pocisku naszego statku
    QVector2D vectorship; /**< Wektor poruszania się pocisku gracza. */

    int level; /**< Poziom gry. */
    QUrl backgroundsound; /**< Ścieżka dźwiękowa gry. */
};

#endif // GAMESETTINGS_H
