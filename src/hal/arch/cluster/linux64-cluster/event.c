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

#include <arch/cluster/linux64-cluster/cores.h>

/**
 * @brief Table of locks.
 */
PRIVATE linux64_spinlock_t locks[LINUX64_CLUSTER_NUM_CORES];

/**
 * Table of pending events.
 */
PRIVATE pthread_cond_t events[LINUX64_CLUSTER_NUM_CORES];

/**
 * @brief Notifies a local core about an event.
 *
 */
PUBLIC void linux64_cluster_event_notify(int coreid)
{
    int self = linux64_core_get_id();
    
    KASSERT(coreid >= 0 && self >= 0 && coreid < LINUX64_CLUSTER_NUM_CORES
            && self < LINUX64_CLUSTER_NUM_CORES
            && coreid != self);

    linux64_spinlock_lock(&locks[coreid]);

    pthread_cond_signal(&events[coreid]);

    linux64_spinlock_unlock(&locks[coreid]);
}

/**
 * @brief Waits for an event.
 */
PUBLIC void linux64_cluster_event_wait(void)
{
    int self = linux64_core_get_id();

    KASSERT(self >= 0 && self < LINUX64_CLUSTER_NUM_CORES);

    linux64_spinlock_lock(&locks[self]);
    pthread_cond_wait(&events[self], &locks[self]);
    linux64_spinlock_unlock(&locks[self]);
}

/**
 * @brief Setup the event table.
 */
PUBLIC void linux64_cluster_event_setup(void)
{
    for(int i = 0; i < LINUX64_CLUSTER_NUM_CORES; i++)
    {
        linux64_spinlock_init(&locks[i]);
        pthread_cond_init(&events[i], NULL);
    }
}

/**
 * @brief Drop all the pending events.
 */
PUBLIC void linux64_cluster_event_drop(void)
{
    linux64_cluster_event_setup();
}