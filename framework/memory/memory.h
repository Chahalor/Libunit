/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:52:57 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/10/08 15:26:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# pragma once

/* -------- modules --------- */
	// --- internals --- //
# include "_internal_/__memory.h"

/* ------- prototypes ------- */
	// ---- exposed ---- //
// allocate :
extern void	*mm_alloc(
				const size_t size
				)	__attribute__((hot, visibility("default")));
extern void	*mm_realloc(
				void *restrict ptr,
				const size_t size
				);
extern void	neutral(
				void *restrict const area,
				const unsigned int size
				);
extern void	mm_free(
				void *restrict ptr
				);
extern void	mm_destroy(void);

#endif