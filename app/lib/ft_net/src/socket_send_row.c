/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_send_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:11:05 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 17:11:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

int			send_socket_raw(t_socket socket, int32_t flags, t_packet *pckt)
{
	int32_t ret;

	ret = sendto(socket, pckt->buf, pckt->buflen, flags,
		(struct sockaddr*)&pckt->to, sizeof(pckt->to));
	if (ret < 0)
		return (SOCKET_SEND_ERROR);
	return (ret);
}
