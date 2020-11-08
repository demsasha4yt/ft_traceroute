/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_cksums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:57:15 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 19:22:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void	calc_icmp_cksum(t_icmphdr *icmphdr, t_packet *packet, uint16_t offset)
{
	uint16_t cksum;

	if (packet->type == IPPROTO_ICMP)
	{
		cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
		packet->icmphdr.icmp__cksum = cksum;
		icmphdr->icmp__cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
	}
		
}

void	calc_udp_cksum(t_udphdr *udphdr, t_packet *packet, uint16_t offset)
{
	uint16_t cksum;

	if (packet->type == IPPROTO_UDP)
	{
		cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
		udphdr->udp_cksum = cksum;
		packet->udphdr.udp_cksum = cksum;
	}
		
}

void 	calc_tcp_cksum(t_tcphdr *tcphdr, t_packet *packet, uint16_t offset)
{
	uint16_t cksum;

	if (packet->type == IPPROTO_TCP)
	{
		cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
		packet->tcphdr.tcp_cksum = cksum;
		tcphdr->tcp_cksum = cksum;
	}
}

void	calc_ip_cksum(t_iphdr *iphdr, t_packet *packet)
{
	(void)iphdr;
	(void)packet;
}
