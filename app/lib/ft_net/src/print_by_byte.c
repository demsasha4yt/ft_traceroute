/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:12:24 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 18:14:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_net.h"

void	print_by_byte(uint8_t *packet, int size)
{
	int		i;
	int		j;
	uint8_t	a;

	j = 0;
	while (j < size)
	{
		i = 7;
		a = (uint8_t)packet[j];
		printf("%d:\t", j);
		while (i >= 0)
		{
			printf("%u", a >> i & 1);
			i--;
		}
		printf("\t|\t%#x\t%d", a, a);
		printf("\n");
		j++;
	}
}
