/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpacket_iphdr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:45:50 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 19:09:44 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"
#include "ft_net_test.h"

int		testpacket_iphdr()
{
	t_packet *packet;

	printf("PACKET INIT DATA TEST\n");
	packet = packet_create(IPPROTO_ICMP, (t_sockaddr_in){
		.sin_addr = { .s_addr = 1},
		.sin_port = 0
	});
	packet_print_debug(packet);
	packet_destroy(packet);
	packet = packet_create(IPPROTO_UDP, (t_sockaddr_in){
		.sin_addr = { .s_addr = 1},
		.sin_port = 0
	});
	packet_print_debug(packet);
	packet_destroy(packet);
	return (0);
}
