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
	printf("hello server \r\n");

	int Server_Fd;
	int Ret;
	int Connet;

	Server_Fd = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in Server_Addr;
	
	bzero(&Server_Addr,sizeof(Server_Addr));
	Server_Addr.sin_family=AF_INET;
	Server_Addr.sin_port = SOCKET_PORT;
	Server_Addr.sin_addr.s_addr=htonl(INADDR_ANY);

	Ret = bind(Server_Fd, (struct sockaddr *)&Server_Addr, sizeof(Server_Addr));
	if (Ret <0)
	{
		printf("bind wrong \r\n");
		return -1;
	}

	Ret = listen(Server_Fd, 5);
	if (Ret <0)
	{	
		printf("listen wrong\r\n");
		return -1;	
	}

	struct sockaddr_in Client_Addr;
	int length = sizeof(Client_Addr);


	char Buffer[1024];
	int Readlength = 0;

	printf("COME IN  while\r\n");
	
	Connet = accept(Server_Fd,(struct sockaddr *)&Client_Addr, &length);
	if (Connet < 0)
	{
		printf("connet wrong\r\n");
		return -1;
	}
	
	while(1)
	{	
		memset(Buffer,0,sizeof(Buffer));
		Readlength = recv(Connet,Buffer,sizeof(Buffer),0);
		if ((Buffer[0] == 'q') || (Buffer[0] == 'Q'))
		{
			printf("Good bye\r\n");
			break;
		}
		
		printf("%s\r\n",Buffer);
	}

	close(Connet);
	close(Server_Fd);

	return 0;
}

