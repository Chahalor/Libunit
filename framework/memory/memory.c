/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/24 21:35:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Interface |----- */
#include "memory.h"

/* -----| Internal  |----- */
#include "_internal_/__memory.h"

/** */
__attribute__((malloc, used)) void	*mm_alloc(
	const size_t size
)
{
	t_mm_node		*node;
	char			*base;
	register size_t	i;

	if (size < 1)
		return (NULL);
	node = (t_mm_node *)malloc(sizeof(t_mm_node) + size);
	if (__builtin_expect(!node, 0))
		return (NULL);
	base = (char *)((char *)node + sizeof(t_mm_node));
	i = 0;
	while (i < size)
		base[i++] = 0;
	node->ptr = base;
	node->allocated = size;
	node->next = NULL;
	_mm_store(node, mm_add);
	return (node->ptr);
}

/** */
__attribute__((malloc, used)) void	*mm_realloc(
	void *restrict ptr,
	const size_t nsize
)
{
	void			*new_ptr;
	register int	cpsize;

	if (ptr == NULL)
		return (mm_alloc(nsize));
	else if (nsize < 1)
		return (mm_free(ptr), NULL);
	new_ptr = mm_alloc(nsize);
	if (!new_ptr)
		return (NULL);
	cpsize = 0;
	while (((char *)ptr)[cpsize])
		++cpsize;
	mm_memcpy(new_ptr, ptr, cpsize);
	mm_free(ptr);
	return (new_ptr);
}

void	neutral(
	void *restrict const area,
	const unsigned int size
)
{
	register unsigned int	i;

	if ((!area || size < 1))
		return ;
	i = 0;
	while (i < size)
		((char *)area)[i++] = 0;
	return ;
}

/** */
__attribute__((used)) void	mm_free(
	void *restrict ptr
)
{
	if (ptr == NULL)
		return ;
	_mm_store(ptr, mm_freeing);
}

/** */
__attribute__((used)) void	mm_destroy(void)
{
	_mm_store(NULL, mm_free_all);
}
