QT += core gui quick sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clients.cpp \
        database_sql.cpp \
        drivers.cpp \
        main.cpp \
        materials.cpp \
        orderstroibase.cpp \
        suppliers.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    clients.h \
    database_sql.h \
    drivers.h \
    materials.h \
    orderstroibase.h \
    suppliers.h
