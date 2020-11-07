/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_hdr_ip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:51:03 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/07 17:56:41 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

static uint16_t get_hdr_len(t_packet *packet)
{
	if (packet->type = IPPROTO_UDP)
		return (UDP_HDR_SIZE);
	if (packet->type = IPPROTO_ICMP)
		return (ICMP_HDR_SIZE);
}

void	packet_fill_ip(t_packet *packet)
{
	packet->iphdr.version = 4;
	packet->iphdr.ihl = IP_HDR_SIZE;
	packet->iphdr.tos = 0;
	packet->iphdr.tot_len = IP_HDR_SIZE + get_hdr_len(packet) + packet->msglen;
	packet->iphdr.id = htons(0);
	packet->iphdr.frag_off = htons(0);
	packet->iphdr.ttl = ttl;
	packet->iphdr.protocol = packet->type;
	packet->iphdr.check = 0;
	packet->iphdr.saddr = INADDR_ANY;
	packet->iphdr.daddr = packet->to.sin_addr.s_addr;
}