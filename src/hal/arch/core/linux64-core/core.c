/*
 * MIT License
 *
 * Copyright(c) 2011-2019 The Maintainers of Nanvix
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <nanvix/hal/core/interrupt.h>
#include <arch/core/linux64/core.h>
#include <nanvix/const.h>

/**
 * @brief Lookup table for thread IDs.
 */
PUBLIC pthread_t linux64_cores_tab[LINUX64_CORE_NUM_CORES];

/*============================================================================*
 * linux64_core_getid()                                                       *
 *============================================================================*/

/**
 * The linux64_core_get_id() returns the ID of the underlying core.
 */
PUBLIC int linux64_core_get_id(void)
{
	/* Search for target core. */
	for (int i = 0; i < LINUX64_CORE_NUM_CORES ; i++)
	{
		/* Found. */
		if (linux64_cores_tab[i] == pthread_self())
			return (i);
	}

	return (-1);
}

/*============================================================================*
 * linux64_core_poweroff()                                                    *
 *============================================================================*/

/**
 * @todo TODO: provide a detailed description for this function.
 */
PUBLIC NORETURN void linux64_core_poweroff(void)
{
	/* Search for target core. */
	for (int i = 0; i < LINUX64_CORE_NUM_CORES; i++)
	{
		/* Found. */
		if (linux64_cores_tab[i] == pthread_self())
		{
			linux64_cores_tab[i] = 0;
			pthread_exit(NULL);
		}
	}

	UNREACHABLE();
}