#include <stdio.h>
#include "arp.h"

void dump_arp_header(struct arp_header *arp_header){
    unsigned char *sha = arp_header->sha;
    unsigned char *sip = arp_header->sip;
    unsigned char *dha = arp_header->dha;
    unsigned char *dip = arp_header->dip;
    int opcode = arp_header->op/256;    //request 01 00 reply 02 00
    printf("---------------------------------------------------------\n");
    if(opcode == 1) printf("[ARP Packet : Request]\n");
    else if(opcode == 2) printf("[ARP Packet : Reply]\n");
    printf("Source MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n",sha[0], sha[1], sha[2], sha[3], sha[4], sha[5]);
    printf("Source IP Address : %d.%d.%d.%d\n",sip[0], sip[1], sip[2], sip[3]);
    printf("Target MAC Address : %02x:%02x:%02x:%02x:%02x:%02x\n",dha[0], dha[1], dha[2], dha[3], dha[4], dha[5]);
    printf("Target IP Address : %d.%d.%d.%d\n",dip[0], dip[1], dip[2], dip[3]);

}

