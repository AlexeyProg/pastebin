QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

LIBS += -L/opt/homebrew/Cellar/postgresql@14/14.8/lib/postgresql@14 -lpq


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/db/dbimporter.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/note.cpp

HEADERS += \
    src/db/dbimporter.h \
    src/mainwindow.h \
    src/note.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


TRANSLATIONS += pastebin_ru.ts \
                pastebin_eng.ts

RESOURCES += \
    lang.qrc
