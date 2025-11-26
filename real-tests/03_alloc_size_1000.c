/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_alloc_size_1000.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:41:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:48:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_alloc_size_1000(void)
{
	void	*ptr;

	ptr = mm_alloc(1000);
	if (ptr != NULL)
		return (mm_free(ptr), 0);
	else
		return (-1);
}
