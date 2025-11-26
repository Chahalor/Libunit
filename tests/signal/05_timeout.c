/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_timeout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:27:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 09:28:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_infinit(void)
{
	while (1)
		;
	return (42);
}

int	test_timeout(void)
{
	if (ft_infinit() == 0)
		return (0);
	else
		return (-1);
}
