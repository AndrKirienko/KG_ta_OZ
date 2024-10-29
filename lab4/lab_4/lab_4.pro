QT += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = lab_4
TEMPLATE = app

SOURCES += main.cpp \
           explosionsimulation.cpp

HEADERS  += explosionsimulation.h

# Додайте наступний рядок для використання GLU
LIBS += -lglu32 -lopengl32
