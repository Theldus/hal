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

#ifndef ARCH_CLUSTER_I386_CORES_H_
#define ARCH_CLUSTER_I386_CORES_H_

	/* Cluster Interface Implementation */
	#include <arch/cluster/i386/_i386.h>

/**
 * @addtogroup i386-cluster-cpu Cores
 * @ingroup i386-cluster
 *
 * @brief Cores
 */
/**@{*/

	/**
	 * @brief Number of cores.
	 */
	#define I386_NUM_CORES 1

	/**
	 * @brief ID of the master core.
	 */
	#define I386_COREID_MASTER 0

	/**
	 * @brief Gets the number of cores.
	 *
	 * The i386_cpu_get_num_cores() gets the number of cores in the
	 * underlying i386 processor.
	 *
	 * @returns The the number of cores in the underlying processor.
	 */
	static inline int i386_cpu_get_num_cores(void)
	{
		return (I386_NUM_CORES);
	}

/**@}*/

/*============================================================================*
 *                              Exported Interface                            *
 *============================================================================*/

/**
 * @cond i386
 */

	/**
	 * @name Provided Functions
	 */
	/**@{*/
	#define __hal_cpu_get_num_cores
	/**@}*/

	/**
	 * @brief Number of cores in a cluster.
	 */
	#define HAL_NUM_CORES I386_NUM_CORES

	/**
	 * @brief ID of the master core.
	 */
	#define COREID_MASTER I386_COREID_MASTER

	/**
	 * @see i386_cpu_get_num_cores()
	 */
	static inline int hal_cpu_get_num_cores(void)
	{
		return (i386_cpu_get_num_cores());
	}

/**@endcond*/

#endif /* ARCH_CLUSTER_I386_CORES_H_ */
