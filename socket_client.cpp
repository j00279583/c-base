#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define SOCKET_PORT 7889

int main ()
{
	printf("hello client \r\n");

	int Client_Fd;
	int connetFd;

	Client_Fd = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in Server_Addr;
	
	Server_Addr.sin_family=AF_INET;
	Server_Addr.sin_port = SOCKET_PORT;
	Server_Addr.sin_addr.s_addr= inet_addr("127.0.0.1");
	
	connetFd = connect(Client_Fd,(struct sockaddr *) &Server_Addr, sizeof(Server_Addr));
	if(connetFd <0)
	{
		printf("connect error\r\n");
	}
	
	while(1)
	{	
		char Buffer[1024];
		gets(Buffer);

		printf("send to server begin:\r\n");
		
		send(Client_Fd,Buffer,strlen(Buffer)+1,0);

		printf("send to server over\r\n");
	}

	return 0;
}

