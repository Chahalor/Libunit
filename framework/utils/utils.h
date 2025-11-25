/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:39:55 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/25 14:01:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
# include "standards.h"

/* -----| Internals |----- */
// # include "types.h"

/* -----| Modules   |----- */
# include "memory.h"

/* ************************************************************************** */
/*                                 Macros                                     */
/* ************************************************************************** */
	//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

int		ft_strlen(
			const char *const restrict str
			);

void	ft_memcpy(
			void *const restrict dest,
			const void *const restrict src,
			const int size
			);

void	ft_memset(
			void *const restrict ptr,
			const int size
			);

void	exit_program(
			const int code
			);

#endif	// UTILS_H