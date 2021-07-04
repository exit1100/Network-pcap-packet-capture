#ifndef ICMP_H
#define ICMP_H

#include <stdint.h>

struct icmp_header{
    uint8_t type;
    uint8_t code;
    uint16_t check;
    uint16_t id;
    uint16_t seq;

}__attribute__((__packed__));

void dump_icmp_header(struct icmp_header *icmp_header);

#endif // ICMP_H
