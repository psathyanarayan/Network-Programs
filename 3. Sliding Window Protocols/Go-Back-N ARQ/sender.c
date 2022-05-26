#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

// The channel's port
#define CHANNELPORT "4950"
// Our receiving buffer length
#define MAXBUFLEN   100
// Size of our frame
#define MAXMESGLEN  1
#define MYPORT "4951"


int main(void)
{
    int       sockfd;
    struct addrinfo hints, *servinfo, *p;
    int       rv;
    int       numbytes;
    struct    sockaddr_storage their_addr;
    char      buf[MAXBUFLEN];
    socklen_t addr_len;

        /*
         * COMMENT
         */
    memset(&hints, 0, sizeof hints);
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags    = AI_PASSIVE;

        // COMMENT -- What does the following function do?
        // COMMENT -- Why is the first parameter to getaddrinfo NULL?
    if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    /*
         *  COMMENT -- what does the following code do?
         */
    for(p = servinfo; p != NULL; p = p->ai_next)
        {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("listener: socket");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("listener: bind");
            continue;
        }

        break;
    } // END FOR

    if (p == NULL) {
        fprintf(stderr, "listener: failed to bind socket\n");
        return 2;
    }

    freeaddrinfo(servinfo);

    printf("server: waiting to recvfrom...\n");


      /* -----------------------------------------------------------------------
       *  MAIN LOOP
       *  Hint: hit ctrl-c to kill the server
       * -----------------------------------------------------------------------
       */
      while(1)
      {
    /*
         *  COMMENT
         */
    addr_len = sizeof their_addr;
    if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
        (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
        perror("recvfrom");
        exit(1);
    }

        // Let's print our received data.
    buf[numbytes] = '\0';
    printf("server: received... \"%s\"\n", buf);

        /*
         * Now that we've received a character (1-byte), do something ...
         * Hint:  checkout sendto
         */


       } // END WHILE -- the main loop

      //  -----------------------------------------------------------------------
      // Close the socket to the channel.
      close(sockfd);

      return 0;
}
