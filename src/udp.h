#ifndef UDP_H
#define UDP_H

#include <stdint.h>

struct udp_header{
    uint16_t sport;
    uint16_t dport;
    uint16_t len;
    uint16_t check;
}__attribute__ ((__packed__));

void dump_udp_header(struct udp_header *udp_header);

#endif // UDP_H
