/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_set_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:57:26 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 17:09:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void		packet_set_message(t_packet *packet, char *message)
{
	packet->msg = message;
	packet->msglen = strlen(message);
}
