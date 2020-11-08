/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpacket_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:10:01 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 19:14:34 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"
#include "ft_net_test.h"


int		testpacket_calc()
{
	t_packet *packet;

	packet = packet_create(IPPROTO_UDP, (t_sockaddr_in){
	});

	packet_set_message(packet, strdup("testing data"));
	packet_fill_udp(packet, 80, 80);
	packet_fill_ip(packet);
	packet_calc(packet, 1);
	packet_print_debug(packet);
	return (0);
}
