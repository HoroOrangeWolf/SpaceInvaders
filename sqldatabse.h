#ifndef SQLDATABSE_H
#define SQLDATABSE_H

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
/**
 * @class SqlDatabase
 * Klasa reprezentująca bazę danych do zapisywania wyników.
 */
class SqlDatabse
{
public:
    SqlDatabse();
    void setupDatabase();
    void setupDatabase(QString hostname, QString username, QString password, int port);
    bool connectDatabase();
    QString *getResult();
    void updateScore(QString name, int score);
    int getScoreByName(QString name);
    bool isConnectedDatabase();
    void closeConnection();
private:
    QSqlDatabase mysql = QSqlDatabase::addDatabase("QMYSQL"); /**< Obiekt bazy danych. */
    void createDatabse();
};

#endif // SQLDATABSE_H
