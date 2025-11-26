/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:59:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/11/26 09:38:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "core.h"

int	test_memory_allocsize_0(void);
int	test_memory_alloc_size_10(void);
int	test_memory_alloc_size_100(void);
int	test_memory_alloc_size_1000(void);

int	test_memory_alloc_size_minu_1(void);
int	test_memory_realloc_10(void);
int	test_memory_neutral_null(void);
int	test_memory_neutral_stack(void);
int	test_memory_neutral_malloc(void);
int	test_memory_neutral_mm_alloc(void);
int	test_memory_neutral_neg_size(void);
int	test_memory_neutral_mm_free_null(void);
int	test_memory_neutral_mm_free_malloc(void);
int	test_memory_neutral_mm_destroy_no_alloc(void);
int	test_memory_neutral_mm_destroy_1_alloc(void);
int	test_memory_neutral_mm_destroy_many_alloc(void);

int	launcher_memory(
	const int start,
	const int end
)
{
	static t_tester	tester = {0};

	g_current_test = "memory manager";
	load_test(&tester, "alloc size == 0", test_memory_allocsize_0,
		(t_timeval){1, 0});
	load_test(&tester, "alloc size == 10", test_memory_alloc_size_10,
		(t_timeval){1, 0});
	load_test(&tester, "alloc size == 100", test_memory_alloc_size_100,
		(t_timeval){1, 0});
	load_test(&tester, "alloc size == 1000", test_memory_alloc_size_1000,
		(t_timeval){1, 0});
	load_test(&tester, "alloc size == -1", test_memory_alloc_size_minu_1,
		(t_timeval){1, 0});
	load_test(&tester, "realloc size == 10", test_memory_realloc_10,
		(t_timeval){1, 0});
	load_test(&tester, "neutral null", test_memory_neutral_null,
		(t_timeval){1, 0});
	load_test(&tester, "neutral stack", test_memory_neutral_stack,
		(t_timeval){1, 0});
	load_test(&tester, "neutral malloc", test_memory_neutral_malloc,
		(t_timeval){1, 0});
	load_test(&tester, "neutral mm_alloc", test_memory_neutral_mm_alloc,
		(t_timeval){1, 0});
	load_test(&tester, "neutral neg size", test_memory_neutral_neg_size,
		(t_timeval){1, 0});
	load_test(&tester, "mm_free null", test_memory_neutral_mm_free_null,
		(t_timeval){1, 0});
	load_test(&tester, "mm_free malloc", test_memory_neutral_mm_free_malloc,
		(t_timeval){1, 0});
	load_test(&tester, "mm_destroy no alloc",
		test_memory_neutral_mm_destroy_no_alloc, (t_timeval){1, 0});
	load_test(&tester, "mm_destroy 1 alloc",
		test_memory_neutral_mm_destroy_1_alloc, (t_timeval){1, 0});
	load_test(&tester, "mm_destroy many alloc",
		test_memory_neutral_mm_destroy_many_alloc, (t_timeval){1, 0});
	return (run_tests(&tester, start, end));
}
