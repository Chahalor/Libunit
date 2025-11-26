/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_alloc_sizen_minus_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:42:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:49:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_alloc_size_minu_1(void)
{
	void	*ptr;

	ptr = mm_alloc(-1);
	if (ptr == NULL)
		return (0);
	else
		return (-1);
}
