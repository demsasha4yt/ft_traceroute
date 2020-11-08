/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:15:31 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 17:47:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"
#include "ft_net_test.h"
int main () 
{
	testpacket_allocfree();
	testpacket_iphdr();
	return (0);	
}
