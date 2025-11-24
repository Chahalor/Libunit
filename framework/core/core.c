/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:59:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/24 21:48:29 by nduvoid          ###   ########.fr       */
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

	dummy = mm_alloc(sizeof(t_test *) * (tester->nb_tests  + 16));
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

static void	exit_program(
	const int code
)
{
	mm_destroy();
	exit(code);
}

t_test	*load_test(
	t_tester *const restrict tester,
	const char *const restrict name,
	int (*const func)(void)
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
	result->func = func;
	ft_memcpy(result->name, name, len);
	result->name[len] = 0;
	result->output = 0;
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
	pid_t	pid;
	int		exit_status;

	pid = fork();
	if (pid < 0)
		return (-2);
	else if (!pid)
	{
		exit_status = test->func();
		exit_program(exit_status);
		exit(exit_status);
	}
	else
	{
		wait(&exit_status);
		if (WIFSIGNALED(exit_status))
			exit_status = WTERMSIG(exit_status);
		else if (exit_status)
			exit_status = NSIG;
		else
			exit_status = 0;
		test->output = exit_status;
		return (exit_status);
	}
}

int	run_tests(
	t_tester *const restrict tester,
	const int begining,
	const int end
)
{
	int	i;
	int	result;
	int	stop;
	int	nb_testes;

	if (begining >= tester->nb_tests)
		i = 0;
	else
		i = begining * (begining > 0);
	if ((end < 0) || (end > tester->nb_tests))
		stop = tester->nb_tests;
	else
		stop = end;
	if (stop < i)
		stop = tester->nb_tests;
	nb_testes = stop - i;
	while (i < stop)
	{
		result = run_test(tester->tests[i]);
		if (result != 0)
			tester->nb_fails++;
		log_test(2, (void *)g_current_test, (void *)tester->tests[i]->name, result);
		i++;
	}
	ft_fprintf(2, "%d/%d tester successfull\n", nb_testes - tester->nb_fails, nb_testes);
	return (-(tester->nb_fails != 0));
}
