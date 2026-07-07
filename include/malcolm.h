#ifndef MALCOLM_H
#define MALCOLM_H

/* Includes */
#include <stdint.h>	// uintX_t

/* Defines */
/* As defined in if_ether.h */
#define ETH_ALEN	6		/* Octets in one ethernet addr */
#define ETH_P_ARP	0x0806		/* Address Resolution packet */

/* Structures */
/* Ethernet frame header */
typedef struct __attribute__((packed)) {
	uint8_t  dest_addr[ETH_ALEN];  /* Destination hardware address */
	uint8_t  src_addr[ETH_ALEN];   /* Source hardware address */
	uint16_t frame_type;           /* Ethernet frame type */
} ether_hdr;

/* As defined in if_ether.h */
struct ethhdr {
	unsigned char	h_dest[ETH_ALEN];	/* destination eth addr	*/
	unsigned char	h_source[ETH_ALEN];	/* source ether addr	*/
	__be16		h_proto;		/* packet type ID field	*/
} __attribute__((packed));

/* Ethernet ARP packet from RFC 826 */
typedef struct __attribute__((packed)) {
	uint16_t ar_hrd;            /* Format of hardware address */
	uint16_t ar_pro;            /* Format of protocol address */
	uint8_t  ar_hln;            /* Length of hardware address */
	uint8_t  ar_pln;            /* Length of protocol address */
	uint16_t ar_op;             /* ARP opcode (command) */
	uint8_t  ar_sha[ETH_ALEN];  /* Sender hardware address */
	uint32_t ar_sip;            /* Sender IP address */
	uint8_t  ar_tha[ETH_ALEN];  /* Target hardware address */
	uint32_t ar_tip;            /* Target IP address */
} arp_ether_ipv4;

struct s_target {
	uint8_t ip[];
	uint8_t mac[];
};

/* Context */
struct s_malcolm_ctx {
	s_target source;
	s_target destination;
} s_malcolm_ctx

/* Prototypes */
int parse_input(int argc, char **argv);

#endif
