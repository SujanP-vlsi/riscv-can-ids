# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vtb_sva.mk

default: Vtb_firmware_cosim

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /home/sujan/tools/oss-cad-suite/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?=
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?=

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Module prefix (from --prefix)
VM_MODPREFIX = Vtb_sva
# Design prefix (from --prefix)
VM_PREFIX = Vtb_sva
# Design header include, for '#include VM_PREFIX_INCLUDE' (from --prefix)
VM_PREFIX_INCLUDE = <Vtb_sva.h>
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
  -Ifirmware/include -I/home/sujan/riscv-can-ids/firmware/include \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
  -L/home/sujan/riscv-can-ids/sim/lib_atomic_fix -Wl,-rpath,/home/sujan/riscv-can-ids/sim/lib_atomic_fix \

# User library files (from .a/.o/.so on Verilator command line)
# These are also in VM_USER_LDLIBS, and are link dependencies
VM_USER_LDLIBS_FILES = \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
  tb_firmware_cosim \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
  .. \
  ../.. \

### Default rules...
# Include list of all generated classes
include Vtb_sva_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

tb_firmware_cosim.o: /home/sujan/riscv-can-ids/sim/tb_firmware_cosim.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
Vtb_firmware_cosim: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_USER_LDLIBS_FILES)
	$(LINK) $(LDFLAGS) $(filter-out $(VM_USER_LDLIBS_FILES),$^) $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@

# Verilated -*- Makefile -*-
