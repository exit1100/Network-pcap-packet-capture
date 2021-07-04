#ifndef IP_H
#define IP_H

#include<stdint.h>

struct ip_header{
    uint8_t ip_len:4;
    uint8_t ip_v:4;     // 4(version)5(ip_len)
    uint8_t tos;
    uint16_t total_len;
    uint16_t id;
    uint8_t frag_offset:5;
    uint8_t more_fragment:1;
    uint8_t dont_fragment:1;
    uint8_t reserved_zero:1;
    uint8_t frag_offset2;
    uint8_t ttl;
    uint8_t proto;
    uint16_t check;
    uint8_t sip[4];
    uint8_t dip[4];
} __attribute__ ((__packed__));

int dump_ip_header(struct ip_header *ip_header);

#endif // IP_H
