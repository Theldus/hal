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

#ifndef PROCESSOR_BOSTAN_NOC_NODE_H_
#define PROCESSOR_BOSTAN_NOC_NODE_H_

/**
 * @cond bostan-noc
 */

	/* Cluster API. */
	#include <arch/processor/bostan/_bostan.h>

	#include <arch/processor/bostan/clusters.h>

/*============================================================================*
 * Node Interface                                                             *
 *============================================================================*/

	/**
	 * @brief Gets the ID of the NoC node attached to the underlying core.
	 *
	 * @returns The ID of the NoC node attached to the underlying core is
	 * returned.
	 *
	 * @note This function is blocking.
	 * @note This function is thread-safe.
	 */
	static inline int bostan_node_get_id(void)
	{
		int clusterid;

		clusterid = bostan_cluster_get_id();

		if (bostan_cluster_is_iocluster(clusterid))
			return (clusterid + k1b_core_get_id());

		return (clusterid);
	}

/**@endcond*/

/*============================================================================*
 * Exported Interface                                                         *
 *============================================================================*/

/**
 * @cond bostan
 */

	/**
	 * @name Provided Interface
	 */
	/**@{*/
	#define __hal_processor_node
	#define __processor_node_get_id   /**< processor_node_get_id()   */
	/**@}*/

	/**
	 * @see bostan_node_get_id()
	 */
	static inline int processor_node_get_id(void)
	{
		return bostan_node_get_id();
	}

/**@endcond*/

#endif /* PROCESSOR_BOSTAN_NOC_NODE_H_ */
