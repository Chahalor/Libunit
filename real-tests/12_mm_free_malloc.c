/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_mm_free_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:56:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_neutral_mm_free_malloc(void)
{
	void	*ptr;

	ptr = malloc(10);
	if (mm_free(ptr), 1)
		return (free(ptr), 0);
	else
		return (-1);
}
