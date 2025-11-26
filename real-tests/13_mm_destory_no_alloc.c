/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_mm_destory_no_alloc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:56:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_neutral_mm_destroy_no_alloc(void)
{
	if (mm_destroy(), 1)
		return (0);
	else
		return (-1);
}
