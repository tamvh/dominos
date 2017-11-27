TEMPLATE = app

QT += qml quick quickcontrols2 concurrent svg network websockets printsupport
CONFIG += link_pkgconfig

#Use this flag to disable qDebug to console
#DEFINES += QT_NO_DEBUG_OUTPUT

#App versioning
VERSION_MAJOR = 1
VERSION_MINOR = 6
VERSION_BUILD = 2

DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
       "VERSION_MINOR=$$VERSION_MINOR"\
       "VERSION_BUILD=$$VERSION_BUILD"

#Target version
DEFINES += APP_VER=\\\"$${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_BUILD}\\\"

CONFIG += c++11

DEFINES += REAL_VERSION

SOURCES += main.cpp \
    http/json.cpp \
    http/httptool.cpp \
    http/httpparams.cpp \
    http/httpbase.cpp \
    http/httpbase2.cpp \
    ../common/prntdataformat.cpp \
    ../common/configsetting.cpp \
    ../common/deviceclient.cpp \
    ../common/deviceclientservice.cpp \
    ../common/udpbrdcastclient.cpp \
    ../common/wscssclient.cpp \
    maincontroller.cpp \
    colorimageprovider.cpp \
    qqrencode.cpp \
    downloadfileman.cpp \
    billdetail.cpp \
    commonfunction.cpp \
    wsclient.cpp \
    qmldefine.cpp \
    androidos.cpp

RESOURCES += qml.qrc

#unix {
#  DESTDIR = /home/sonnk/qtbuild
#  OBJECTS_DIR = $${DESTDIR}/.obj
#  MOC_DIR = $${DESTDIR}/.moc
#  RCC_DIR = $${DESTDIR}/.rcc
#  UI_DIR = $${DESTDIR}/.ui
#  UI_HEADERS_DIR = $${DESTDIR}/.h
#  UI_SOURCES_DIR = $${DESTDIR}/.cpp
#}

linux-rpi3-g++ {
    QTPLUGIN += qtvirtualkeyboardplugin
    DEFINES += USE_VT_KB
    DEFINES += ALLOW_LOCAL_DOCK
    DEFINES += USE_SYSLOG
}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

include(qrencode-3.4.4/qrencode.pri)
INCLUDEPATH += $$PWD/qrencode-3.4.4
DEFINES += HAVE_CONFIG_H

HEADERS += \
    http/json.h \
    http/httptool.h \
    http/httpparams.h \
    http/httpbase.h \
    http/httpbase2.h \
    ../common/prntdataformat.h \
    ../common/configsetting.h \
    ../common/deviceclient.h \
    ../common/deviceclientservice.h \
    ../common/udpbrdcastclient.h \
    ../common/wscssclient.h \
    maincontroller.h \
    colorimageprovider.h \
    qqrencode.h \
    qqrencode_p.h \
    commonfunction.h \
    wsclient.h \
    downloadfileman.h \
    billdetail.h \
    qmldefine.h \
    androidos.h \
    androidos.h

android {
    QT += androidextras
}

RESOURCES += icons/icons.qrc
RC_FILE = VPOS.rc

DISTFILES += \
    fonts/UnisectVnu Black.ttf \
    fonts/UnisectVnu Bold.ttf \
    fonts/UnisectVnu Bold.ttf \
    fonts/UnisectVnu Black.ttf \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
