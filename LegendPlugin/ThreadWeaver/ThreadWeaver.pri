INCLUDEPATH += $$PWD
SOURCES += \
    $$PWD/collection.cpp \
    $$PWD/collection_p.cpp \
     $$PWD/debuggingaids.cpp \
     $$PWD/dependency.cpp \
     $$PWD/dependencypolicy.cpp \
     $$PWD/destructedstate.cpp \
     $$PWD/exception.cpp \
     $$PWD/executewrapper.cpp \
     $$PWD/executor.cpp \
     $$PWD/iddecorator.cpp \
     $$PWD/inconstructionstate.cpp \
     $$PWD/job.cpp \
     $$PWD/job_p.cpp \
     $$PWD/qobjectdecorator.cpp \
     $$PWD/queue.cpp \
     $$PWD/queueapi.cpp \
     $$PWD/queuesignals.cpp \
     $$PWD/queuesignals_p.cpp \
     $$PWD/queuestream.cpp \
     $$PWD/resourcerestrictionpolicy.cpp \
     $$PWD/sequence.cpp \
     $$PWD/sequence_p.cpp \
     $$PWD/shuttingdownstate.cpp \
     $$PWD/state.cpp \
     $$PWD/suspendedstate.cpp \
     $$PWD/suspendingstate.cpp \
     $$PWD/thread.cpp \
     $$PWD/threadweaver.cpp \
     $$PWD/weaver.cpp \
     $$PWD/weaver_p.cpp \
     $$PWD/weaverimplstate.cpp \
     $$PWD/workinghardstate.cpp

HEADERS += \
     $$PWD/collection.h \
     $$PWD/collection_p.h \
     $$PWD/debuggingaids.h \
     $$PWD/dependency.h \
     $$PWD/dependencypolicy.h \
     $$PWD/destructedstate.h \
     $$PWD/exception.h \
     $$PWD/executewrapper_p.h \
     $$PWD/executor_p.h \
     $$PWD/iddecorator.h \
     $$PWD/inconstructionstate.h \
     $$PWD/job.h \
     $$PWD/job_p.h \
     $$PWD/jobinterface.h \
     $$PWD/jobpointer.h \
     $$PWD/kdemacros.h \
     $$PWD/lambda.h \
     $$PWD/managedjobpointer.h \
     $$PWD/qobjectdecorator.h \
     $$PWD/queue.h \
     $$PWD/queueapi.h \
     $$PWD/queueing.h \
     $$PWD/queueinterface.h \
     $$PWD/queuepolicy.h \
     $$PWD/queuesignals.h \
     $$PWD/queuesignals_p.h \
     $$PWD/queuestream.h \
     $$PWD/resourcerestrictionpolicy.h \
     $$PWD/sequence.h \
     $$PWD/sequence_p.h \
     $$PWD/shuttingdownstate.h \
     $$PWD/state.h \
     $$PWD/suspendedstate.h \
     $$PWD/suspendingstate.h \
     $$PWD/thread.h \
     $$PWD/threadweaver.h \
     $$PWD/threadweaver_export.h \
     $$PWD/weaver.h \
     $$PWD/weaver_p.h \
     $$PWD/weaverimplstate.h \
     $$PWD/weaverinterface.h \
     $$PWD/workinghardstate.h
SUBDIRS += \
    $$PWD/ThreadWeaver.pro
