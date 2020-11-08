/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:48:00 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 17:11:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"


t_socket			socket_create(int32_t protocol, int32_t hdrincl, int32_t broadcast, int32_t timeout)
{
	t_socket			sock;

	if ((sock = socket(AF_INET, SOCK_RAW, protocol)) < 0) // Raw socket descriptor
	{
		printf("socket() failed : Operation not permitted\n");
		return (SOCKET_CREATE_ERROR);
	}
	if ((setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &hdrincl, sizeof(hdrincl))) < 0) // set flag so socket expects us to provide IPv4 header.
	{
		printf("setsockopt() failed to set IP_HDRINCL\n");
		socket_close(sock);
		return (SOCKET_CREATE_ERROR);
	}
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (const char*)&broadcast, sizeof(broadcast)) < 0) // allow socket to send datagrams to broadcast addresses
	{
		printf("setsockopt() failed to set SO_BROADCAST\n");
		socket_close(sock);
		return (SOCKET_CREATE_ERROR);
	}
	if ((socket_settimeout(sock, timeout)) != 1) {
		socket_close(sock);
		return (SOCKET_CREATE_ERROR);
	}
	return (sock);
}
