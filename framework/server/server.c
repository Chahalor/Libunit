/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:09:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 14:39:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ----| Headers    |----- */
	/* Standard */
		//...
	/* Internal */
#include "server.h"
	/* External */
		//...

/* ----| Prototypes |----- */
	//...

/* ----| Internals  |----- */
	//...

/* ----| Public     |----- */

void	_signal_handler(
	int signal,
	siginfo_t *info,
	void *context
)
{
	(void)signal;
	(void)info;
	(void)context;
	exit_program(signal);
}

__attribute__((always_inline, used))
inline int	reset_signal(void)
{
	return (signal(SIGALRM, SIG_DFL) == SIG_ERR);
}

/**
 * @brief	Initializes the signal handlers for all differents signals.
 * 
 * @param	None
 * 
 * @return	the success status of the signal initialization.
 * @retval		0 if the signal handlers were successfully set.
 * @retval		1 if there was an error setting the signal handlers.
 * 
 * @version 1.2
*/
__attribute__((always_inline, used))
inline int	server_init(void)
{
	struct sigaction	sig_action;

	sig_action.sa_sigaction = _signal_handler;
	sig_action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sig_action.sa_mask);
	return (sigaction(SIGALRM, &sig_action, NULL));
}
