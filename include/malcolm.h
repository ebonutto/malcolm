#ifndef MALCOLM_H
#define MALCOLM_H

/* Includes */
#include <netinet/in.h> // struct in_addr

/* Defines */
#define FLAG_HELP (1 << 0)
#define FLAG_VERBOSE (1 << 1)

/* Structures */
typedef struct s_arp {
	uint16_t hardware_type;
	uint16_t protocol_type;
	uint8_t hardware_len;
	uint8_t protocol_len;
	uint16_t opcode;
	uint8_t sender_mac[6];
	uint8_t sender_ip[4];
	uint8_t target_mac[6];
	uint8_t target_ip[4];
} t_arp;

typedef struct s_ethernet {
	uint8_t dest_mac[6];
	uint8_t src_mac[6];
	uint16_t ether_type;
} t_ethernet;

typedef struct s_packet {
	t_ethernet eth;
	t_arp arp;
} t_packet;

typedef struct s_target {
	struct in_addr ip;
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
	int sockfd;
	int ifindex;
} t_malcolm;

/* Prototypes */
/* parsing */
int parse_args(t_args *args, int argc, char **argv);

/* malcolm */
int malcolm(t_malcolm *ctx);

/* network */
int setup_socket(t_malcolm *ctx);

/* packet */
t_packet build_packet(t_malcolm *ctx, t_target *me, t_target *dest);
int send_packet(t_malcolm *ctx, t_target *dest, t_packet *packet);

#endif
