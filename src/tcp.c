#include <stdio.h>
#include "tcp.h"
#include "ip.h"
void dump_tcp_header(void *ip){
    char data[1024];
    int i, cut_size;
    struct tcp_header *tcp_header;
    struct ip_header *ip_header = (struct ip_header *)ip;
    int ip_len, tcp_len, data_len;
    unsigned char *data_ptr;

    ip_len = ip_header->ip_len << 2; // *=4
    tcp_header = (struct tcp_header *)((char *)ip_header + ip_len);
    tcp_len = tcp_header->tcp_len << 2; // *=4

    data_len = ntohs(ip_header->total_len) - tcp_len - ip_len;
    data_ptr = (unsigned char*)tcp_header + tcp_len;

    cut_size = (data_len > 16)?16:data_len;
    for(i=0; i < cut_size; i++) data[i] = (isprint(data_ptr[i]))?data_ptr[i]:'.';
    data[cut_size] = '\0';

    printf("---------------------------------------------------------\n");
    printf("[TCP Packet]\n");
    //printf("big : %d, little : %d\n", ip_header->total_len, ntohs(ip_header->total_len));
    printf("Source Port : %d\n", tcp_header->sport);
    printf("Destionation Port : %d\n", tcp_header->dport);
    printf("---------------------------------------------------------\n");
    printf("Payload : %s\n",data);
}
