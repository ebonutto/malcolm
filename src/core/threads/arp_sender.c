#include "malcolm.h"

#include <stddef.h> // NULL

void *arp_sender(void *arg)
{
	t_malcolm *ctx;
	t_packet packet;
	t_target me;

	ctx = (t_malcolm *)arg;
	while (1) {
		me.ip = ctx->args.dest.ip;
		packet = build_packet(ctx, &me, &ctx->args.src);
		send_packet(ctx, &packet);

		me.ip = ctx->args.src.ip;
		packet = build_packet(ctx, &me, &ctx->args.dest);
		send_packet(ctx, &packet);

		sleep(2);
	}
	return (NULL);
}
