#include "malcolm.h"

#include <sys/socket.h>

int setup_socket(t_malcolm *ctx)
{
	int fd;

	fd = socket(AF_PACKET, SOCK_RAW, htons(0x0806));
	if (fd < 0)
		return (1);

	ctx->sockfd = fd;
	return (0);
}
