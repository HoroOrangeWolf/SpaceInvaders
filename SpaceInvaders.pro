QT       += core gui \
                multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                                     sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animation.cpp \
    animationcontainer.cpp \
    bullet.cpp \
    bulletcontainer.cpp \
    canshoot.cpp \
    enemy.cpp \
    enemycontainer.cpp \
    enemydata.cpp \
    enemyspawner.cpp \
    game.cpp \
    gamescene.cpp \
    gamesettings.cpp \
    health.cpp \
    main.cpp \
    mainwindow.cpp \
    pixmapcontainer.cpp \
    score.cpp \
    ship.cpp \
    sqldatabse.cpp

HEADERS += \
    ContainerElement.h \
    animation.h \
    animationcontainer.h \
    bullet.h \
    bulletcontainer.h \
    canshoot.h \
    enemy.h \
    enemycontainer.h \
    enemydata.h \
    enemyspawner.h \
    game.h \
    gamescene.h \
    gamesettings.h \
    health.h \
    mainwindow.h \
    pixmapcontainer.h \
    score.h \
    ship.h \
    sqldatabse.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
