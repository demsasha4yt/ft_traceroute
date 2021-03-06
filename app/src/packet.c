/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:39:39 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/28 17:54:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void				send_packet(t_socket socket, int port,
	uint32_t saddr, t_timeval *tv_send)
{
	char			packet[60];
	t_sockaddr_in	sin;

	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = saddr;
	ft_memset(&(sin.sin_zero), 0, sizeof(sin.sin_zero));
	ft_memset(&packet, 0, 60);
	gettimeofday(tv_send, NULL);
	sendto(socket, packet, 60, 0, (t_sockaddr*)&sin, sizeof(sin));
}

static double		diff(struct timeval *tv_1, struct timeval *tv_2)
{
	return ((double)(((tv_2->tv_sec - tv_1->tv_sec) * 1000000) +
		(tv_2->tv_usec - tv_1->tv_usec)) / 1000);
}

static char			*hostname(t_in_addr *iaddr, char *host)
{
	ft_memset(host, 0, INET_ADDRSTRLEN + 1);
	if (inet_ntop(AF_INET, &(iaddr->s_addr), host, INET_ADDRSTRLEN + 1))
		return (host);
	return (NULL);
}

int					read_packet(int sock, t_probe *probe)
{
	int		ret;
	void	*ptr;

	ft_memset(&probe->buf, 0, 512);
	if ((ret = recvfrom(sock, &probe->buf, 512, 0,
		(struct sockaddr*)&probe->from, &probe->fromlen)) > 0)
	{
		ptr = (void*)probe->buf;
		probe->iphdr = ptr;
		probe->icmphdr = ptr + probe->iphdr->ihl * 4;
		gettimeofday(&probe->tv_read, NULL);
		probe->tv_delta = diff(&probe->tv_send, &probe->tv_read);
		if (probe->probe == 0)
			printf("%2d  %s ", probe->ttl,
				hostname((t_in_addr*)&(probe->iphdr->saddr),
					(char*)(&probe->host)));
		if (probe->probe == 0 || probe->old_saddr == probe->iphdr->saddr)
			printf(" %.3f ms", probe->tv_delta);
		else
			printf(" (%s) %.3f ms", hostname((t_in_addr*)&(probe->iphdr->saddr),
				(char*)(&probe->host)), probe->tv_delta);
		probe->old_saddr = probe->iphdr->saddr;
		return (probe->icmphdr->icmp__type);
	}
	return (-1);
}
