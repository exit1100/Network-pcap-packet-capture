#include <stdio.h>
#include "udp.h"

void dump_udp_header(struct udp_header *udp_header){
    int i, cut_size, data_len;
    char data[1024];
    unsigned char *data_ptr;

    data_len = ntohs(udp_header->len) - sizeof(struct udp_header);
    data_ptr = (unsigned char *)udp_header + sizeof(struct udp_header);

    cut_size = (data_len > 16)?16:data_len;
    for(i = 0; i < cut_size; i += 1) {
        data[i] = (isprint(data_ptr[i]))?data_ptr[i]:'.';
    }
    data[cut_size] = '\0';

    printf("---------------------------------------------------------\n");
    printf("[UDP Packet]\n");
    printf("%d -> %d, len : %d\n",ntohs(udp_header->sport), ntohs(udp_header->dport),ntohs(udp_header->len));
    printf("---------------------------------------------------------\n");
    printf("Payload : %s\n",data);
}
