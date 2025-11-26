/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_realloc_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:42:45 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:50:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_realloc_10(void)
{
	void	*ptr;
	void	*ptr_2;

	ptr = mm_alloc(5);
	ptr_2 = mm_realloc(ptr, 10);
	if (ptr_2 != NULL)
		return (mm_free(ptr_2), 0);
	else
		return (-1);
}
