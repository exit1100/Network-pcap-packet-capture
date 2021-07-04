#ifndef TCP_H
#define TCP_H

#include <stdint.h>

struct tcp_header{
    uint16_t sport;
    uint16_t dport;
    uint32_t sequence;
    uint32_t acknowlegment;
    uint8_t unset:4;
    uint8_t tcp_len:4;
    uint8_t flag;
    uint8_t fin:1;
    uint8_t syn:1;
    uint8_t rst:1;
    uint8_t psh:1;
    uint8_t ack:1;
    uint8_t urg:1;
    uint8_t ecn:1;
    uint8_t cwr:1;
    uint8_t win;
    uint16_t check;
    uint16_t urp;
} __attribute__((__packed__));

void dump_tcp_header(void *ip_header);

#endif // TCP_H
