/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_sigbus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:06:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 15:12:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	sigbus(void)
{
	if (kill(getpid(), SIGBUS))
		return (0);
	else
		return (-1);
}
