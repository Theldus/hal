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

#ifndef ARCH_CORE_OR1K_CORE_H_
#define ARCH_CORE_OR1K_CORE_H_

	#define __NEED_OR1K_REGS
	#include <arch/core/or1k/regs.h>
	#include <arch/core/or1k/types.h>

/**
 * @addtogroup or1k-core
 */
/**@{*/

#ifndef _ASM_FILE_

	#include <nanvix/const.h>
	#include <stdint.h>

#endif /* _ASM_FILE_ */

	/**
	 * @name States of a Core
	 */
	/**@{*/
	#define OR1K_CORE_IDLE      0 /**< Idle        */
	#define OR1K_CORE_SLEEPING  1 /**< Sleeping    */
	#define OR1K_CORE_RUNNING   2 /**< Running     */
	#define OR1K_CORE_RESETTING 3 /**< Resetting   */
	#define OR1K_CORE_OFFLINE   4 /**< Powered Off */
	/**@}*/

#ifndef _ASM_FILE_

	/**
	 * @brief Reads from an specified Special-Purpose register.
	 *
	 * @param reg Register to be read.
	 *
	 * @returns Returns the value of the specified SPR.
	 */
	static inline unsigned or1k_mfspr(unsigned reg)
	{
		register unsigned ret
			__asm__("r3") = (unsigned) 0;
		register unsigned r5
			__asm__("r5") = (unsigned) reg;

		__asm__ __volatile__
		(
			"l.mfspr r3, r5, 0"
			: "=r" (ret)
			: "r" (r5)
		);
		return (ret);
	}

	/**
	 * @brief Writes to an specified Special-Purpose register.
	 *
	 * @param reg Register to be written.
	 * @param value Value to be written.
	 */
	static inline void or1k_mtspr(unsigned reg, unsigned value)
	{
		register unsigned r3
			__asm__("r3") = (unsigned) reg;
		register unsigned r5
			__asm__("r5") = (unsigned) value;

		__asm__ __volatile__
		(
			"l.mtspr r3, r5, 0\n"
			:
			: "r" (r3), "r" (r5)
		);
	}

	/**
	 * @brief Gets the ID of the core.
	 *
	 * The or1k_core_get_id() returns the ID of the underlying core.
	 *
	 * @returns The ID of the underlying core.
	 */
	static inline int or1k_core_get_id(void)
	{
		return (or1k_mfspr(OR1K_SPR_COREID));
	}

	/**
	 * @brief Suspends instruction execution in the underlying core.
	 */
	EXTERN void or1k_core_sleep(void);

	/**
	 * @brief Suspends instruction execution in the underlying core.
	 */
	EXTERN void or1k_core_idle(void);

	/**
	 * @brief Wakes up a core.
	 *
	 * @param coreid ID of the target core.
	 */
	EXTERN void or1k_core_wakeup(int coreid);

	/**
	 * @brief Starts a core.
	 *
	 * @param coreid ID of the target core.
	 * @param start  Starting routine to execute.
	 */
	EXTERN void or1k_core_start(int coreid, void (*start)(void));

	/**
	 * @brief Shutdowns the underlying core.
	 *
	 * @param status Shutdown status.
	 */
	EXTERN void or1k_core_shutdown(int status);	

	/**
	 * @brief Initializes the underlying core.
	 */
	EXTERN void or1k_core_setup(void);

	/**
	 * @brief Resets the underlying core.
	 *
	 * The or1k_core_reset() function resets execution instruction in
	 * the underlying core by reseting the kernel stack to its initial
	 * location and relaunching the or1k_slave_setup() function.
	 *
	 * @note This function does not return.
	 * @note For the implementation of this function check out
	 * assembly source files.
	 *
	 * @see or1k_slave_setup()
	 *
	 * @author Davidson Francis
	 */
	EXTERN void or1k_core_reset(void);

	/**
	 * @brief Resumes instruction execution in the underlying core.
	 */
	EXTERN void or1k_core_run(void);

#endif /* _ASM_FILE_ */

/**@}*/

/*============================================================================*
 * Exported Interface                                                         *
 *============================================================================*/

/**
 * @cond mor1kx
 */

	/**
	 * @name Provided Interface
	 */
	/**@{*/
	#define __core_get_id   /**< core_get_id()   */
	#define __core_shutdown /**< core_shutdown() */
	#define __core_sleep    /**< core_sleep()    */
	#define __core_wakeup   /**< core_wakeup()   */
	#define __core_start    /**< core_start()    */
	#define __core_reset    /**< core_reset()    */
	/**@}*/

#ifndef _ASM_FILE_

	/**
	 * @see or1k_core_get_id().
	 */
	static inline int core_get_id(void)
	{
		return (or1k_core_get_id());
	}
	
	/**
	 * @see or1k_core_sleep().
	 */
	static inline void core_sleep(void)
	{
		or1k_core_sleep();
	}

	/**
	 * @see or1k_core_wakeup().
	 */
	static inline void core_wakeup(int coreid)
	{
		or1k_core_wakeup(coreid);
	}

	/**
	 * @see or1k_core_start().
	 */
	static inline void core_start(int coreid, void (*start)(void))
	{
		or1k_core_start(coreid, start);
	}

	/**
	 * @see or1k_core_shutdown().
	 */
	static inline void core_shutdown(int status)
	{
		or1k_core_shutdown(status);
	}

	/**
	 * @see or1k_core_reset().
	 */
	static inline void core_reset(void)
	{
		or1k_core_reset();
	}	

#endif /* _ASM_FILE_ */

/**@endcond*/

#endif	/* ARCH_CORE_OR1K_CORE_H_ */
