#! [0]
TEMPLATE    = lib
CONFIG     += plugin
HEADERS     = simplestyle.h \
              simplestyleplugin.h
SOURCES     = simplestyle.cpp \
              simplestyleplugin.cpp
TARGET      = simplestyleplugin
#! [0]
win32 {
    debug:DESTDIR = ../debug/styles/
    release:DESTDIR = ../release/styles/
} else {
    DESTDIR = ../styles/
}

# install
target.path = $$[QT_INSTALL_EXAMPLES]/tools/styleplugin/styles
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS plugin.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/tools/styleplugin/plugin
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)

symbian:TARGET.EPOCALLOWDLLDATA = 1
