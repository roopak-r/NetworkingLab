#include<stdio.h>
#include<arpa/inet.h>
#define port 4000
void main()
{
struct sockaddr_in serveraddr;
int clisocket,size;
char buffer[100];
clisocket=socket(AF_INET,SOCK_DGRAM,0);
if(clisocket>0)
printf("\nClient socket created");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(port);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
while(1)
{
printf("\nTo server:");
fgets(buffer,sizeof(buffer),stdin);
sendto(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(strcmp(buffer,"bye\n")==0)
break;
size=sizeof(serveraddr);
recvfrom(clisocket,buffer,sizeof(buffer),0,(struct sockaddr*)&serveraddr,&size);
printf("\tFrom server:%s",buffer);
}
close(clisocket);
}

