QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Credit/credit.cpp \
    Credit/credit_result.cpp \
    Graff_and_set_x/graff.cpp \
    Graff_and_set_x/set_graff_border.cpp \
    Graff_and_set_x/set_x.cpp \
    Model_and_Controller/controller.cpp \
    Model_and_Controller/model.cpp \
    main.cpp \
    interface.cpp \
    qcustomplot.cpp

HEADERS += \
    Credit/credit.h \
    Credit/credit_result.h \
    Graff_and_set_x/graff.h \
    Graff_and_set_x/set_graff_border.h \
    Graff_and_set_x/set_x.h \
    Graff_and_set_x/ui_set_graff_border.h \
    Model_and_Controller/controller.h \
    Model_and_Controller/model.h \
    interface.h \
    qcustomplot.h

FORMS += \
    Credit/credit.ui \
    Credit/credit_result.ui \
    Graff_and_set_x/graff.ui \
    Graff_and_set_x/set_graff_border.ui \
    Graff_and_set_x/set_x.ui \
    interface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
