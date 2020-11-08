/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:40:23 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 16:54:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

t_packet			*packet_create(int32_t type, t_sockaddr_in to)
{
	t_packet	*packet;

	if (!(packet = (t_packet*)malloc(sizeof(t_packet)))) {
		return (NULL);
	}
	memset(packet, 0, sizeof(t_packet));
	packet->type = type;
	packet->to = to;
	packet->ttl = DEFAULT_TTL;
	packet->sequence = 0;
	packet->msg = NULL;
	packet->msglen = 0;
	return (packet);
}
