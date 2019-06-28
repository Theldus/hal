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

#include <arch/core/linux64/tlb.h>
#include <nanvix/const.h>
#include <errno.h>

/*============================================================================*
 * linux64_tlb_write()                                                            *
 *============================================================================*/

/**
 * The linux64_tlbe_write() function writes an entry into the architectural
 * TLB. If the new entry conflicts to an old one, the old one is
 * overwritten.
 *
 * @author Pedro Henrique Penna
 */
PUBLIC int linux64_tlbe_write(
		struct tlbe *tlbe,
		vaddr_t vaddr,
		paddr_t paddr,
		unsigned protection
)
{
	struct tlbe _tlbe;      /**< Temporary tlbe.  */

	/* Invalid TLB entry. */
	if (tlbe == NULL)
		return (-EINVAL);

	_tlbe.addr_ext = 0;
	_tlbe.addrspace = 0;
	_tlbe.cache_policy = LINUX64_DTLBE_CACHE_POLICY_WRTHROUGH;
	_tlbe.frame = paddr >> LINUX64_PAGE_SHIFT;
	_tlbe.global = 1;
	_tlbe.page = vaddr >> LINUX64_PAGE_SHIFT;
	_tlbe.protection = protection;
	_tlbe.size = 1;
	_tlbe.status = LINUX64_TLBE_STATUS_AMODIFIED;

	kmemcpy(tlbe, &_tlbe, LINUX64_TLBE_SIZE);

	return (0);
}

/**
 * The linux64_tlbe_inval() function invalidates the TLB entry that
 * encodes the virtual address @p vaddr.
 *
 * @author Pedro Henrique Penna
 */
PUBLIC int linux64_tlbe_inval(
	struct tlbe *tlbe,
	vaddr_t vaddr
)
{
	struct tlbe _tlbe;      /**< Temporary tlbe.  */

	/* Invalid TLB entry. */
	if (tlbe == NULL)
		return (-EINVAL);

	_tlbe.addr_ext = 0;
	_tlbe.addrspace = 0;
	_tlbe.cache_policy = 0;
	_tlbe.frame = 0;
	_tlbe.global = 0;
	_tlbe.page = vaddr >> LINUX64_PAGE_SHIFT;
	_tlbe.protection = 0;
	_tlbe.size = 1;
	_tlbe.status = LINUX64_TLBE_STATUS_INVALID;

	kmemcpy(tlbe, &_tlbe, LINUX64_TLBE_SIZE);

	return (0);
}