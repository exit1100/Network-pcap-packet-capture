#include <stdio.h>
#include "icmp.h"

void dump_icmp_header(struct icmp_header *icmp_header){
    printf("---------------------------------------------------------\n");
    printf("[ICMP Packet]\n");
    printf("Type : %d, Code : %d\n", icmp_header->type, icmp_header->code);
}
