/*
** listener.c -- a datagram sockets "server" demo
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

//********
#define SERVERPORT "7500"
//******

#define MYPORT "7500"
// the port users will be connecting to
#define MAXBUFLEN 100
// get sockaddr, IPv4 or IPv6:
int suma(int , int);
void *get_in_addr(struct sockaddr *sa)
{
if (sa->sa_family == AF_INET) {
return &(((struct sockaddr_in*)sa)->sin_addr);
}
return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main(void)
{
int sockfd, new_fd;
struct addrinfo hints, *servinfo, *p;
int rv;
int numbytes;
struct sockaddr_storage their_addr;
char buf[MAXBUFLEN];
socklen_t addr_len;
char s[INET6_ADDRSTRLEN];



//codigo modificado por Guillermo Islas Arreola
int num1, num2, argc = 3;//variables para guardar los numeros enteros que manda el cliente
char *argv[3];
argv[1] = "localhost";
//**********************************

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
freeaddrinfo(servinfo);
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
printf("listener: packet contains \"%s\"\n", buf);
num1 = atoi(buf);

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
printf("listener: packet contains \"%s\"\n", buf);
num2 = atoi(buf);
printf("\n");
printf("La suma de los numeros %d y %d = %d\n",num1, num2, suma(num1, num2));

//*****
sprintf(argv[2], "%d", suma(num1, num2));
printf("PRUEBA%s\n",argv[2]);
//****

close(sockfd);

////codigo de prueba para que el servidor envie informacion
if (argc != 3) {
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

freeaddrinfo(servinfo);

printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
close(sockfd);


return 0;
}

int suma(int num1, int num2){

int suma;
suma = num1 + num2;
return suma;
}






