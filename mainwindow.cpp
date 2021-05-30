#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QLabel>
#include <QRect>
#include <QSize>
#include <QTextEdit>
#include <QPushButton>
#include <sqldatabse.h>
#include <QScrollBar>
#include <QListWidget>
#include <sstream>
#include <game.h>
#include <ship.h>
#include <gamesettings.h>
#include <QMessageBox>
#include <animation.h>
#include <enemydata.h>
#include <QSound>
/**
 * @file mainwindow.h
 * Plik nagłówkowy klasy MainWindow.
 */
/**
 * @file sqldatabase.h
 * Plik nagłówkowy klasy SqlDatabase odpowiedzialnej za połączenie z bazą danych.
 */
/**
 * @file game.h
 * Plik nagłówkowy klasy Game odpowiedzialnej za przebieg rozgrywki.
 */
/**
 * @file ship.h
 * Plik nagłówkowy klasy Ship tworzącej i obsługującej statek gracza.
 */
/**
 * @file gamesettings.h
 * Plik nagłówkowy klasy GameSettings przechowującej ustawienia gry.
 */
/**
 * @file animation.h
 * Plik nagłówkowy klasy Animation odpowiadającej za odtwarzanie animacji w programie.
 */

/**
 * @file enemydata.h
 * Plik nagłówkowy klasy EnemyData zawierającej informacje o przeciwniku i jego możliwościach.
 */

/**
 * @brief MainWindow::MainWindow
 * Konstruktor klasy MainWindow. Ustawia podstawowy wygląd programu, inicjalizuje stos elementów i wyśrodkowuje je, tworzy obiekt bazy danych oraz połączenie z bazą danych.
 * @param parent Obiekt QWidget
 * @see resizeMenuElements()
 * @see SqlDatabase::SqlDatabase()
 * @see SqlDatabase::setupDatabase()
 * @see SqlDatabase::connectDatabase()
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->statusbar->setHidden(true);
    this->ui->centralwidget->setContentsMargins(0, 0, 0, 0);

    //inicializacja widgetstuck
    this->widgetstack = this->findChild<QStackedWidget *>("stackedWidget");

    this->widgetstack->setContentsMargins(0, 0, 0, 0);
    this->widgetstack->setCurrentIndex(0);

    //ustawianie elementów takich jak, przyciski aby były wyśrodkowane
    this->resizeMenuElements();
    //koniec wyśrodkowania

    if(MainWindow::windows != NULL)
        throw "ERROR!!!";

    MainWindow::windows = this;
    this->database = new SqlDatabse();
    this->database->setupDatabase();
    this->isbaseconnected = this->database->connectDatabase();
}
/**
 * @brief MainWindow::~MainWindow
 * Destruktor klasy MainWindow. Usuwa obiekt klasy i interfejs użytkownika oraz rozłącza z bazą danych i usuwa jej obiekt.
 * @see SqlDatabase::closeConnection()
 */

MainWindow::~MainWindow()
{
    windows = NULL;
    delete ui;

    this->database->closeConnection();
    delete this->database;
}

//funkcja odpowiedzialna za wyświetlanie gif jako tło głównego menu
/**
 * @brief MainWindow::movieBackground
 * Ustawienie i wyświetlenie tła programu.
 */

void MainWindow::movieBackground()
{
    QMovie *qmovie = new QMovie(":/gifs/background.gif");

    this->ui->background->setContentsMargins(0, 0, 0, 0);

    this->ui->background->resize(this->width() + 10, this->height() + this->ui->statusbar->height());

    qmovie->setScaledSize(QSize(this->ui->background->width(), this->ui->background->height()));
    //QLabel *
    this->ui->background->setMovie(qmovie);

    qmovie->start();

    this->ismovieactive = true;
}
//przestawia elementy, odpowiednio je przestawiając
/**
 * @brief MainWindow::resizeEvent
 * Ustawienie elementow.
 * @param q Obiekt QResizeEvent.
 * @see resizeMenuElements()
 * @see resizeBackGround()
 */
void MainWindow::resizeEvent(QResizeEvent *q)
{
    this->resizeMenuElements();
    this->resizeBackGround();
}
//funkcja środkująca przyciski i inne elementy menu.
/**
 * @brief MainWindow::resizeMenuElements
 * Przestawienie (wyśrodkowanie) elementów takich jak przyciski, pola do wprowadzania danych czy etykiety w oknie.
 * @see returnGameScene()
 * @see resizeGameScene()
 */
void MainWindow::resizeMenuElements()
{
    //przyciski

    QPushButton *button = this->findChild<QPushButton *>("playbt");
    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("scorebt");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("playbt");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("exitbt");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("backbt");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("playbtp2");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("gameOver_btn");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("wingamebutton");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    //levele
    button = this->findChild<QPushButton *>("backbt_2");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("level1_btn");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("level2_btn");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    button = this->findChild<QPushButton *>("level3_btn");

    button->move((this->width())/2 - button->width()/2, button->pos().y());

    //pola edycji
    QLineEdit *edit = this->findChild<QLineEdit *>("insertnickname");

    edit->move((this->width()/2) - edit->width()/2, edit->pos().y());

    //pole gry
    this->ui->gamescene->resize(this->width() + 2, this->height() + this->statusBar()->height());

    this->widgetstack->resize(this->width(), this->height() + this->statusBar()->height());

    if(this->game != NULL)
    {
        this->game->returnGameScene()->resizeGameScene(this->width(), this->height() + this->statusBar()->height() + 2);
    }

    //graphics view spaceinaders

    QGraphicsView *view = this->findChild<QGraphicsView *>("graphicsView");
    view->move(this->width()/2 - view->width()/2, view->pos().y());

    //game score label
    QLabel *label = this->findChild<QLabel *>("winlabel");
    label->move((this->width()/2) - label->width()/2, label->pos().y());

    label = this->findChild<QLabel *>("overlabel");
    label->move((this->width()/2) - label->width()/2, label->pos().y());
}
/**
 * @brief MainWindow::resizeBackGround
 * Odpowiednie ustawienie tła w oknie.
 */

void MainWindow::resizeBackGround()
{

    if(this->ismovieactive == false)
        return;
    //Pobrane z qlabel (background to nazwa obiektu)
    QMovie *movie = this->ui->background->movie();
    movie->stop();

    this->ui->background->resize(this->width() + 10, this->height() + this->ui->statusbar->height());

    movie->setScaledSize(QSize(this->ui->background->width(), this->ui->background->height()));

    movie->start();

    QGraphicsView *s = this->widgetstack->findChild<QGraphicsView *>("gamescene");

    s->resize(this->width() + 2, this->height() + this->ui->statusbar->height());
}
/**
 * @brief MainWindow::setIndex
 * Ustawienie odpowiedniego indeksu na stosie elementów, dzięki czemu zmienia się widok interfejsu użytkownika.
 * @param a Liczba całkowita, indeks do ustawienia.
 */

void MainWindow::setIndex(int a)
{
    this->widgetstack->setCurrentIndex(a);
}
/**
 * @brief MainWindow::restartGame
 * Zresetowanie gry, po zakończeniu rozgrywki. Wyświetlenie etykiety z odpowiednim komunikatem oraz liczbą zdobytych punktów. Usunięcie obiektu gray Game
 * oraz zapisanie wyniku w bazie danych.
 * @param a Indeks strony interfejsu użytkownika.
 * @param score Liczba całkowita jako liczba punktów zdobytych przez gracza w rozgrywce.
 * @see setIndex()
 * @see SqlDatabase::isConnectedDatabase()
 * @see SqlDatabase::updateScore()
 */

void MainWindow::restartGame(int a, int score)
{
    if(a == 5)
    {
        QLabel *label = this->widgetstack->findChild<QLabel *>("overlabel");
        label->setText(QString("Score: ") + QString::number(score));
    }
    else
    {
        QLabel *label = this->widgetstack->findChild<QLabel *>("winlabel");
        label->setText(QString("Score: ") + QString::number(score));
    }

    this->setIndex(a);

    delete (this->game);

    this->game = NULL;

    if(this->database->isConnectedDatabase())
    {
        QString q = this->widgetstack->findChild<QLineEdit*>("insertnickname")->text();
        this->database->updateScore(q, score);
    }
}
/**
 * @brief MainWindow::on_playbt_clicked
 * Obsługa przycisku PLAY.
 * @see setIndex()
 */


void MainWindow::on_playbt_clicked()
{
   this->setIndex(2);
}
/**
 * @brief MainWindow::on_backbt_clicked
 * Obsługa przycisku BACK. Wyczyszczenie pola Insert Nickname.
 * @see setIndex()
 */



void MainWindow::on_backbt_clicked()
{
    this->setIndex(0);

    QLineEdit *nick = this->ui->centralwidget->findChild<QLineEdit *>("insertnickname");
    nick->clear();
}
/**
 * @brief MainWindow::on_exitbt_clicked
 * Obsługa przycisku EXIT. Zamknięcie programu.
 */

void MainWindow::on_exitbt_clicked()
{
    this->close();
}
/**
 * @brief MainWindow::on_scorebt_clicked
 * Obsługa przycisku SCORE TABLE. Pobranie wyników z bazy danych i wyświetlenie ich w odpowiednim miejscu.
 * @see SqlDatabase::isConnectedDatabase()
 * @see SqlDatabase::getResult()
 */

void MainWindow::on_scorebt_clicked()
{
    if(!this->database->isConnectedDatabase())
        return;

    QString *res = this->database->getResult();

    QListWidget *list = this->ui->centralwidget->findChild<QListWidget *>("listscore");

    if(*(res + 1) == '\0')
    {
        list->addItem(*res);
        this->widgetstack->setCurrentIndex(1);
        return;
    }

    for(int i = 0; *(res + i) != '\0';)
    {
        QString s = "Name: ";
        s += *(res + i++);
        s += " Score: ";
        s += *(res + i++);
        list->addItem(s);
    }
    this->widgetstack->setCurrentIndex(1);
}
/**
 * @brief MainWindow::on_backbtscorep_clicked
 * Obsługa przycisku BACK. Wyczyszczenie pola z wynikami.
 * @see setIndex()
 */

void MainWindow::on_backbtscorep_clicked()
{
    this->setIndex(0);
    this->ui->centralwidget->findChild<QListWidget *>("listscore")->clear();
}
/**
 * @brief MainWindow::on_SearchBt_clicked
 * Obsługa przycisku SEARCH. Wyszukiwanie wyniku po nazwie użytkownika.
 * @see SqlDatabase::isConnectedDatabase()
 * @see SqlDatabase:: getScoreByName()
 */

void MainWindow::on_SearchBt_clicked()
{
    if(!this->database->isConnectedDatabase())
        return;

    QLineEdit *line = this->ui->centralwidget->findChild<QLineEdit *>("insertnickname_2");

    int score = this->database->getScoreByName(line->text());

    QListWidget *list = this->ui->centralwidget->findChild<QListWidget *>("listscore");
    list->clear();

    if(score == -1)
    {
        list->addItem(QString("Player not found!!!!"));
    }
    else
    {
        QString s = "Name: ";
        s += line->text();
        s += " Score: ";

        std::stringstream sstream;
        sstream << score;
        std::string st;
        sstream >> st;
        s += QString::fromStdString(st);
        list->addItem(s);
    }
}
/**
 * @brief MainWindow::on_playbtp2_clicked
 * Obsługa przycisku PLAY. Sprawdzenie poprawności wprowadzonego nickname.
 * @see setIndex()
 */

void MainWindow::on_playbtp2_clicked()
{
    QLineEdit *nick = this->ui->centralwidget->findChild<QLineEdit *>("insertnickname");
    if(nick->text().length()>0)
        this->setIndex(3);
    else
        QMessageBox::information(this, "Invalid nickname", "Your nickname is too short", QMessageBox::Ok);

}
/**
 * @brief MainWindow::on_backbt_2_clicked
 * Obsługa przycisku BACK. Wyczyszczenie pola do wprowadzania nickname.
 * @see setIndex()
 */

void MainWindow::on_backbt_2_clicked()
{
    this->setIndex(0);
    QLineEdit *nick = this->ui->centralwidget->findChild<QLineEdit *>("insertnickname");
    nick->clear();
}
/**
 * @brief MainWindow::on_level1_btn_clicked
 * Obsługa przycisku LEVEL 1. Stworzenie rozgrywki oraz inicjalizacja jej ustawień. Wyświetlenie rozgrywki.
 * @see setIndex()
 * @see GameSettings::setLevel()
 * @see GameSettings::setMovie()
 * @see GameSettings::setBackgroundSound()
 * @see GameSettings::setVectorenemy()
 * @see GameSettings::setVectorship()
 * @see GameSettings::addEnemy()
 * @see Game::Game()
 * @see Game::returnGameScene()
 * @see Game::resizeGameScene()
 * @see Game::setSceneRect()
 * @see Game::initShip()
 * @see Game::startUpdater()
 */

void MainWindow::on_level1_btn_clicked()
{
    this->setIndex(4);

    QGraphicsView *s = this->widgetstack->findChild<QGraphicsView *>("gamescene");

    s->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    s->resize(this->width() + 2, this->height() + this->ui->statusbar->height());

    s->move(-1, -1);

    GameSettings settings;

    settings.setLevel(1);
    settings.setMovie(NULL);

    settings.setBackgroundSound(QUrl("qrc:sounds/res/music1.mp3"));

    //ten fragment nie dziala, nie ma obslugi w klasie Game
    settings.setVectorenemy(QVector2D(0.0f, 250.0f));
    settings.setVectorship(QVector2D(0.0f, -250.0f));

    settings.addEnemy(EnemyData(ENEMYGIF2, 40, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2,180, 80, 80, 3));
    settings.addEnemy((EnemyData(ENEMYGIF2, 150, 80, 80, 3)));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 100, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 100, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 170, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 100, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 100, 80, 80, 3));



    game = new Game(settings);

    s->setScene(game->returnGameScene());

    this->game->returnGameScene()->resizeGameScene(this->width() + 2, this->height() + this->statusBar()->height() + 2);

    this->game->returnGameScene()->setSceneRect(QRect(0, 0, this->width() + 1, this->height() + this->statusBar()->height()));

    game->initShip();

    game->startUpdater(16);
    //zmienna *s -> (*game/*game2/*game3);
}
/**
 * @brief MainWindow::on_level2_btn_clicked
 * Obsługa przycisku LEVEL 2. Stworzenie rozgrywki oraz inicjalizacja jej ustawień. Wyświetlenie rozgrywki.
 * @see setIndex()
 * @see GameSettings::setLevel()
 * @see GameSettings::setMovie()
 * @see GameSettings::setBackgroundSound()
 * @see GameSettings::setVectorenemy()
 * @see GameSettings::setVectorship()
 * @see GameSettings::addEnemy()
 * @see Game::Game()
 * @see Game::returnGameScene()
 * @see Game::resizeGameScene()
 * @see Game::setSceneRect()
 * @see Game::initShip()
 * @see Game::startUpdater()
 */

void MainWindow::on_level2_btn_clicked()
{
    this->setIndex(4);
    QGraphicsView *s = this->widgetstack->findChild<QGraphicsView *>("gamescene");

    s->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    s->resize(this->width() + 2, this->height() + this->ui->statusbar->height());

    s->move(-1, -1);

    GameSettings settings;

    settings.setLevel(1);
    settings.setMovie(NULL);

    settings.setBackgroundSound(QUrl("qrc:sounds/res/music2.mp3"));

    //ten fragment nie dziala, nie ma obslugi w klasie Game
    settings.setVectorenemy(QVector2D(0.0f, 250.0f));
    settings.setVectorship(QVector2D(0.0f, -250.0f));

    \

    settings.addEnemy((EnemyData(ENEMYGIF2, 40, 80, 80, 3)));
    settings.addEnemy(EnemyData(ENEMYGIF2,150, 80, 80, 3));
    settings.addEnemy((EnemyData(ENEMYGIF2, 150, 80, 80, 3)));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(BOSS1GIF, 100,150, 150, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 180, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 3));
    settings.addEnemy(EnemyData(ENEMYGIF2, 100, 80, 80, 3));
    settings.addEnemy(EnemyData(BOSS1GIF, 100,150, 150, 5));

    game = new Game(settings);

    s->setScene(game->returnGameScene());

    this->game->returnGameScene()->resizeGameScene(this->width() + 2, this->height() + this->statusBar()->height() + 2);

    this->game->returnGameScene()->setSceneRect(QRect(0, 0, this->width() + 1, this->height() + this->statusBar()->height()));

    game->initShip();

    game->startUpdater(16);
}
/**
 * @brief MainWindow::on_level3_btn_clicked
 * Obsługa przycisku LEVEL 3. Stworzenie rozgrywki oraz inicjalizacja jej ustawień. Wyświetlenie rozgrywki.
 * @see setIndex()
 * @see GameSettings::setLevel()
 * @see GameSettings::setMovie()
 * @see GameSettings::setBackgroundSound()
 * @see GameSettings::setVectorenemy()
 * @see GameSettings::setVectorship()
 * @see GameSettings::addEnemy()
 * @see Game::Game()
 * @see Game::returnGameScene()
 * @see Game::resizeGameScene()
 * @see Game::setSceneRect()
 * @see Game::initShip()
 * @see Game::startUpdater()
 */

void MainWindow::on_level3_btn_clicked()
{
    this->setIndex(4);
    QGraphicsView *s = this->widgetstack->findChild<QGraphicsView *>("gamescene");

    s->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    s->resize(this->width() + 2, this->height() + this->ui->statusbar->height());

    s->move(-1, -1);

    GameSettings settings;

    settings.setLevel(1);
    settings.setMovie(NULL);

    settings.setBackgroundSound(QUrl("qrc:sounds/res/music3.mp3"));

    //ten fragment nie dziala, nie ma obslugi w klasie Game
    settings.setVectorenemy(QVector2D(0.0f, 250.0f));
    settings.setVectorship(QVector2D(0.0f, -250.0f));

    settings.addEnemy((EnemyData(ENEMYGIF2, 40, 80, 80, 5)));
    settings.addEnemy(EnemyData(ENEMYGIF2,150, 80, 80, 5));
    settings.addEnemy((EnemyData(ENEMYGIF2, 150, 80, 80, 5)));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 5));
    settings.addEnemy(EnemyData(BOSS1GIF, 150,150, 150, 8));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 5));
    settings.addEnemy(EnemyData(BOSS1GIF, 100,150, 150, 8));
    settings.addEnemy(EnemyData(ENEMYGIF2, 180, 80, 80, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 150, 80, 80, 5));
    settings.addEnemy(EnemyData(BOSS1GIF, 150,150, 150, 8));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 120, 80, 80, 5));
    settings.addEnemy(EnemyData(ENEMYGIF2, 100, 80, 80, 5));
    settings.addEnemy(EnemyData(BOSS1GIF, 100,150, 150, 8));

    game = new Game(settings);

    s->setScene(game->returnGameScene());

    this->game->returnGameScene()->resizeGameScene(this->width() + 2, this->height() + this->statusBar()->height() + 2);

    this->game->returnGameScene()->setSceneRect(QRect(0, 0, this->width() + 1, this->height() + this->statusBar()->height()));

    game->initShip();

    game->startUpdater(16);
}
/**
 * @brief MainWindow::getWindows
 * Pobiera obiekt okna głównego.
 * @return Obiekt MainWindow - okno główne programu.
 */
MainWindow *MainWindow::getWindows()
{
    return windows;
}
MainWindow *MainWindow::windows = NULL;

/**
 * @brief MainWindow::on_gameOver_btn_clicked
 * Obsługa przycisku GAME OVER. Powrót do pierwszej strony interfejsu użytkownika.
 * @see setIndex()
 */

void MainWindow::on_gameOver_btn_clicked()
{
    this->setIndex(0);
}
/**
 * @brief MainWindow::on_wingamebutton_clicked
 * Obsługa przycisku WIN GAME. Powrót do pierwszej strony interfejsu użytkownika.
 * @see setIndex()
 */

void MainWindow::on_wingamebutton_clicked()
{
    this->setIndex(0);
}
