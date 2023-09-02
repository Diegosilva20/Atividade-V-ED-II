QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buscar.cpp \
    comparardepartamentotipocontratonome.cpp \
    comparardepartamentotitulacaonome.cpp \
    compararpordepartamentoandnome.cpp \
    compararpormatricula.cpp \
    compararpornome.cpp \
    comparartipocontratoandnome.cpp \
    comparartitulacaoandnome.cpp \
    docentes.cpp \
    docentescomparador.cpp \
    docentesordena.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    buscar.h \
    comparardepartamentotipocontratonome.h \
    comparardepartamentotitulacaonome.h \
    compararpordepartamentoandnome.h \
    compararpormatricula.h \
    compararpornome.h \
    comparartipocontratoandnome.h \
    comparartitulacaoandnome.h \
    docentes.h \
    docentescomparador.h \
    docentesordena.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
