/*****************************************************************************/
/*                                                                           */
/* This routine establishes an active open connection.  That is, it creates  */
/* a socket, and connects using it to a remote machine. The routine returns  */
/* a file descriptor to be used to communicate with the remote machine.      */
/* Make sure that you change the machine name from "vulcan" to that of   */
/* the remote machine.  Also, change the port number to a suitable port      */
/* number as indicated in the project writeup.                               */
/*                                                                           */
/*****************************************************************************/
#include "header.h"

//Read packet

	//if sourceNum == localNum, packet has gone in full loop
	//if destNum == localNum, packet is at its destination
	//else forward packet to next computer

//Input "server#, address of next server, port"
int main(int argc, char* argv[]) {
	struct hostent *outhost, inhost;
	struct sockaddr_in outaddr, inaddr;

	printf("starting\n");
	int sIn, sOut;
	int n;
	int code;
	FILE *fp;
	char *otherhostname="vulcan", ch, thishostname[256], buff[88];

	bzero(&outaddr, sizeof(outaddr));
	bzero(&inaddr, sizeof(inaddr));

	inaddr.sin_family = AF_INET;
	inaddr.sin_port = htons(atoi(argv[3]));
	inaddr.sin_addr.s_addr = INADDR_ANY;
	printf("creating in socket\n");
	sIn = socket(AF_INET, SOCK_STREAM, 0);
	printf("socket in created\n");

	//If root server
	if (atoi(argv[1]) == 1) {
		//Wait until enter is pressed
		printf("Press enter after last server is started...");
		getchar();
	}

	outaddr.sin_family = AF_INET;
	outaddr.sin_port = htons(atoi(argv[3]));
	outaddr.sin_addr.s_addr = inet_addr(argv[2]);
	printf("creating out socket\n");
	sOut = socket(AF_INET, SOCK_STREAM, 0);
	printf("socket out created\n");
	//otherhost = gethostbyname(otherhostname);
	//bcopy(otherhost->h_addr_list[0], &outaddr.sin_addr, otherhost->h_length);
	printf("binding\n");
	n = bind(sIn, (struct sockaddr *)&inaddr, sizeof(inaddr));
	printf("bound\n");
	printf("listening\n");
	listen(sIn, 5);
	printf("listened\n");
	printf("connecting\n");
	n = connect(sOut, (struct sockaddr *)&outaddr, sizeof(outaddr));
	printf("connected\n");

	for(;;) {
		//Revieve data into buff
		n = recv(sIn, &buff, 88, 0);

		//If we have all 88 bytes of data
		if (n > 0) {
			//If destination == local, print value
			if (buff[4] == atoi(argv[1])) {
				//Print message
			//If source == local, print error 'cause its gone around the loop
			} else if (buff[5] == atoi(argv[1])) {
				//Print "No server with that name"
			//Forward packet otherwise
			} else {
				n = send(sOut, &buff, 88, 0);
			}
		}
	}


}