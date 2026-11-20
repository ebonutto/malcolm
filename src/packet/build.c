#include "malcolm.h"

#include <string.h> // memcpy()

static t_ethernet build_ethernet(t_malcolm *ctx, t_target *me, t_target *dest)
{
	t_ethernet eth;

	(void)ctx;

	memcpy(eth.src_mac, me->mac, 6);
	memcpy(eth.dest_mac, dest->mac, 6);

	return (eth);
}

static t_arp build_arp(t_malcolm *ctx, t_target *me, t_target *dest)
{
	t_arp arp;

	(void)ctx;

	arp.hardware_type = htons(1);
	arp.protocol_type = htons(0x0800);
	arp.hardware_len = 6;
	arp.protocol_len = 4;
	arp.opcode = htons(2);

	memcpy(arp.sender_mac, me->mac, 6);
	memcpy(arp.sender_ip, &me->ip, 4);
	memcpy(arp.target_mac, dest->mac, 6);
	memcpy(arp.target_ip, &dest->ip, 4);

	return (arp);
}

t_packet build_packet(t_malcolm *ctx, t_target *me, t_target *dest)
{
	t_packet packet;

	packet.eth = build_ethernet(ctx, me, dest);
	packet.arp = build_arp(ctx, me, dest);

	return (packet);
}
