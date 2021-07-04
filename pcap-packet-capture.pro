TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap

SOURCES += main.c \
    arp.c \
    ethernet.c \
    icmp.c \
    ip.c \
    tcp.c \
    udp.c


HEADERS += \
    arp.h \
    ethernet.h \
    icmp.h \
    ip.h \
    tcp.h \
    udp.h
