/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_alloc_size_10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:40:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:48:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_alloc_size_10(void)
{
	void	*ptr;

	ptr = mm_alloc(10);
	if (ptr != NULL)
		return (mm_free(ptr), 0);
	else
		return (-1);
}
