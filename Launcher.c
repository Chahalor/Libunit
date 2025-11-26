/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:52:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 09:32:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "core.h"

int	launcher_signal(
		const int start,
		const int stop
		);

int	launcher_memory(
		const int start,
		const int end
		);

int	main(int argc, char *argv[])
{
	int	result;

	result = launcher_signal(0, 6);
	result += launcher_memory(0, 15) * result == -1;
	exit_program(result);
	return (result);
}
