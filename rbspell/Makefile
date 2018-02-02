# Makefile for rbspell task
#
# to compile rbspell, type
#
#   make
#

COMPILE = gcc -g -c
LINK = gcc

RBOBJS = ../rb_tree/red_black_tree.o ../rb_tree/list.o ../rb_tree/misc.o

# note: make builds the first target (rbspell) by default:

rbspell: $(RBOBJS) rbspell.o
	$(LINK) -o rbspell rbspell.o $(RBOBJS)

run: rbspell
	./rbspell

debug: rbspell
	gdb rbspell

clean:
	rm -rf $(RBOBJS) rbspell rbspell.o

rbspell.o: rbspell.c
	$(COMPILE) -o rbspell.o rbspell.c

../rb_tree/red_black_tree.o: ../rb_tree/red_black_tree.c ../rb_tree/red_black_tree.h
	cd ../rb_tree; make -f Makefile

../rb_tree/list.o:  ../rb_tree/list.c ../rb_tree/list.h
	cd ../rb_tree; make -f Makefile

../rb_tree/misc.o: 
	cd ../rb_tree; make -f Makefile

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/rbspell-submission.zip *
