# Makefile for rbcal task
#
# to compile rbcal, type
#
#   make
#

COMPILE = gcc -g -c
LINK = gcc

RBOBJS = ../rb_tree/red_black_tree.o ../rb_tree/list.o ../rb_tree/misc.o

# note: make builds the first target (rbcal) by default:

rbcal: $(RBOBJS) rbcal.o
	$(LINK) -o rbcal rbcal.o $(RBOBJS)

run: rbcal
	./rbcal

debug: rbcal
	gdb rbcal

clean:
	rm -rf $(RBOBJS) rbcal rbcal.o

rbcal.o: rbcal.c
	$(COMPILE) -o rbcal.o rbcal.c

../rb_tree/red_black_tree.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/list.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/misc.o: 
	cd ../rb_tree; make -f Makefile

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/rbcal-submission.zip *
