/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:39:45 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 18:37:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

const char *g_iphdr = "[IP HDR]:\n\
	VERSION: %u\n\
	IHL: %u\n\
	TOS: %u\n\
	TOT_LEN: %u\n\
	ID: %u\n\
	FRAG_OFF: %u\n\
	TTL: %u\n\
	PROTOCOL: %u\n\
	CHECKSUM: %u\n\
	SADDR: %u\n\
	DADDR: %u\n\n\
";

static void print_ip_hdr (t_packet *packet)
{
	printf(g_iphdr, 
		packet->iphdr.version,
		packet->iphdr.ihl,
		packet->iphdr.tos,
		packet->iphdr.tot_len,
		packet->iphdr.id,
		packet->iphdr.frag_off,
		packet->iphdr.ttl,
		packet->iphdr.protocol,
		packet->iphdr.check,
		packet->iphdr.saddr,
		packet->iphdr.daddr);
}

const char *g_icmphdr = "[ICMP HDR]:\n\
	ICMP_TYPE: %u\n\
	ICMP_CODE: %u\n\
	ICMP_CKSUM: %u\n\
	ICMP_ID: %u\n\
	ICMP_SEQ: %u\n\
	ICMP_TIMESTAMP: %d\n\n\
";

static void print_icmp_hdr(t_packet *packet)
{
	if (packet->type == IPPROTO_ICMP) 
		printf(g_icmphdr,
			packet->icmphdr.icmp__type,
			packet->icmphdr.icmp__code,
			packet->icmphdr.icmp__cksum,
			packet->icmphdr.icmp__id,
			packet->icmphdr.icmp__sequence,
			packet->icmphdr.icmp__timestamp);
}

const char *g_udphdr = "[UDP HDR]:\n\
	UDP_SRCPORT: %u\n\
	UDP_DSTPORT: %u\n\
	UDP_LEN: %u\n\
	UDP_CKSUM: %u\n\n\
";

static void print_udp_hdr(t_packet *packet)
{
	if (packet->type == IPPROTO_UDP)
	{
		printf(g_udphdr,
			packet->udphdr.udp_srcport,
			packet->udphdr.udp_dstport,
			packet->udphdr.udp_len,
			packet->udphdr.udp_cksum
		);
	}
}

void	packet_print_debug(t_packet *packet)
{
	print_ip_hdr(packet);
	print_icmp_hdr(packet);
	print_udp_hdr(packet);
}
