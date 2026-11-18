#include "malcolm.h"

#include <sys/socket.h>

int setup_socket(t_malcolm *ctx)
{
	int fd;

	fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
	if (fd < 0)
		return (1);

	ctx->sockfd = fd;

	return (0);
}

int malcolm(t_malcolm *ctx)
{
	if (setup_socket(ctx))
		return (1);

	while (1) {
		build_packet()
	}

	return (0);
}
