/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:14:48 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 19:05:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

static int	packet_calc_withip(t_packet *packet)
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

static int packet_calc_withnoip(t_packet *packet)
{
	packet->buflen =  packet_get_hdr_len(packet) + packet->msglen;
	if (packet->buf != NULL)
		packet_destroy_buffer(packet);
	packet->buf = (uint8_t*)malloc(sizeof(uint8_t) * packet->buflen + 1);
	memset(packet->buf, 0, packet->buflen);
	memcpy(packet->buf + packet_get_hdr_len(packet), 
		packet->msg, packet->msglen);
	if (packet->type == IPPROTO_UDP)
		memcpy(packet->buf, &packet->udphdr, sizeof(t_udphdr));
	if (packet->type == IPPROTO_ICMP)
		memcpy(packet->buf , &packet->icmphdr, sizeof(t_icmphdr));
	calc_icmp_cksum((t_icmphdr*)(packet->buf), packet, 
		0);
	calc_udp_cksum((t_udphdr*)(packet->buf), packet, 
		0);
	calc_tcp_cksum((t_tcphdr*)(packet->buf), packet,
		0);
	return (0);
}

int		packet_calc(t_packet *packet, int withip)
{
	if (withip)
		return (packet_calc_withip(packet));
	return (packet_calc_withnoip(packet));
}
