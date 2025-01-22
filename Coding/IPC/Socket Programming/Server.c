#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
#include<memory.h>
#include<stdlib.h>
#include <unistd.h>

#define SERVER_PORT 9000
#define BACKLOG     10


int main()
{
    int sockfd =0;  //listen on sockfd
    int new_fd =0;   //new connection on newfd

    FILE *fp = NULL;

    int sin_size=0;
    int recv_bytes =0;
    int sent_bytes=0;

    int icounter =0;
    char ch;

    char recvbuf[16] = {0};
    char sendbuf[1024] = {0};
    
    /*
        IPv4 socket addresses: struct sockaddr_in
        An IPv4 socket address is stored in a sockaddr_in structure, defined in <netinet/in.h>
        struct in_addr  // IPv4 4-byte address 
        { 
            in_addr_t s_addr; // Unsigned 32-bit integer 
        };
        struct sockaddr_in  // IPv4 socket address 
        {  
            sa_family_t sin_family; // Address family (AF_INET) 
            in_port_t sin_port; // Port number 
            struct in_addr sin_addr; // IPv4 address 
            unsigned char __pad[X]; // Pad to size of 'sockaddr' structure (16 bytes) 
        };
    
    */

    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;

    my_addr.sin_family = AF_INET;          
    my_addr.sin_port = htons(SERVER_PORT);
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(&(my_addr.sin_zero),0,8);
    
    /*
        
        domain is AF_INET (IPV4) or AF_INET6(IPV6), 
        type is SOCK_STREAM (connection oriented - safe -tcp/ip) or SOCK_DGRAM (connection less - udp), 
        protocol can be set to 0 to choose the proper protocol for the given type.
        int socket(int domain, int type, int protocol);
    */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("socket");   
        exit(1);
    }



    /*int bind(int sockfd, struct sockaddr *my_addr, int addrlen);  ME MAZYA ADDRESS LA BIND KARUN GHETLA*/
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))== -1) 
    {
        perror("bind");
        exit(1);
    }

    printf("Bind done \n");

    if (listen(sockfd, BACKLOG) == -1) 
    {   
        perror("listen");
        exit(1);
    }
    
    printf("Listen done \n");

    sin_size = sizeof(struct sockaddr_in);
    /*ALELA CONNECTION ACCEPT KELA*/
    if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,&sin_size)) == -1) 
        {
            perror("accept");   
            exit(1);
        }

    printf("server: got connection from %s\n",inet_ntoa(their_addr.sin_addr));
    
    if((recv_bytes = recv(new_fd,recvbuf,(int)sizeof(recvbuf),0) ) == -1) 
    {   
        perror("recv");
        exit(1);
    }  

    printf("Request Recived from Client\n");
//request validation
//error codes define

    printf("Serving the request ... \n");
    fp = fopen(recvbuf,"r");
    if(fp == NULL)
        {
            printf("File open failed");
            exit(1);
        }
    
        while((ch = fgetc(fp)) != EOF)
      {
        sendbuf[icounter]=ch;
        icounter++;
      }

    sendbuf[icounter]='\0';

    if((sent_bytes = send(new_fd,sendbuf,strlen(sendbuf),0) ) == -1) 
    {   
        perror("send");
        exit(1);
    }
    printf("Request Served \n");
    printf("bytes sent to client :: %d\n",sent_bytes);
    close(new_fd);
    return 0;
}