/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_allocsize_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:38:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:40:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_allocsize_0(void)
{
	if (mm_alloc(0) == NULL)
		return (0);
	else
		return (-1);
}
