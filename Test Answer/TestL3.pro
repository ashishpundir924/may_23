TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        animatedassets.cpp \
        dragon.cpp \
        main.cpp \
        tree.cpp


INCLUDEPATH += "C:/Users/Lab/Documents/Test 10th May/SFML-2.5.1/include"

LIBS += -L"C:/Users/Lab/Documents/Test 10th May/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}


HEADERS += \
    animatedassets.h \
    dragon.h \
    tree.h
