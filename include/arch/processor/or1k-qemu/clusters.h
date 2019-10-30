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

#ifndef PROCESSOR_OR1K_PROCESSOR_CLUSTERS_H_
#define PROCESSOR_OR1K_PROCESSOR_CLUSTERS_H_

	/* Processor Interface Implementation */
	#include <arch/processor/or1k-qemu/_or1k-qemu.h>

/**
 * @addtogroup processor-or1k-clusters Clusters
 * @ingroup processor-or1k
 *
 * @brief Clusters
 */
/**@*/

	#include <nanvix/const.h>

	/**
	 * @brief Number of IO Clusters.
	 */
	#define OR1K_PROCESSOR_IOCLUSTERS_NUM 1

	/**
	 * @brief Number of compute clusters.
	 */
	#define OR1K_PROCESSOR_CCLUSTERS_NUM 0

	/**
	 * @brief Types of Clusters
	 */
	/**@{*/
	#define OR1K_PROCESSOR_IOCLUSTER 1 /**< IO Cluster      */
	#define OR1K_PROCESSOR_CCLUSTER  2 /**< Compute Cluster */
	/**@}*/

	/**
	 * @brief Logical ID of master cluster.
	 */
	#define OR1K_PROCESSOR_CLUSTERNUM_MASTER 0

	/**
	 * @brief Retrieves the logical number of the underlying cluster.
	 */
	EXTERN int or1k_cluster_get_num(void);

	/**
	 * @brief Asserts whether or not the target cluster is a compute cluster.
	 *
	 * @param clusterid ID of the target cluster.
	 *
	 * @return Non zero if the target cluster is a compute cluster and
	 * zero otherwise.
	 */
	EXTERN int or1k_cluster_is_compute(int clusternum);

	/**
	 * @brief Asserts whether or not the target cluster is an IO cluster.
	 *
	 * @param clusterid ID of the target cluster.
	 *
	 * @return Non zero if the target cluster is an IO cluster and
	 * zero otherwise.
	 */
	EXTERN int or1k_cluster_is_io(int clusternum);

/**@}*/
/*============================================================================*
 * Exported Interface                                                         *
 *============================================================================*/

/**
 * @cond or1k_processor
 */

	/**
	 * @name Provided Constants
	 */
	/**@{*/
	#define PROCESSOR_CCLUSTERS_NUM     OR1K_PROCESSOR_CCLUSTERS_NUM     /**< @see OR1K_PROCESSOR_CCLUSTERS_NUM     */
	#define PROCESSOR_IOCLUSTERS_NUM    OR1K_PROCESSOR_IOCLUSTERS_NUM    /**< @see OR1K_PROCESSOR_IOCLUSTERS_NUM    */
	#define PROCESSOR_CLUSTERNUM_MASTER OR1K_PROCESSOR_CLUSTERNUM_MASTER /**< @see OR1K_PROCESSOR_CLUSTERNUM_MASTER */
	/**@}*/

	/**
	 * @name Provided Functions
	 */
	/**@{*/
	#define __cluster_get_num_fn      /**< or1k_cluster_cluster_get_num() */
	#define __cluster_is_ccluster_fn  /**< or1k_cluster_is_compute()      */
	#define __cluster_is_iocluster_fn /**< or1k_cluster_is_io()           */
	/**@}*/

	/**
	 * @see or1k_processor_cluster_get_num().
	 */
	static inline int cluster_get_num(void)
	{
		return (or1k_cluster_get_num());
	}

	/**
	 * @see or1k_processor_cluster_is_ccluster().
	 */
	static inline int cluster_is_ccluster(int clusternum)
	{
		return (or1k_cluster_is_compute(clusternum));
	}

	/**
	 * @see or1k_processor_cluster_is_iocluster().
	 */
	static inline int cluster_is_iocluster(int clusternum)
	{
		return (or1k_cluster_is_io(clusternum));
	}

/**@endcond*/

#endif /* PROCESSOR_OR1K_PROCESSOR_CLUSTERS_H_ */
