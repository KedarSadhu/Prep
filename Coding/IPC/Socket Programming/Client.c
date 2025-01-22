#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 9000
#define SERVER_IP "127.0.0.1"
#define BACKLOG     10

int main()
{
    int sockfd = 0;  //listen on sockfd
    
    int sent_bytes = 0;
    int recv_bytes = 0;

    FILE *fp =NULL;

    int icounter =0;
    char ch;

    char recvbuf[1024] = {0};

    int sin_size = 0;
    struct sockaddr_in their_addr;

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) 
    {
        perror("socket");   
        exit(1);
    }

    their_addr.sin_family = AF_INET;    
    their_addr.sin_port = htons(SERVER_PORT);   // host to network short
    their_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    
    memset(&(their_addr.sin_zero),0, 8); // zero the rest of the struct
    
    if (connect(sockfd, (struct sockaddr *)&their_addr,sizeof(struct sockaddr)) == -1) 
    {
        perror("connect");
        exit(1);    
    }
    
    printf("Connection done with server ... \n");
    
    printf("Sending Request to Server\n");
    if((sent_bytes = send(sockfd,"mati.txt",9,0) ) == -1) 
    {   
        perror("send");
        exit(1);
    }

    if((recv_bytes = recv(sockfd,recvbuf,(int)sizeof(recvbuf),0) ) == -1) 
    {   
        perror("recv");
        exit(1);
    }  

    printf("Recived Response from server\n");

    fp = fopen("mati.txt","w");
    if(fp == NULL)
        {
            printf("File open failed");
            exit(1);
        }
    

    for(icounter = 0 ; icounter<recv_bytes ;icounter ++)
        fputc(recvbuf[icounter],fp);

    fclose(fp);
    printf("File Downloading done \n");
    
    close(sockfd);
    printf("Closed Connection with Server\n");


    return 0;   
}