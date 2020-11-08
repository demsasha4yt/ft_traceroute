/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:14:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 18:46:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

static void	calc_icmp_cksum(t_icmphdr *icmphdr, t_packet *packet, uint16_t offset)
{
	if (packet->type == IPPROTO_ICMP)
		icmphdr->icmp__cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
}

static void calc_udp_cksum(t_udphdr *udphdr, t_packet *packet, uint16_t offset)
{
	if (packet->type == IPPROTO_UDP)
		udphdr->udp_cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
}

static void calc_tcp_cksum(t_tcphdr *tcphdr, t_packet *packet, uint16_t offset)
{
	if (packet->type == IPPROTO_TCP)
		tcphdr->tcp_cksum = in_cksum(packet->buf + offset,
			packet_get_hdr_len(packet) + packet->msglen);
}

static void calc_ip_cksum(t_iphdr *iphdr, t_packet *packet)
{
	(void)iphdr;
	(void)packet;
}

int		packet_calc(t_packet *packet)
{
	packet->buflen = IP_HDR_SIZE + packet_get_hdr_len(packet) + packet->msglen;
	if (packet->buf != NULL)
		packet_destroy_buffer(packet);
	packet->buf = (uint8_t*)malloc(sizeof(uint8_t) * packet->buflen + 1);
	memset(packet->buf, 0, packet->buflen);
	memcpy(packet->buf + IP_HDR_SIZE + packet_get_hdr_len(packet), 
		packet->msg, packet->msglen);
	if (packet->type == IPPROTO_UDP)
		memcpy(packet->buf + IP_HDR_SIZE, &packet->udphdr, sizeof(t_udphdr));
	if (packet->type == IPPROTO_ICMP)
		memcpy(packet->buf + IP_HDR_SIZE, &packet->icmphdr, sizeof(t_icmphdr));
	calc_icmp_cksum((t_icmphdr*)(packet->buf + IP_HDR_SIZE), packet, 
		IP_HDR_SIZE);
	calc_udp_cksum((t_udphdr*)(packet->buf + IP_HDR_SIZE), packet, 
		IP_HDR_SIZE);
	calc_tcp_cksum((t_tcphdr*)(packet->buf + IP_HDR_SIZE), packet,
		IP_HDR_SIZE);
	calc_ip_cksum((t_iphdr*)packet->buf, packet);
	return (0);
}
