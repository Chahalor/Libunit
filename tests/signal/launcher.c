/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:26:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 09:37:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

// #define (t_timeval){1, 0}	(t_timeval){1, 0}

int	sigsev(void);
int	sigbus(void);
int	sigabrt(void);
int	sigfpe(void);
int	sigpipe(void);
int	test_timeout(void);
int	sigill(void);

int	launcher_signal(
	const int start,
	const int stop
)
{
	static t_tester	tester = {0};
	int				result;

	g_current_test = "test signal";
	load_test(&tester, "should SIGSEV", sigsev, (t_timeval){1, 0});
	load_test(&tester, "should SIGBUS", sigbus, (t_timeval){1, 0});
	load_test(&tester, "should SIGABRT", sigabrt, (t_timeval){1, 0});
	load_test(&tester, "should SIGFPE", sigfpe, (t_timeval){1, 0});
	load_test(&tester, "should SIGPIPE", sigpipe, (t_timeval){1, 0});
	load_test(&tester, "should TIMEOUT", test_timeout, (t_timeval){1, 0});
	load_test(&tester, "should SIGILL", sigill, (t_timeval){1, 0});
	result = run_tests(&tester, start, stop);
	return (result);
}
