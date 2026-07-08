#include "malcolm.h"

#include <stdio.h>	// fprintf(), stderr

static void parse_flag(int *flags, char *arg) //! const arg
{
	if (strcmp("-h", arg) == 0 || strcmp("--help", arg) == 0)
		*flags |= FLAG_HELP;
	if (strcmp("-v", arg) == 0 || strcmp("--verbose", arg) == 0)
		*flags |= FLAG_VERBOSE;
}

int parse_args(t_malcolm_ctx *ctx, int argc, char **argv)
{
	int i;

	ctx->progname = argv[0];
	i = 1;
	while (i < argc) {
		if (argv[i][0] == '-')
			parse_flag(ctx->flags, argv[i]);
		else
			parse_address();
	}

	return (0);
}
