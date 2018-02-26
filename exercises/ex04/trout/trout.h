#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>

#define BUFSIZE 1500

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

#define max(a,b) ((a) > (b) ? (a) : (b))

/* the following are prototypes for the Stevens utilities in util.c */

void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	    const struct sockaddr *sa, socklen_t salen);

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

socklen_t salen;                    /* length of a socket address */

/* other global variables */

int seq;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];

int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

// Sockaddr *sasend;    /* socket addresses for various purposes */
// Sockaddr *sarecv;
// Sockaddr *salast;
// Sockaddr *sabind;

// socklen_t salen;                    /* length of a socket address */
int datalen;        /* length of the data in a datagram */
int max_ttl;

u_short sport;                      /* source UDP port # */

                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];