/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:21:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 14:03:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct timeval	t_timeval;
typedef struct s_test	t_test;
typedef struct s_tester	t_tester;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_test_status
{
	test_status_ok,
	test_status_ko,
	test_status_sigsev,
	test_status_sigbus,
	test_status_sigabrt,
	test_status_sigfpe,
	test_status_sigpipe,
	test_status_sikill,
	test_status_other,
};

/* ************************************************************************** */
/*                                 Unions                                     */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_test
{
	struct timeval	timeout;
	char			*name;
	int				(*func)(void);
	int				finished;
	int				index;
	int				output;
	pid_t			pid;
};

struct s_tester
{
	int		nb_tests;
	int		nb_fails;
	int		nb_displayed;
	t_test	**tests;
};

#endif // TYPES_H