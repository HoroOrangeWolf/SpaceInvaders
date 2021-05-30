#include "gamesettings.h"
/**
  * @file gamesettings.h
  * Plik nagłówkowy klasy GameSettings
  * /

/**
 * @brief GameSettings::GameSettings
 * Kontruktor klasy GameSettings. Ustawia ściężkę dźwiękowa jako obiekt klasy QUrl().
 */
GameSettings::GameSettings()
{
    this->backgroundsound = QUrl();
}
/**
 * @brief GameSettings::getVectorship
 * Pobranie wartości zmiennej vectorship przechowującej wektor poruszania się pocisku gracza.
 * @return Zwraca obiekt QVector2D - wektor poruszania się pocisku gracza.
 */

QVector2D GameSettings::getVectorship() const
{
    return vectorship;
}
/**
 * @brief GameSettings::setVectorship
 * Ustawienie wartości zmiennej vectorship przechowującej wektor poruszania się pocisku gracza.
 * @param value Obiekt QVector2D - wektor poruszania się pocisku gracza.
 */

void GameSettings::setVectorship(const QVector2D &value)
{
    vectorship = value;
}
/**
 * @brief GameSettings::getVectorenemy
 * Pobranie wartości zmiennej vectorenemy przechowującej wektor poruszania się pocisku wroga.
 * @return Zwraca obiektt QVector2D - wektor poruszania się pocisku przeciwnika.
 */

QVector2D GameSettings::getVectorenemy() const
{
    return vectorenemy;
}
/**
 * @brief GameSettings::setVectorenemy
 * Ustawienie wartości zmiennej vectorenemy przechowującej wektor poruszania się pocisku wroga.
 * @param value Obiekt QVector2D - wektor poruszania się pocisku przeciwnika.
 */

void GameSettings::setVectorenemy(const QVector2D &value)
{
    vectorenemy = value;
}
/**
 * @brief GameSettings::getMovie
 * Pobranie wartości zmiennej movie przechowującej obiekt tła.
 * @return Zwraca obiekt QMovie - tło gry.
 */

QMovie *GameSettings::getMovie() const
{
    return movie;
}
/**
 * @brief GameSettings::setMovie
 * Ustawienie wartości zmiennej movie przechowującej obiekt tła.
 * @param value Obiekt QMovie - tło rozgrywki.
 */

void GameSettings::setMovie(QMovie *value)
{
    movie = value;
}
/**
 * @brief GameSettings::getEnemydata
 * Pobranie listy przeciwników rozgrywki.
 * @return Lista obiektów klasy EnemyData - lista przeciwników.
 */

std::list<EnemyData> GameSettings::getEnemydata() const
{
    return enemydata;
}
/**
 * @brief GameSettings::addEnemy
 * Dodanie przeciwnika na koniec listy wrogów.
 * @param enemy Obiekt klasy EnemyData - przeciwnik.
 */

void GameSettings::addEnemy(EnemyData enemy)
{
    this->enemydata.push_back(enemy);
}
/**
 * @brief GameSettings::getLevel
 * Pobranie wartości zmiennej level - poziom gry.
 * @return Zmienna typu integer - poziom gry.
 */

int GameSettings::getLevel() const
{
    return level;
}
/**
 * @brief GameSettings::setLevel
 * Ustawienie poziomu gry - zmienna level.
 * @param value Zmienna typu całkowitego będąca poziomem gry.
 */

void GameSettings::setLevel(int value)
{
    level = value;
}
/**
 * @brief GameSettings::getBackgroundSound
 * Pobranie adresu ścieżki dźwiękowej.
 * @return Obiekt QUrl - adres ścieżki dźwiękowej.
 */

QUrl GameSettings::getBackgroundSound() const
{
    return backgroundsound;
}
/**
 * @brief GameSettings::setBackgroundSound
 * Ustawienie adresu ścieżki dźwiękowej w zmiennej backgroundsound.
 * @param value Obiekt QUrl - adres ścieżki dźwiękowej.
 */
void GameSettings::setBackgroundSound(QUrl value)
{
    backgroundsound = value;
}

