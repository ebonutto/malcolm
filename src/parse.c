#include "malcolm.h"

#include <arpa/inet.h> // inet_ntop()

#include <stdio.h> // stderr, fprintf()
#include <string.h> // strcmp()

static int parse_flag(t_malcolm_ctx *ctx, char *arg)
{
	if (strcmp("-h", arg) == 0 || strcmp("--help", arg) == 0)
		ctx->flags |= FLAG_HELP;
	else if (strcmp("-v", arg) == 0 || strcmp("--verbose", arg) == 0)
		ctx->flags |= FLAG_VERBOSE;
	else {
		fprintf(stderr, "%s: Error: invalid option '%s'",
		        ctx->progname, arg);
		return (1);
	}
	return (0);
}

static int parse_ip(uint8_t ip[IPV4_ALEN], const char *arg) //! const
{
	if (inet_pton(AF_INET, arg, ip) != 1) {
		fprintf(stderr, "malcolm: Error: unknown or invalid ip address '%s'", arg);
		return (1);
	}
	return (0);
}

static int hex_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

/*
 * Parse une adresse MAC stricte "xx:xx:xx:xx:xx:xx" (exactement 2 chiffres
 * hexa par octet, separes par ':'). Rejette explicitement "aaa:bb:..." ou
 * "a:bb:...", contrairement a sscanf("%hhx:...") qui les laisserait passer.
 */
static int parse_mac(uint8_t mac[ETH_ALEN], const char *str)
{
	int	i;
	int	hi;
	int	lo;

	i = 0;
	while (i < ETH_ALEN) {
		hi = hex_val(str[0]);
		lo = (str[0] != '\0') ? hex_val(str[1]) : -1;
		if (hi < 0 || lo < 0)
			return (1);
		mac[i] = (uint8_t)((hi << 4) | lo);
		str += 2;
		i++;
		if (i < ETH_ALEN) {
			if (*str != ':')
				return (1);
			str++;
		}
	}
	if (*str != '\0')
		return (1);
	return (0);
}

static int parse_address(t_malcolm_ctx *ctx, char *arg, int pos)
{
	if (pos == 0)
		parse_ip(ctx->src.ip, arg);
	else if (pos == 1)
		parse_mac(ctx->src.mac, arg);
	else if (pos == 2)
		parse_ip(ctx->dest.ip, arg);
	else if (pos == 3)
		parse_mac(ctx->dest.mac, arg);
	else {

		return (1);
	}
	return (0);
}

int parse_args(t_malcolm_ctx *ctx, int argc, char **argv)
{
	int i;
	int pos;
	int ret;

	ctx->progname = argv[0];
	i = 1;
	pos = 0;
	while (i < argc) {
		if (argv[i][0] == '-')
			ret = parse_flag(ctx, argv[i]);
		else {
			ret = parse_address(ctx, argv[i], pos);
			pos++;
		}
		if (ret)
			return (1);
		i++;
	}
	if (pos != 4) {
		fprintf(stderr, "%s: Error: missing arguments\n",
		        ctx->progname);
		return (1);
	}
	return (0);
}
