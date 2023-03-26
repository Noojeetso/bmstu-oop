QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bivector.cpp \
    connections.cpp \
    draw.cpp \
    errors.cpp \
    files.cpp \
    geometry.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    math_impl.cpp \
    model.cpp \
    pivot.cpp \
    projected_vertices.cpp \
    vertices.cpp

HEADERS += \
    bivector.h \
    connections.h \
    draw.h \
    errors.h \
    files.h \
    geometry.h \
    mainwindow.h \
    manager.h \
    math_impl.h \
    model.h \
    pivot.h \
    projected_vertices.h \
    vertices.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cube.txt
