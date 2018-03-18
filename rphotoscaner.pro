QT += core gui widgets

TARGET = lcv
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += precompile_header c++14
PRECOMPILED_HEADER = pch.h

include(./opencv.pri)

SOURCES += \
    main.cpp \
    main_view.cpp \
    scene.cpp \
    scene_view.cpp \
    node.cpp \
    nodes.cpp \
    scene_img.cpp \
    img_transformator.cpp

HEADERS += \
    main_view.h \
    pch.h \
    scene.h \
    scene_view.h \
    node.h \
    nodes.h \
    scene_img.h \
    asm_open_cv.h \
    img_transformator.h

FORMS += \
    main_view.ui
