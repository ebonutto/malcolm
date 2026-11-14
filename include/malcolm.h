#ifndef MALCOLM_H
#define MALCOLM_H

/* Includes */
#include <netinet/in.h> // struct in_addr

/* Defines */
#define FLAG_HELP (1 << 0)
#define FLAG_VERBOSE (1 << 1)

/* As defined in if_ether.h */
#define ETH_ALEN 6 // Octets in one ethernet addr
#define ETH_P_ARP 0x0806 /* Address Resolution packet

/* Structures */
typedef struct s_target {
	struct in_addr *ip;
	uint8_t mac[6];
} t_target;

typedef struct s_args {
	char *progname;
	t_target src;
	t_target dest;
	int flags;
} t_args;

typedef struct s_malcolm {
	t_args args;
} t_malcolm;

/* Prototypes */
int parse_args(t_args *args, int argc, char **argv);

#endif
