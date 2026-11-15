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

t_packet build_packet(t_malcolm *ctx)
{
	t_packet packet;

	packet.ethernet = build_ethernet(ctx);
	packet.arp = build_arp(ctx);

	return (packet);
}

int malcolm(t_malcolm *ctx)
{
	t_packet packet;

	if (setup_socket(ctx))
		return (1);

	while (1) {
		packet = build_packet(ctx);
	}

	return (0);
}
