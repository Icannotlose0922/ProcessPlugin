QT       += core

TEMPLATE = lib
TARGET = threadweaver

CONFIG += c++11

DESTDIR = $$PWD/lib

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    collection.cpp \
    collection_p.cpp \
    debuggingaids.cpp \
    dependency.cpp \
    dependencypolicy.cpp \
    destructedstate.cpp \
    exception.cpp \
    executewrapper.cpp \
    executor.cpp \
    iddecorator.cpp \
    inconstructionstate.cpp \
    job.cpp \
    job_p.cpp \
    qobjectdecorator.cpp \
    queue.cpp \
    queueapi.cpp \
    queuesignals.cpp \
    queuesignals_p.cpp \
    queuestream.cpp \
    resourcerestrictionpolicy.cpp \
    sequence.cpp \
    sequence_p.cpp \
    shuttingdownstate.cpp \
    state.cpp \
    suspendedstate.cpp \
    suspendingstate.cpp \
    thread.cpp \
    threadweaver.cpp \
    weaver.cpp \
    weaver_p.cpp \
    weaverimplstate.cpp \
    workinghardstate.cpp

HEADERS += \
    collection.h \
    collection_p.h \
    debuggingaids.h \
    dependency.h \
    dependencypolicy.h \
    destructedstate.h \
    exception.h \
    executewrapper_p.h \
    executor_p.h \
    iddecorator.h \
    inconstructionstate.h \
    job.h \
    job_p.h \
    jobinterface.h \
    jobpointer.h \
    kdemacros.h \
    lambda.h \
    managedjobpointer.h \
    qobjectdecorator.h \
    queue.h \
    queueapi.h \
    queueing.h \
    queueinterface.h \
    queuepolicy.h \
    queuesignals.h \
    queuesignals_p.h \
    queuestream.h \
    resourcerestrictionpolicy.h \
    sequence.h \
    sequence_p.h \
    shuttingdownstate.h \
    state.h \
    suspendedstate.h \
    suspendingstate.h \
    thread.h \
    threadweaver.h \
    threadweaver_export.h \
    weaver.h \
    weaver_p.h \
    weaverimplstate.h \
    weaverinterface.h \
    workinghardstate.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ThreadWeaver.pri
