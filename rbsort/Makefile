# Makefile for rbsort task
#
# to compile rbsort, type
#
#   make
#

COMPILE = gcc -g -c
LINK = gcc

RBOBJS = ../rb_tree/red_black_tree.o ../rb_tree/list.o ../rb_tree/misc.o

# note: make builds the first target (rbsort) by default:

rbsort: $(RBOBJS) rbsort.o
	$(LINK) -o rbsort rbsort.o $(RBOBJS)

run: rbsort
	./rbsort

debug: rbsort
	gdb rbsort

clean:
	rm -rf $(RBOBJS) rbsort rbsort-test rbsort.o

rbsort.o: rbsort.c
	$(COMPILE) -o rbsort.o rbsort.c

../rb_tree/red_black_tree.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/list.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/misc.o: 
	cd ../rb_tree; make -f Makefile

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/rbsort-submission.zip *
