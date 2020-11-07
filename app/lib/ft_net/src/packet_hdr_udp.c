/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_hdr_udp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:52:10 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/07 17:46:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void	packet_fill_udp(t_packet *packet, uint16_t dstport, uint16_t srcport)
{
	if (packet->type != IPPROTO_UDP)
		return ;
	packet->udphdr.udp_len = UDP_HDR_SIZE + packet->msglen;
	packet->udphdr.udp_dstport = dstport;
	packet->udphdr.udp_srcport = srcport;
	packet->udphdr.udp_cksum = 0;
}