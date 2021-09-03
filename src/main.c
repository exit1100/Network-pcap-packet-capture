#include <pcap.h>
#include <stdio.h>
#include "ethernet.c"
#include "arp.c"
#include "ip.c"
#include "tcp.c"
#include "icmp.c"
#include "udp.c"

void usage() {
    printf("syntax: pcap-test <interface>\n");
    printf("sample: pcap-test wlan0\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage();
        return 0;
    }
    char * dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t* pcap = pcap_open_live(dev , BUFSIZ, 1, 1000, errbuf);
    if (pcap == NULL) {
        fprintf(stderr, "pcap_open_live(%s) return null - %s\n", dev, errbuf);
        return -1;
    }

    while (1) {
        struct pcap_pkthdr* header;
        struct ip_header *ip;
        const u_char* packet;
        void * next_header_ptr;

        int res = pcap_next_ex(pcap, &header, &packet);
        if (res == 0) continue;
        if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK) {
            printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(pcap));
            break;
        }
        printf("%u bytes captured\n", header->caplen);

        short L3 = htons(dump_ethernet_header((struct ethernet_header *)packet));
        if(L3==2048){   //2048 == 0x0800 -> IP Packet
            packet += 14;
            int proto = dump_ip_header((struct ip_header *)packet);
            if(proto == 1){ //ICMP Packet
                ip = (struct ip *)packet;
                next_header_ptr = ((char*)ip) + (ip->ip_len << 2);
                dump_icmp_header((struct icmp_header *)next_header_ptr);
            } else if(proto == 6){ //TCP Packet
                dump_tcp_header((void *)packet);
            } else if(proto == 17){ //UDP Packet
                ip = (struct ip *)packet;
                next_header_ptr = ((char*)ip) + (ip->ip_len << 2);
                dump_udp_header((struct udp_header *)next_header_ptr);
            }
        } else if(L3==2054){  //2054 == 0x0806 -> ARP Packet
            packet += 14;
            dump_arp_header((struct arp_header *)packet);
        }
        printf("\n\n");
    }

    pcap_close(pcap);
}
