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

#include <arch/core/k1b/mmu.h>
#include <nanvix/const.h>
#include <errno.h>

/**
 * @brief Maps a page.
 *
 * @param pgtab Target page table.
 * @param paddr Physical address of the target page frame.
 * @param vaddr Virtual address of the target page.
 * @param w     Writable page?
 *
 * @returns Upon successful completion, zero is returned. Upon
 * failure, a negative error code is returned instead.
 */
PUBLIC int k1b_page_map(struct pte *pgtab, paddr_t paddr, vaddr_t vaddr, int w)
{
	int idx;

	/* Invalid page table. */
	if (UNLIKELY(pgtab == NULL))
		return (-EINVAL);

	idx = pte_idx_get(vaddr);

	pgtab[idx].present = 1;
	pgtab[idx].writable = (w) ? 1 : 0;
	pgtab[idx].frame = K1B_FRAME(paddr >> K1B_PAGE_SHIFT);

	return (0);
}

/**
 * @brief Maps a page table.
 *
 * @param pgdir Target page directory.
 * @param paddr Physical address of the target page table frame.
 * @param vaddr Virtual address of the target page table.
 */
PUBLIC int k1b_pgtab_map(struct pde *pgdir, paddr_t paddr, vaddr_t vaddr)
{
	int idx;

	/* Invalid page directory. */
	if (UNLIKELY(pgdir == NULL))
		return (-EINVAL);

	idx = pde_idx_get(vaddr);

	pgdir[idx].present = 1;
	pgdir[idx].frame = K1B_FRAME(paddr >> K1B_PAGE_SHIFT);

	return (0);
}
