#include "malcolm.h"

int malcolm(t_malcolm *ctx)
{
	t_packet packet;
	t_target me;

	if (setup_socket(ctx))
		return (1);

	while (1) {
		packet = build_packet(ctx, &me, &ctx->args.src);
		packet = build_packet(ctx, &me, &ctx->args.dest);
	}

	return (0);
}
