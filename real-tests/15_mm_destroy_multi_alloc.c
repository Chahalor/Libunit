/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_mm_destroy_multi_alloc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 09:11:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_neutral_mm_destroy_many_alloc(void)
{
	mm_alloc(50);
	mm_alloc(45);
	mm_alloc(456);
	mm_alloc(5468);
	mm_alloc(321321);
	mm_alloc(11);
	mm_alloc(12);
	mm_alloc(45);
	mm_alloc(15);
	mm_alloc(77887);
	if (mm_destroy(), 1)
		return (0);
	else
		return (-1);
}
