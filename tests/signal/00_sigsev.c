/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_sigsev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:03:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:10:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULL
# define NULL	((void *)0)
#endif

int	sigsev(void)
{
	char	*null = NULL;

	if ((*null = 10))
		return (-1);
	else
		return (0);
}
