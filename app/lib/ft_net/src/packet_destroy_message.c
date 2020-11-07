/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_destroy_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:50:15 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/07 17:51:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void	packet_destroy_message(t_packet *packet)
{
	if (packet->msg)
		free(packet->msg);
	packet->msglen = 0;
}