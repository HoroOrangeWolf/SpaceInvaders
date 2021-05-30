#include "sqldatabse.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <iostream>

/**
  * @file sqldatabse.h
  * Plik nagłówkowy klasy SqlDatabase obsługującej bazę danych.
  */
/**
 * @brief SqlDatabse::SqlDatabse
 * Konstruktor klasy SqlDatabase.
 */
SqlDatabse::SqlDatabse()
{

}
/**
 * @brief SqlDatabse::setupDatabase
 * Konfiguracja bazy danych domyślnymi parametrami.
 */

void SqlDatabse::setupDatabase()
{
    this->mysql.setHostName(QString("127.0.0.1"));
    this->mysql.setPassword(QString(""));
    this->mysql.setUserName(QString("root"));
    this->mysql.setPort(3306);
}
/**
 * @brief SqlDatabse::setupDatabase
 * Konfiguracja bazy danych podanymi parametrami.
 * @param hostname Nazwa hosta.
 * @param username Nazwa użytkownika.
 * @param password Hasło.
 * @param port Numer portu.
 */

void SqlDatabse::setupDatabase(QString hostname, QString username, QString password, int port)
{
    this->mysql.setHostName(hostname);
    this->mysql.setPassword(password);
    this->mysql.setUserName(username);
    this->mysql.setPort(port);
}
/**
 * @brief SqlDatabse::connectDatabase
 * Połączenie z bazą danych.
 * @return Zwraca true jeśli udało się połączyć z bazą danych, w przeciwnym wypadku zwraca false.
 * @see createDatabase()
 */

bool SqlDatabse::connectDatabase()
{
    bool t = this->mysql.open();
    if(t)
        this->createDatabse();
    return t;
}
/**
 * @brief SqlDatabse::getResult
 * Pobranie 20 najmnieszych wyników z bazy danych.
 * @return Zwraca ciąg znaków QString stanowiący wyniki pobrane z baz danych.
 */

QString *SqlDatabse::getResult()
{
    if(!this->mysql.isOpen())
    {
        QString *buff = new QString[2];
        buff[0] = QString("connection error");
        buff[1] = '\0';
        return buff;
    }

    QSqlQuery query = QSqlQuery(this->mysql);

    query.exec("SELECT `name`, `score` FROM `scores` ORDER BY `score` ASC LIMIT 20");

    if(query.size() < 0)
    {
        QString *buff = new QString[2];
        buff[0] = QString("connection error");
        buff[1] = '\0';
        return buff;
    }

    QString *buff = new QString[query.size()*2 + 1];

    buff[query.size()*2] = '\0';
    int i = 0;
    while(query.next())
    {
        *(buff + i++) = query.value(0).toString();
        *(buff + i++) = query.value(1).toString();
    }



    return buff;
}
/**
 * @brief SqlDatabse::updateScore
 * Ukatualnienie wyników w bazie danych.
 * @param name Nazwa gracza.
 * @param score Liczba punktów zdobytych przez gracza.
 */

void SqlDatabse::updateScore(QString name, int score)
{
    if(!this->mysql.isOpen())
        return;
    QSqlQuery query = QSqlQuery(this->mysql);

    query.prepare("SELECT COUNT(*) FROM `scores` WHERE `name` LIKE :name");

    query.bindValue(":name", name);

    query.exec();

    if(!query.next())
        return;

    if(query.value(0).toInt() >= 1)
    {
         query.prepare("UPDATE `scores` SET `score` = :score WHERE `name` LIKE :name");
         query.bindValue(":name", name);
         query.bindValue(":score", score);
         query.exec();
    }
    else
    {
         query.prepare("INSERT INTO `scores` (`score`, `name`) VALUES (:score, :name)");
         query.bindValue(":name", name);
         query.bindValue(":score", score);
         query.exec();
    }




}
/**
 * @brief SqlDatabse::getScoreByName
 * Wyszukiwanie i wyświetlenie wyniku zdobytego przez gracza o podanej nazwie.
 * @param name Nazwa gracza.
 * @return Liczba punktów.
 */

int SqlDatabse::getScoreByName(QString name)
{
    if(!this->mysql.isOpen())
        throw "Can not connect to db";

    QSqlQuery query = QSqlQuery(this->mysql);

    query.prepare("SELECT `score` FROM `scores` WHERE `name` LIKE :name");

    query.bindValue(":name", name);

    query.exec();

    if(!query.next())
        return  -1;

    return query.value(0).toInt();
}
/**
 * @brief SqlDatabse::isConnectedDatabase
 * Sprawdzenie czy baza danych jest połączona.
 * @return Zwraca wartość true jeśli baza danych jest połączona, a false w przeciwnym wypadku.
 */

bool SqlDatabse::isConnectedDatabase()
{
    return this->mysql.isOpen();
}
/**
 * @brief SqlDatabse::closeConnection
 * Zamknięcie połączenie z bazą danych.
 */

void SqlDatabse::closeConnection()
{
    this->mysql.close();
}
//tworzy baze danych jezeli jeszcze nie istnieje
/**
 * @brief SqlDatabse::createDatabse
 * Utworzenie bazy danych jeżeli nie istnieje.
 */
void SqlDatabse::createDatabse()
{
    if(!this->mysql.isOpen())
        throw "Can not connect to db";

    QSqlQuery query = QSqlQuery(this->mysql);

    query.exec("CREATE DATABASE IF NOT EXISTS `SpaceInvaders` DEFAULT CHARACTER SET 'utf8' COLLATE 'utf8_general_ci'");

    query.exec("CREATE TABLE IF NOT EXISTS `SpaceInvaders`.`Scores` (IDScore int NOT NULL AUTO_INCREMENT, name varchar(30) DEFAULT 'no name', score int DEFAULT 0, PRIMARY KEY (`IDScore`))");

    this->mysql.close();

    this->mysql.setDatabaseName("SpaceInvaders");

    if(!this->mysql.open())
        throw "Can not connect to db";

}


