#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 40
#define NPACK 3
#define PORT 79
#define SRV_IP "127.0.0.1"

const char * flags[] = {
    "aLgoRithMiC_trAding",
    "qUantaTivE_anaLysIS",
    "TecHnicaL_indicaT0rs",
};

void diep(char *s) {
    perror(s);
    exit(1);
}

// int main(void) {
//     struct sockaddr_in si_other;
//     int s, i, slen=sizeof(si_other);
//     char buf[BUFLEN];

//     if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
//         diep("socket");

//     memset((char *) &si_other, 0, sizeof(si_other));
//     si_other.sin_family = AF_INET;
//     si_other.sin_port = htons(PORT);
//     if (inet_aton(SRV_IP, &si_other.sin_addr)==0) {
//         fprintf(stderr, "inet_aton() failed\n");
//         exit(1);
//     }

//     for (i=0; i<NPACK; i++) {
//         printf("Sending packet %d: %s\n", i, flags[i]);
//         sprintf(buf, "SA_FLAG{%s}\n", flags[i]);
//     if (sendto(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, slen)==-1)
//         diep("sendto()");
//     }

//     close(s);
//     return 0;
// }

// receive packet:
int main(void) {
    struct sockaddr_in si_me, si_other;
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];

    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        diep("socket");
        memset((char *) &si_me, 0, sizeof(si_me));
        si_me.sin_family = AF_INET;
        si_me.sin_port = htons(PORT);
        si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(s, (struct sockaddr *)&si_me, sizeof(si_me))==-1)
        diep("bind");

    for (i=0; i<NPACK; i++) {
        if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)==-1)
            diep("recvfrom()");
        printf("Received packet from %s:%d\nData: %s\n\n", 
                inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
    }   
    close(s);
    return 0;
}