/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 23:47:24 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/28 17:19:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_socket	init_socket(int domain, int type, int protocol)
{
	t_socket sock;

	sock = socket(domain, type, protocol);
	if (sock < 0)
		perror("socket");
	return (sock);
}

void		set_ttl(t_socket socket, uint8_t ttl)
{
	if (setsockopt(socket, IPPROTO_IP, IP_TTL, &(ttl), sizeof(ttl)) < 0)
		perror("setsockopt");
}
