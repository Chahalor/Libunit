/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_neutral_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:52:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "framework/memory/memory.h"

int	test_memory_neutral_stack(void)
{
	char	buffer[12];

	memcpy(buffer, "bob is bob\n", 12);
	neutral(buffer, 12);
	if (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0", 12) == 0)
		return (0);
	else
		return (-1);
}
