/*****************************************************************************/
/*                                                                           */
/* This routine establishes a passive open connection.  That is, it creates  */
/* a socket, and passively wait for a connection.  Once a connection request */
/* has been received, it echoes "connected" on the screen, and return        */
/* a file descriptor to be used to communicate with the remote machine.      */
/* Make sure that you change the machine name from "vulcan" to that you    */
/* will be running your process on. Also, change the port number to          */
/* a suitable port number as indicated in the project writeup.               */
/*                                                                           */
/*****************************************************************************/
#include "header.h"

int Server(char * IP, char * PORT)
{
	printf("starting\n");
	struct sockaddr_in myaddr, otheraddr;
	//struct hostent *myname;

	int s, fd, otherlength;
	FILE *fdopen(), *fp;
	char ch;
	//*hostname = "vulcan", 
	//int hostnamelength;

	pid_t pid;

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) ReportError ("socket");
	//myname = gethostbyname(hostname);
	//fprintf("%s", myname);
	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family  = AF_INET;
	myaddr.sin_port = htons(atoi(PORT));
	myaddr.sin_addr.s_addr = inet_addr(IP);
	//bcopy(myname->h_addr_list[0], &myaddr.sin_addr, myname->h_length);	
	printf("binding\n");
	bind(s, (struct sockaddr *)&myaddr, sizeof(myaddr));
	printf("binded\n");
	listen(s, 1);
	otherlength = sizeof(otheraddr);	
	printf("accepting\n");
	fd = accept(s, (struct sockaddr *)&otheraddr, &otherlength);

	fprintf(stdout, "Connected\n");
	return(fd);
}
