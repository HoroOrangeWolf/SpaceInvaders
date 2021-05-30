#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMovie>
#include <QGraphicsScene>
#include <game.h>
#include <sqldatabse.h>

/**
 * @file game.h
 * Plik nagłówkowy klasy Game implementującej rozgrywkę.
 */
/**
 *@file sqldatabase.h
 * Plik nagłówkowy klasy SqlDatabase odpowiedzialnej za połączenie z bazą danych.
 */
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * Klasa odpowiedzialna za wygląd i obsługę zdarzeń zachodzących w głównym oknie programu. Łączy w sobie wyświetlanie programu, właściwą grę oraz połączenie z bazą danych.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void movieBackground();
    void resizeEvent(QResizeEvent *q);
    void resizeMenuElements();
    void resizeBackGround();
    void setIndex(int a);
    void restartGame(int a, int score);

    static MainWindow *getWindows();

private slots:
    void on_playbt_clicked();
    void on_backbt_clicked();
    void on_exitbt_clicked();

    void on_scorebt_clicked();

    void on_backbtscorep_clicked();

    void on_SearchBt_clicked();

    void on_playbtp2_clicked();

    void on_gameOver_btn_clicked();

    void on_backbt_2_clicked();

    void on_level1_btn_clicked();

    void on_level2_btn_clicked();

    void on_level3_btn_clicked();

    void on_wingamebutton_clicked();

private:
    static MainWindow *windows; /**< Obiekt przechowujący okno główne programu. Inicjalizowana wwartością początkową NULL.*/
    Ui::MainWindow *ui = NULL; /**< Interfejs użytkownika. */
    QStackedWidget *widgetstack = NULL; /**< Stos elementów w interfejsie użytkownika. */
    SqlDatabse *database = NULL; /**< Obiekt bazy danych. */
    Game *game = NULL; /**< Obiekt rozgrywki. */
    bool ismovieactive = false; /**< Flaga ustawienia tła programu. */
    bool isbaseconnected = false; /**< Flaga połączenia z bazą danych. */
};

#endif // MAINWINDOW_H
