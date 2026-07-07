#include "malcolm.h"
#include <signal.h> // signal(), SIGINT
#include <sys/socket.h> // socket(), AF_INET, SOCK_RAW
#include <arpa/inet.h> // htons()
#include <stdio.h> // fprintf(), stderr
#include <unistd.h> // close()


// static int g_sig = 1;


// int ft_malcolm()
// {
// 	return (0);
// }


// static void signal_handler()
// {
// 	g_sig = 0;
// }


int main(int argc, char **argv)
{
	int sockfd;
	(void)argv;
	(void)argc;
	// if (!parse_input(argc, argv))
	// 	return (1);

	// signal(SIGINT, signal_handler);

	sockfd = socket(AF_INET, SOCK_RAW, htons(ETH_P_ARP));
	if (sockfd < 0) {
		fprintf(stderr, "Fuck this\n");
		return (1);
	}
	while (1) {
		recvfrom();
	}

	close(sockfd);

	return (0);
}
