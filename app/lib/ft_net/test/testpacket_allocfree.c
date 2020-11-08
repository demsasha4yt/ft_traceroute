/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpacket_allocfree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:25:33 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 18:08:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

int testpacket_allocfree() 
{
	t_packet *packet;
	
	printf("ALLOCFREE TEST\n");
	packet = packet_create(IPPROTO_ICMP, (t_sockaddr_in){
		.sin_addr = { .s_addr = 1},
		.sin_port = 0
	});
	packet_destroy_buffer(packet);
	packet_destroy_message(packet);
	packet_set_message(packet, strdup("Hello world"));
	packet_destroy_message(packet);
	printf("Hello!\n");
	packet_destroy(packet);
	return (0);
}
