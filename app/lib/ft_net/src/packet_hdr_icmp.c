/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_hdr_icmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:03:19 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/07 18:04:24 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void		packet_fill_icmp(t_packet *packet, uint8_t type, uint8_t code)
{
	if (packet->type != IPPROTO_ICMP)
		return ;
	packet->icmphdr.icmp__type = type;
	packet->icmphdr.icmp__code = code;
	packet->icmphdr.icmp__id = htons(getpid());
	packet->icmphdr.icmp__timestamp = net_gettime();
}