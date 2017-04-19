#include "header.h"


int main(int argc, char* argv[])
{
/* 
** argv[1] = own node number
** argv[2] = client dst IP
** argv[3] = client dst PORT
** argv[4] = server IP
** argv[5] = server PORT
*/

if (argc < 6) {
	printf("Gimme more command line args please.\n");
}
else{
	int Sfd, Cfd, node;
	node = argv[1];
	Sfd = Server(argv[4],argv[5]);
	Cfd = Client(argv[2],argv[3]);

	//start ncurses	
	initscr();
	
	char buff[80] = {};	
}

return 1;
}
