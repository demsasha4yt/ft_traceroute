/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_get_hdr_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:16:37 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 18:16:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

uint16_t packet_get_hdr_len(t_packet *packet)
{
	if (packet->type == IPPROTO_UDP)
		return (UDP_HDR_SIZE);
	if (packet->type == IPPROTO_ICMP)
		return (ICMP_HDR_SIZE);
	return (ICMP_HDR_SIZE);
}
