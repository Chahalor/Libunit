/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:05:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 14:41:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

extern char			*g_current_test;

static const char	*g_signal_str[NSIG] = {
[0] = "OK",
[SIGHUP] = "SIGHUP",
[SIGINT] = "SIGINT",
[SIGQUIT] = "SIGQUIT",
[SIGILL] = "SIGILL",
[SIGTRAP] = "SIGTRAP",
[SIGABRT] = "SIGABRT",
[SIGBUS] = "SIGBUS",
[SIGFPE] = "SIGFPE",
[SIGKILL] = "SIGKILL",
[SIGUSR1] = "SIGUSR1",
[SIGSEGV] = "SIGSEGV",
[SIGUSR2] = "SIGUSR2",
[SIGPIPE] = "SIGPIPE",
[SIGALRM] = "TIMEOUT",
[SIGTERM] = "SIGTERM",
[SIGCHLD] = "SIGCHLD",
[SIGCONT] = "SIGCONT",
[SIGSTOP] = "SIGSTOP",
[SIGTSTP] = "SIGTSTP",
[SIGTTIN] = "SIGTTIN",
[SIGTTOU] = "SIGTTOU",
[SIGURG] = "SIGURG",
[SIGXCPU] = "SIGXCPU",
[SIGXFSZ] = "SIGXFSZ",
[SIGVTALRM] = "SIGVTALRM",
[SIGPROF] = "SIGPROF",
[SIGWINCH] = "SIGWINCH",
[SIGIO] = "SIGIO",
[SIGPWR] = "SIGPWR",
[SIGSYS] = "SIGSYS",
};

const char	*strsignal(
	const int sig
)
{
	if (sig >= 0 && sig < NSIG && g_signal_str[sig])
		return (g_signal_str[sig]);
	else
		return ("KO");
}

__attribute_maybe_unused__
static void	write_log_file(
	const t_test *const restrict test
)
{
	const int	len = ft_strlen(g_current_test) + sizeof(".log");
	char		*filename;
	int			fd;

	filename = mm_alloc(sizeof(char) * len);
	if (!filename)
		return ;
	ft_sprintf(filename, "%s.log", g_current_test);
	fd = open(filename, O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		return (mm_free(filename));
	ft_fprintf(fd, "[%s]:[%s]:[%s]\n", g_current_test, test->name,
		strsignal(test->output));
	close(fd);
	mm_free(filename);
}

static void	print_result_line(
	const t_test *const restrict test,
	const int result,
	const int total
)
{
	const int	line_up = total - test->index;
	char		buffer[32];
	char		*color;

	if (result == 0)
		color = GREEN;
	else if (result < NSIG && result != SIGSEGV && result != SIGBUS)
		color = YELLOW;
	else
		color = RED;
	ft_sprintf(buffer, "\033[%dF", line_up);
	ft_printf("\033[s%s\033[2K[%s]:[%s]:[%s%s"RESET"]\n\033[u", buffer,
		g_current_test, test->name, color, strsignal(result));
	write_log_file(test);
}

int	handle_result(
	t_tester *tester,
	t_test *test,
	int status
)
{
	int	result;

	if (WIFSIGNALED(status))
		result = WTERMSIG(status);
	else if (WIFEXITED(status))
		result = WEXITSTATUS(status);
	else
		result = NSIG;
	if (result)
		tester->nb_fails++;
	test->output = result;
	test->finished = 1;
	print_result_line(test, result, tester->nb_displayed);
	return (result);
}
