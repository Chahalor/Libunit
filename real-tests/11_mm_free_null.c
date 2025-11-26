/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_mm_free_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:50:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:55:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/memory/memory.h"

int	test_memory_neutral_mm_free_null(void)
{
	if (mm_free(NULL), 1)
		return (0);
	else
		return (-1);
}
