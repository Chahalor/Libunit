/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:52:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 15:39:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	return_0(void)
{
	return(0);
}

int	return_neg(void)
{
	return(-1);
}

int	return_pos(void)
{
	return(2);
}
int	should_timeout(void)
{
	while (1)
		;
}

int	sigsev(void)
{
	char	*null = NULL;

	*null = 10;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_tester	tester;
	int			exit_status;
	int			i;

	(void)argc;
	(void)argv;
	tester.nb_fails = 0;
	tester.nb_tests = 0;
	tester.tests = NULL;
	g_current_test = "random shit";
	load_test(&tester, "success 0", return_0, (t_timeval){1, 0});
	load_test(&tester, "fail -1", return_neg, (t_timeval){1, 0});
	load_test(&tester, "fail > 0", return_pos, (t_timeval){1, 0});
	load_test(&tester, "should timeout", should_timeout, (t_timeval){3, 0});
	load_test(&tester, "should segfault", sigsev, (t_timeval){1, 0});

	exit_status = run_tests(&tester, -1, -1);
	i = 0;
	while (i < tester.nb_tests)
	{
		mm_free(tester.tests[i]);
		tester.tests[i] = NULL;
		i++;
	}
	mm_free(tester.tests);
	return (exit_status);
}
