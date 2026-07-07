#include "malcolm.h"

#include <stdio.h>	// fprintf(), stderr

int parse_args(t_malcolm_ctx *ctx, int argc, char **argv)
{
	if (argc != 5) {
		fprintf(stderr, "%s: usage error: invalid number of arguments\n", argv[0]);
		fprintf(stderr, "\nUsage:\tyeahhh\n");
		return (1);
	}

	return (0);
}
