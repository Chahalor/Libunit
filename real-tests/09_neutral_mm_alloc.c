/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_neutral_mm_alloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:54:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "framework/memory/memory.h"

int	test_memory_neutral_mm_alloc(void)
{
	char	*buffer;

	buffer = mm_alloc(sizeof(char) * 12);
	memcpy(buffer, "bob is bob\n", 12);
	neutral(buffer, 12);
	if (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0", 12) == 0)
		return (mm_free(buffer), 0);
	else
		return (-1);
}
