/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:05:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/24 19:58:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static inline int	ft_strlen(
	const char *const str
)
{
	int	i;

	if (!i)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static inline int	ft_strerr(
	const int errnum
)
{
	const char	*errors[8] = {
		[test_status_ok] = "OK",
		[test_status_ko] = "KO",
		[test_status_sigsev] = "SIGSEV",
		[test_status_sigbus] = "SIGBUS",
		[test_status_sigabrt] = "SIGABRT",
		[test_status_sigfpe] = "SIGFPE",
		[test_status_sigpipe] = "SIGPIPE",
		[test_status_sikill] = "SIGKILL"
	};

	return (errors[errnum]);
}

void	log_test(
	const int fd,
	const char *const *function,
	const char *const *name,
	const int status
)
#if BONUS != 1

{
	char	*color;

	if (status != test_status_ok)
		color = RED;
	else
		color = GREEN;
	ft_fprintf(fd, "%s%s:%s:%s"RESET, color, function, name, ft_strerr(status));
}

#else

{
	static int	log_fd = -1;
	char		*color;
	char		*filename;
	int			len;

	if (status < 0)
		return ((void)close(log_fd));
	else if (log_fd < 0)
		log_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (status != test_status_ok)
		color = RED;
	else
		color = GREEN;
	ft_fprintf(fd, "%s%s:%s:%s"RESET, color, function, name, ft_strerr(status));
	filename = malloc(sizeof(char) * (ft_strlen(function) + 5));
	if (!filename)
		return ;
	ft_fprintf(log_fd, "%s%s:%s:%s"RESET, color, function, name, ft_strerr(status));
	free(filename);
}

#endif	// BONUS != 1
