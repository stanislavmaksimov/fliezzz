TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    controller.cpp \
    fly.cpp \
    common.cpp \
    flymodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
include(generated/generated.pri)

HEADERS += \
    controller.h \
    fly.h \
    common.h \
    flymodel.h
