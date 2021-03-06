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

#ifndef NANVIX_HAL_CLOCK_H_
#define NANVIX_HAL_CLOCK_H_

	/* Core Interface Implementation */
	#include <nanvix/hal/core/_core.h>

/*============================================================================*
 * Interface Implementation Checking                                          *
 *============================================================================*/

	/* Constants */
	#ifndef HAL_INT_CLOCK
	#error "HAL_INT_CLOCK not defined"
	#endif

	/* Functions */
	#ifndef __hal_clock_init
	#error "hal_clock_init() not defined?"
	#endif

/*============================================================================*
 * Clock Device Interface                                                     *
 *============================================================================*/

/**
 * @addtogroup kernel-hal-core-clock Clock
 * @ingroup kernel-hal-core
 *
 * @brief Clock Device Interface HAL Interface
 */
/**@{*/

	#include <nanvix/const.h>

	/**
	 * @brief Initializes the hardware dependent clock driver.
	 *
	 * @param freq Frequency for the clock device.
	 */
	EXTERN void hal_clock_init(unsigned freq);

/**@}*/

#endif /* NANVIX_HAL_CLOCK_H_ */

