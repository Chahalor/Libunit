/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_neutral_neg_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 09:01:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "framework/memory/memory.h"

int	test_memory_neutral_neg_size(void)
{
	char	buffer[12];

	memcpy(buffer, "bob is bob\n", 12);
	neutral(buffer, -1);
	if (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0", -12) != 0)
		return (0);
	else
		return (-1);
}
