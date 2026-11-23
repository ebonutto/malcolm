// #include "malcolm.h"

// #include <sys/socket.h> // sendto()

// #include <if/ether.h>

// int send_packet(t_malcolm *ctx, t_target *dest, t_packet *packet)
// {
// 	struct sockaddr_ll addr;

// 	memset(&addr, 0, sizeof(addr));
// 	addr.sll_family = AF_PACKET;
// 	addr.sll_ifindex = ;
// 	addr.sll_halen = ETH_ALEN;
// 	memcpy(addr.sll_addr, dest->mac, ETH_ALEN);

// 	if (sendto(ctx->sockfd, packet, sizeof(*packet), 0, ) < 0) {

// 	}
// 	return (0);
// }
