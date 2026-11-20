#include "malcolm.h"

#include <arpa/inet.h> // inet_pton()

#include <stdlib.h> // strtoul()
#include <string.h> // strlen()

static int parse_ip(struct in_addr *ip, const char *str)
{
	if (inet_pton(AF_INET, str, ip) != 1)
		return (1);
	return (0);
}

static int parse_mac(uint8_t mac[6], const char *str)
{
	size_t i;
	unsigned long value;
	char *end;

	if (strlen(str) != 17)
		return (1);

	for (i = 0; i < 6; i++) {
		value = strtoul(str + i * 3, &end, 16);
		if (end != str + i * 3 + 2)
			return (1);

		mac[i] = (uint8_t)value;

		if (i < 5 && str[i * 3 + 2] != ':')
			return (1);
	}

	return (0);
}

int parse_args(t_args *args, int argc, char **argv)
{
	if (argc < 5)
		return (1);

	args->progname = argv[0];

	if (parse_ip(&args->src.ip, argv[1]))
		return (1);
	if (parse_mac(args->src.mac, argv[2]))
		return (1);
	if (parse_ip(&args->dest.ip, argv[3]))
		return (1);
	if (parse_mac(args->src.mac, argv[4]))
		return (1);

	return (0);
}
