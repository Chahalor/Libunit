/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_alloc_size_100.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:41:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:48:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_alloc_size_100(void)
{
	void	*ptr;

	ptr = mm_alloc(100);
	if (ptr != NULL)
		return (mm_free(ptr), 0);
	else
		return (-1);
}
