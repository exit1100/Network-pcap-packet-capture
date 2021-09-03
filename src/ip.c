#include <stdio.h>
#include "ip.h"

int dump_ip_header(struct ip_header *ip_header){
    unsigned char *sip = ip_header->sip;
    unsigned char *dip = ip_header->dip;
    unsigned int proto = ip_header->proto;
    printf("---------------------------------------------------------\n");
    printf("[IP Packet]\n");
    //printf("%d, %d\n",ip_header->ip_v, ip_header->ip_len);
    printf("Source IP Address : %d.%d.%d.%d\n",sip[0], sip[1], sip[2], sip[3]);
    printf("Destionation IP Address : %d.%d.%d.%d\n",dip[0], dip[1], dip[2], dip[3]);
    printf("Protocol : %d\n", proto);
    return proto;
}
