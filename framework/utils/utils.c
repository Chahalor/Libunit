/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:02:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 09:58:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

extern inline int	ft_strlen(
	const char *const restrict str
)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_memcpy(
	void *const restrict dest,
	const void *const restrict src,
	const int size
)
{
	int	i;

	i = 0;
	while (i < size)
	{
		((char *)(dest))[i] = ((char *)(src))[i];
		i++;
	}
}

void	ft_memset(
	void *const restrict ptr,
	const int size
)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (i < size)
		((char *)ptr)[i++] = 0;
}

extern void	exit_program(
	const int code
)
{
	mm_destroy();
	exit(code);
}
