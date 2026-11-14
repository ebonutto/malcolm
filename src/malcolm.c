#include "malcolm.h"

#include <sys/socket.h>

int setup_socket(t_malcolm *ctx)
{
	int fd;

	fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));

	ctx->sockfd = fd;

	return (0);
}

int malcolm(t_malcolm *ctx)
{
	setup_socket();
}
