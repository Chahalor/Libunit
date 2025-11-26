/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:39:55 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 08:09:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
# include "../standards/standards.h"
# include "../standards/formating.h"

/* -----| Internals |----- */
// # include "types.h"

/* -----| Modules   |----- */
# include "memory.h"
# include "../server/server.h"
# include "interface.h"
# include "utils.h"

/* ************************************************************************** */
/*                                 Macros                                     */
/* ************************************************************************** */

extern char	*g_current_test;

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_test	*load_test(
			t_tester *const restrict tester,
			const char *const restrict name,
			int (*const func)(void),
			const struct timeval timeout
			);

int		run_tests(
			t_tester *const restrict tester,
			int begining,
			int end
			);

#endif	// CORE_H