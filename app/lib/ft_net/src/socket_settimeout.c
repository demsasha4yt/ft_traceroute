/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_settimeout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:23:18 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 16:42:57 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

int		socket_settimeout(t_socket sock, int32_t timeout_sec)
{
	struct timeval		timeout;
	
	memset(&timeout, 0, sizeof(timeout));
	timeout.tv_usec = timeout_sec;
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
		return (0);
	}
	return (1);
}
