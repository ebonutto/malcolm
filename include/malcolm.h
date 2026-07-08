#ifndef MALCOLM_H
#define MALCOLM_H

/* Includes */
#include <stdint.h> // uintX_t

/* Defines */
#define FLAG_HELP    (1 << 0) // -h, --help
#define FLAG_VERBOSE (1 << 1) // -v, --verbose

/* As defined in if_ether.h */
#define ETH_ALEN  6      // Octets in one ethernet addr
#define ETH_P_ARP 0x0806 // Address Resolution packet
#define IPV4_ALEN 4      // Octets in one IPv4 addr

/* As defined in net/if.h */
#define	IF_NAMESIZE 16

/* ARP opcodes, RFC 826 */
#define ARP_REQUEST 1
#define ARP_REPLY   2

/* Hardware/protocol types, RFC 826 */
#define ARP_HTYPE_ETHER 1
#define ARP_PTYPE_IPV4  0x0800

/* Structures */
/* Ethernet frame header */
typedef struct __attribute__((packed)) {
	uint8_t dest_addr[ETH_ALEN]; // Destination hardware address
	uint8_t src_addr[ETH_ALEN];  // Source hardware address
	uint16_t frame_type;         // Ethernet frame type
} ether_hdr;

/* Ethernet ARP packet, RFC 826 */
typedef struct __attribute__((packed)) s_arp_packet {
	uint16_t ar_hrd;          // Format of hardware address
	uint16_t ar_pro;          // Format of protocol address
	uint8_t ar_hln;           // Length of hardware address
	uint8_t ar_pln;           // Length of protocol address
	uint16_t ar_op;           // ARP opcode (command)
	uint8_t ar_sha[ETH_ALEN]; // Sender hardware address
	uint32_t ar_sip;          // Sender IP address
	uint8_t ar_tha[ETH_ALEN]; // Target hardware address
	uint32_t ar_tip;          // Target IP address
} t_arp_packet;

/* Target */
typedef struct s_target {
	uint8_t	ip[IPV4_ALEN];
	uint8_t	mac[ETH_ALEN];
} t_target;

/* Context */
typedef struct s_malcolm_ctx {
	const char *progname;
	int flags;
	int sockfd;
	t_target self;
	t_target src;
	t_target dest;
} t_malcolm_ctx;

/* Prototypes */
int parse_args(t_malcolm_ctx *ctx, int argc, char **argv);

int malcolm(t_malcolm_ctx *ctx);

#endif
