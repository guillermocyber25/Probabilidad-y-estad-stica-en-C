/*
** talker.c -- a datagram "client" demo
*/
/*
Beej's Guide to Network Programming
Using Internet Sockets
Brian “Beej Jorgensen” Hall
beej@beej.us
Version 3.0.15
July 3, 2012
Copyright © 2012 Brian “Beej Jorgensen” Hall
*/


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

//PUERTOS DE LOS SERVIDORES
#define SERVERPORT "7500" // the port client will be connecting to

//****
#define MAXBUFLEN 1000
#define MYPORT "7200"
void *get_in_addr(struct sockaddr *sa)
{
if (sa->sa_family == AF_INET) {
return &(((struct sockaddr_in*)sa)->sin_addr);
}
return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
//******
int main(int argc, char *argv[])
{

/***CODIGO MODIFICADO POR GUILLERMO ISLAS ARREOLA****/
argc = 3;
int tipo;
argv[1] = "localhoost";
printf("Ingrese el primer numero entero\n");
scanf("%s",argv[2]);
printf("Ingrese el segundo numero entero\n");
scanf("%s",argv[3]);
printf("Escoja la operacion a realizar\n");
printf("1-------- suma\n");
printf("2-------- resta\n");
printf("3-------- multiplicacion\n");
printf("4-------- Division\n");
scanf("%s",argv[4]);
printf("Los datos fueron enviados al servidor para realizar una operacion\n");
//sprintf(argv[4], "%d", tipo);
/******/

printf("%d\n",argc);
int sockfd;
struct addrinfo hints, *servinfo, *p;
int rv;
int numbytes;
//****
struct sockaddr_storage their_addr;
char buf[MAXBUFLEN];
socklen_t addr_len;
char s[INET6_ADDRSTRLEN];
//***

if (argc != 5) {
fprintf(stderr,"usage: talker localhoost message\n");
exit(1);
}
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_DGRAM;
if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0) {
fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
return 1;
}
// loop through all the results and make a socket
for(p = servinfo; p != NULL; p = p->ai_next) {
if ((sockfd = socket(p->ai_family, p->ai_socktype,
p->ai_protocol)) == -1) {
perror("talker: socket");
continue;
}
break;
}
if (p == NULL) {
fprintf(stderr, "talker: failed to bind socket\n");
return 2;
}
if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0,
p->ai_addr, p->ai_addrlen)) == -1) {
perror("talker: sendto");
exit(1);
}
if ((numbytes = sendto(sockfd, argv[3], strlen(argv[3]), 0,
p->ai_addr, p->ai_addrlen)) == -1) {
perror("talker: sendto");
exit(1);
}
/////////*********
if ((numbytes = sendto(sockfd, argv[4], strlen(argv[4]), 0,
p->ai_addr, p->ai_addrlen)) == -1) {
perror("talker: sendto");
exit(1);
}

printf("------>%s", argv[4]);//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
////*******
freeaddrinfo(servinfo);

printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
close(sockfd);

//**************************************
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
hints.ai_socktype = SOCK_DGRAM;
hints.ai_flags = AI_PASSIVE; // use my IP
if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
return 1;
}
// loop through all the results and bind to the first we can
for(p = servinfo; p != NULL; p = p->ai_next) {
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
}
if (p == NULL) {
fprintf(stderr, "listener: failed to bind socket\n");
return 2;
}
//freeaddrinfo(servinfo);
printf("listener: waiting to recvfrom...\n");
addr_len = sizeof their_addr;
if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
(struct sockaddr *)&their_addr, &addr_len)) == -1) {
perror("recvfrom");
exit(1);
}
printf("listener: got packet from %s\n",
inet_ntop(their_addr.ss_family,
get_in_addr((struct sockaddr *)&their_addr),
s, sizeof s));
printf("listener: packet is %d bytes long\n", numbytes);
buf[numbytes] = '\0';
//sprintf(buf, "%d", tipo);

            printf("El resultado de la operacion es \"%s\"\n", buf);
             
return 0;
}





