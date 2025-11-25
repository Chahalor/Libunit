/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:05:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 09:54:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static const char	*g_signal_str[NSIG] = {
[0] = "ok",
[SIGHUP] = "Hangup",
[SIGINT] = "Interrupt",
[SIGQUIT] = "Quit",
[SIGILL] = "Illegal instruction",
[SIGTRAP] = "Trace/breakpoint trap",
[SIGABRT] = "Abort",
[SIGBUS] = "Bus error",
[SIGFPE] = "Floating point exception",
[SIGKILL] = "Killed",
[SIGUSR1] = "User-defined signal 1",
[SIGSEGV] = "Segmentation fault",
[SIGUSR2] = "User-defined signal 2",
[SIGPIPE] = "Broken pipe",
[SIGALRM] = "Alarm clock",
[SIGTERM] = "Terminated",
[SIGCHLD] = "Child status changed",
[SIGCONT] = "Continue",
[SIGSTOP] = "Stopped",
[SIGTSTP] = "Stopped (tty)",
[SIGTTIN] = "Background read from tty",
[SIGTTOU] = "Background write to tty",
};

const char	*strsignal(
	const int sig
)
{
	if (sig >= 0 && sig < NSIG && g_signal_str[sig])
		return (g_signal_str[sig]);
	else if (sig == NSIG)
		return ("ko");
	else
		return ("Unknown signal");
}

#if BONUS != 1

void	log_test(
	const int fd,
	const char *const *function,
	const char *const *name,
	const int status
)

{
	char	*color;

	if (status != test_status_ok)
		color = RED;
	else
		color = GREEN;
	ft_fprintf(fd, "%s%s:%s:%s"RESET, color, function, name, ft_strerr(status));
}

#else

void	log_test(
	const int fd,
	const char *const *function,
	const char *const *name,
	const int status
)
{
	int		log_fd;
	char	*color;
	char	*filename;

	if (status != test_status_ok)
		color = RED;
	else
		color = GREEN;
	ft_fprintf(fd, "%s%s:%s:%s\n"RESET, color, function, name,
		strsignal(status));
	filename = mm_alloc(sizeof(char) * (ft_strlen((void *)function) + 6));
	if (!filename)
		return ;
	ft_memset(filename, (ft_strlen((void *)function) + 6));
	ft_sprintf(filename, "%s.log", function);
	log_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_fprintf(log_fd, "%s:%s:%s\n", function, name, strsignal(status));
	mm_free(filename);
	close(log_fd);
}

#endif	// BONUS != 1
