#
# MIT License
#
# Copyright(c) 2011-2019 The Maintainers of Nanvix
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

#===============================================================================
# Target Configuration
#===============================================================================

export PROCESSOR = bostan

#===============================================================================
# Toolchain Configuration
#===============================================================================

# Toolchain Directory
export K1_TOOLCHAIN_DIR=/usr/local/k1tools

# Tools
export CC = $(K1_TOOLCHAIN_DIR)/bin/k1-gcc
export LD = $(K1_TOOLCHAIN_DIR)/bin/k1-gcc
export AR = $(K1_TOOLCHAIN_DIR)/bin/k1-ar

# Compiler Options
export CFLAGS   = -D __mppa256__ -D __k1b__
export CFLAGS  += -mos=bare -march=k1b -mboard=developer

# Linker Options
export LDFLAGS  = -Wl,--allow-multiple-definition

#===============================================================================

# Builds Nanvix for the MPPA-256 target.
nanvix-target: nanvix-k1bdp nanvix-k1bio

# Cleans everything for the MPPA-256 target.
distclean-target: distclean-k1bdp distclean-k1bio

# Builds Nanvix for a Compute Cluster.
nanvix-k1bdp:
	$(MAKE) -C $(SRCDIR) -f build/makefile.k1bdp all

# Builds Nanvix for an IO Cluster.
nanvix-k1bio:
	$(MAKE) -C $(SRCDIR) -f build/makefile.k1bio all

# Cleans compilation files for a Compute Cluster.
distclean-k1bdp:
	$(MAKE) -C $(SRCDIR) -f build/makefile.k1bdp distclean

# Cleans compilation files for an IO Cluster.
distclean-k1bio:
	$(MAKE) -C $(SRCDIR) -f build/makefile.k1bio distclean
