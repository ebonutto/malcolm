#include "malcolm.h"

#include <unistd.h> // sleep()

int malcolm(t_malcolm *ctx)
{
	t_packet packet;
	t_target me;

	if (setup_socket(ctx))
		return (1);

	while (1) {
		me.ip = ctx->args.dest.ip;
		packet = build_packet(ctx, &me, &ctx->args.src);

		me.ip = ctx->args.src.ip;
		packet = build_packet(ctx, &me, &ctx->args.dest);

		sleep(2);
	}

	return (0);
}
