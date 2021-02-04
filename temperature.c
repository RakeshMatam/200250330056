#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>
#include <time.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

void func(int sockfd) 
{
    int buff[MAX]; 
    int i, 
    
    for(i=30;i<=300;i++)
    {
        int k = 0;
        k = rand()%100 + buff[i];
    }
    write(sockfd, buff, sizeof(buff)); 
    read(sockfd, buff, sizeof(buff)); 
        
} 

int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
    

    sockfd = socket(AF_INET, SOCK_STREAM, 0);  // socket creation

    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0);
    } 
    else
        printf("Socket successfully created..\n"); 

    // assign IP, PORT 

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT); 

  

    // connect the client socket to server socket 

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
    func(sockfd); 
    // close the socket 
    close(sockfd); // close the socket
} 