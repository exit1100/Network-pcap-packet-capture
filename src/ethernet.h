#ifndef ETHERNET_H
#define ETHERNET_H

#include <stdint.h>

struct ethernet_header{
    uint8_t dhost[6];
    uint8_t shost[6];
    uint16_t type;
} __attribute__ ((__packed__));

short dump_ethernet_header(struct ethernet_header *ethernet_header);

#endif // ETHERNET_H
