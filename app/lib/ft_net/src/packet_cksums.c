/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_cksums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:57:15 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 19:05:09 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void	calc_icmp_cksum(t_icmphdr *icmphdr, t_packet *packet, uint16_t offset)
{
	if (packet->type == IPPROTO_ICMP)
		icmphdr->icmp__cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
}

void	calc_udp_cksum(t_udphdr *udphdr, t_packet *packet, uint16_t offset)
{
	if (packet->type == IPPROTO_UDP)
		udphdr->udp_cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
}

void 	calc_tcp_cksum(t_tcphdr *tcphdr, t_packet *packet, uint16_t offset)
{
	if (packet->type == IPPROTO_TCP)
		tcphdr->tcp_cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
}

void	calc_ip_cksum(t_iphdr *iphdr, t_packet *packet)
{
	(void)iphdr;
	(void)packet;
}
