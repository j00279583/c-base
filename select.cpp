#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	char Key;
	int Ret;
	int KeyBoardFd;
	fd_set Readfds;
	int TimeoutCount = 0;
	
	struct timeval timeout;
	char *path="/dev/tty";

	KeyBoardFd = open(path, O_RDONLY|O_NONBLOCK);
	if (KeyBoardFd <0)
	{
		printf("open keyboard failed\r\n");
		return -1;
	}
	
	while(1)
	{	
		
		timeout.tv_sec=5;
		timeout.tv_usec=0;
		
		FD_ZERO(&Readfds);
		FD_SET(KeyBoardFd,&Readfds);

		Ret = select(KeyBoardFd+1,&Readfds,NULL,NULL,&timeout);
		if(Ret < 0)
		{
			printf("seletc wrong \r\n");
		}

		Ret = FD_ISSET(KeyBoardFd,&Readfds);
		if (Ret >0)
		{
			read(KeyBoardFd,&Key,1);
			if (('q' == Key )|| ('Q' == Key))
			{
				printf("good bye\r\n");	
				break;
			}
			else if (Key != '\n')
			{
				printf("you put char is %c\r\n",Key);
			}
		}
		else
		{	
			TimeoutCount++;
			printf("Timeout for nothing input,time out %d .\r\n",TimeoutCount);
		}
		
	}
	
	return 0;
}

