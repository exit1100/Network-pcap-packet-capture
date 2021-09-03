#include <stdio.h>
#include "ethernet.h"


short dump_ethernet_header(struct ethernet_header *ethernet_header){
    unsigned char *da = ethernet_header->dhost;
    unsigned char *sa = ethernet_header->shost;
    unsigned short type = ethernet_header->type;
    printf("---------------------------------------------------------\n");
    printf("[Ethernet Packet]\n");
    printf("Destination MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n", da[0], da[1], da[2], da[3], da[4], da[5]);
    printf("Source MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n", sa[0], sa[1], sa[2], sa[3], sa[4], sa[5]);
    printf("Ethernet Type : 0x%04x\n", htons(type));
    return type;
}
