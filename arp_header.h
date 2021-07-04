#ifndef ARP_HEADER_H
#define ARP_HEADER_H
#define ARP_REQUEST 1
#define ARP_REPLY 2
#include <stdint.h>

struct arp_hedaer{
    uint16_t h_type;
    uint16_t p_type;
    uint8_t h_size;
    uint8_t p_size;
    uint16_t op;
    uint8_t sha[6];
    uint8_t sip[4];
    uint8_t tha[6];
    uint8_t tip[4];
} __attribute__ ((__packed__));

void dump_arp_header(struct arp_header *arp_header);

#endif // ARP_HEADER_H
