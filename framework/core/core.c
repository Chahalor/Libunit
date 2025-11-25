/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:59:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 14:33:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

extern char	*g_current_test;

static inline void	*_realloc(
	t_tester *const restrict tester,
	int *const restrict alloc_size
)
{
	t_test	**dummy;
	int		i;

	dummy = mm_alloc(sizeof(t_test *) * (tester->nb_tests + 16));
	if (!dummy)
		return (NULL);
	if (tester->tests)
	{
		tester->tests = dummy;
		return (dummy);
	}
	i = -1;
	while (++i < tester->nb_tests)
		dummy[i] = tester->tests[i];
	mm_free(tester->tests);
	tester->tests = dummy;
	*alloc_size += 16;
	return (dummy);
}

t_test	*load_test(
	t_tester *const restrict tester,
	const char *const restrict name,
	int (*const func)(void),
	const struct timeval timeout
)
{
	static int	alloc_size = 0;
	t_test		*result;
	int			len;

	if ((!tester || !name || !func))
		return (NULL);
	len = ft_strlen(name);
	result = mm_alloc(sizeof(t_test) + sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result->name = (char *)(result + 1);
	ft_memcpy(result->name, name, len);
	result->func = func;
	result->output = 0;
	result->timeout = timeout;
	result->finished = 0;
	if (tester->nb_tests < alloc_size)
		tester->tests[tester->nb_tests++] = result;
	else
	{
		if (!_realloc(tester, &alloc_size))
			return (mm_free(result), NULL);
		tester->tests[tester->nb_tests++] = result;
	}
	return (result);
}

static inline int	run_test(
	t_test *const test
)
{
	pid_t				pid;
	int					exit_status;
	struct itimerval	timeout;

	pid = fork();
	if (pid < 0)
		return (-2);
	else if (!pid)
	{
		server_init();
		if (test->timeout.tv_sec || test->timeout.tv_usec)
		{
			timeout.it_value = test->timeout;
			timeout.it_interval = (t_timeval){0};
			setitimer(ITIMER_REAL, &timeout, NULL);
		}
		exit_status = test->func();
		exit_program(exit_status);
		exit(exit_status);
	}
	else
	{
		test->pid = pid;
		return (pid);
	}
}

static inline int	display_tests(
	t_tester *tester,
	int nb_tests,
	int begining,
	int end
)
{
	int		nb_finished;
	int		i;
	int		status;
	t_test	*t;
	pid_t	pid;

	nb_finished = 0;
	while (nb_finished < nb_tests)
	{
		i = begining - 1;
		while (++i < end)
		{
			t = tester->tests[i];
			if (t->finished)
				continue ;
			pid = waitpid(t->pid, &status, WNOHANG);
			if (pid > 0)
				handle_result(tester, t, status + 0 * nb_finished++);
		}
		usleep(1000);
	}
	ft_fprintf(2, "%d/%d tests successfull\n",
		nb_tests - tester->nb_fails, nb_tests);
	return (-(tester->nb_fails != 0));
}

int	run_tests(
	t_tester *tester,
	int begining,
	int end
)
{
	int	i;
	int	nb_tests;

	if (begining < 0)
		begining = 0;
	if (end <= 0 || end > tester->nb_tests)
		end = tester->nb_tests;
	if (end < begining)
		end = tester->nb_tests;
	nb_tests = end - begining;
	i = begining;
	while (i < end)
	{
		tester->tests[i]->index = tester->nb_displayed;
		ft_printf("[%s]:[%s]:[   RUN    ]\n", g_current_test,
			tester->tests[i]->name);
		tester->nb_displayed++;
		run_test(tester->tests[i++]);
	}
	return (display_tests(tester, nb_tests, begining, end));
}
