# prompt> make
# builds everything and links in test program test_rb
#
# prompt> make mem_check
# Rebuilds everything using dmalloc and does memory testing.
# Only works if you have dmalloc installed (see http://dmalloc.com).

SRCS = test_red_black_tree.c red_black_tree.c list.c misc.c

HDRS = red_black_tree.h list.h misc.h

LIBOBJS = red_black_tree.o list.o misc.o

OBJS = test_red_black_tree.o $(LIBOBJS)

CC = gcc

CFLAGS = -g -Wall -pedantic

PROGRAM = test_rb

.PHONY:	mem_check clean

# default is to build just the "library" objects needed by users
default: $(LIBOBJS)

all: $(PROGRAM)

$(PROGRAM): 	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) $(DMALLOC_LIB)

mem_check:	
		echo "Using default makefile (i.e. no -f flag)." ; \
		$(MAKE) clean ; \
		$(MAKE) $(PROGRAM) "CFLAGS=$(CFLAGS) -DDMALLOC" "DMALLOC_LIB=-ldmalloc" ; \
		./simple_test.sh
		@if [ -s unfreed.txt ] ; then \
			echo " " ; \
			echo "Leaked some memory.  See logfile for details." ;\
		else \
			echo " " ; \
			echo "No memory leaks detected. " ;\
			echo " " ; \
			echo "Test passed. " ; \
			echo " " ; \
		fi


test_red_black_tree.o:	test_red_black_tree.c red_black_tree.c list.c list.h red_black_tree.h misc.h

red_black_tree.o:	red_black_tree.h list.h red_black_tree.c list.c misc.h misc.c

list.o:		list.c list.h misc.h misc.c

clean:			
	rm -f *.o *~ $(PROGRAM)






