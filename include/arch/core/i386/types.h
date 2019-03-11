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

/**
 * @cond i386
 */

#if (!defined(__NEED_CORE_TYPES) && !defined(__NEED_MEMORY_TYPES))
	#error "do not include this file"
#endif

#ifndef _ASM_FILE_
	#include <stdint.h>
#endif

/**
 * @addtogroup i386-core
 */
/**@{*/

#ifdef __NEED_CORE_TYPES
#ifndef __CORE_CONSTANTS
#define __CORE_CONSTANTS

	/**
	 * @name Bit-Length of Core Types
	 */
	/**@{*/
	#define I386_BYTE_BIT    8 /**< Byte        */
	#define I386_HWORD_BIT  16 /**< Half Word   */
	#define I386_WORD_BIT   32 /**< Word        */
	#define I386_DWORD_BIT  64 /**< Double Word */
	/**@}*/

	/**
	 * @name Byte-Length of Core Types
	 */
	/**@{*/
	#define I386_BYTE_SIZE   1 /**< Byte        */
	#define I386_HWORD_SIZE  2 /**< Half Word   */
	#define I386_WORD_SIZE   4 /**< Word        */
	#define I386_DWORD_SIZE  8 /**< Double Word */
	/**@}*/

#endif
#endif

/**@}*/

#ifndef _ASM_FILE_

	#ifdef __NEED_MEMORY_TYPES
	#ifndef __MEMORY_TYPES
	#define __MEMORY_TYPES

		/**
		 * @brief Virtual address.
		 */
		typedef uint32_t vaddr_t;

		/**
		 * @brief Physical address.
		 */
		typedef uint32_t paddr_t;

	#endif
	#endif


	/**
	 * @addtogroup i386-core
	 */
	/**@{*/

	#ifdef __NEED_CORE_TYPES
	#ifndef __CORE_TYPES
	#define __CORE_TYPES

		/**
		 * @name Core Types
		 */
		/**@{*/
		typedef uint8_t i386_byte_t;   /**< Byte        */
		typedef uint16_t i386_hword_t; /**< Half Word   */
		typedef uint32_t i386_word_t;  /**< Word        */
		typedef uint64_t i386_dword_t; /**< Double Word */
		/**@}*/

	#endif
	#endif

	/**@}*/

#endif

/**@endcond*/
