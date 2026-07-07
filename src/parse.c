#include "malcolm.h"
#include <stdio.h> // fprintf(), stderr

void print_usage()
{
	fprintf(stdout, "Hello\n");
}

int parse_input(int argc, char **argv)
{
	// if (argc > 2 && (ft_strcmp("-h", argv[1]) != 0 || ft_strcmp("--help", argv[1]) != 0)) {
	// }

	if (argc != 5) {
		fprintf(stderr, "%s: usage error: invalid number of arguments\n", argv[0]);
		fprintf(stderr, "\nUsage:\tyeahhh\n");
		return (1);
	}

	return (0);
}
