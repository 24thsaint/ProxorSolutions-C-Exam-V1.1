# Makefile for rbdict task
#
# to compile rbdict, type
#
#   make
#

COMPILE = gcc -g -c
LINK = gcc

RBOBJS = ../rb_tree/red_black_tree.o ../rb_tree/list.o ../rb_tree/misc.o

# note: make builds the first target (rbdict) by default:

rbdict: $(RBOBJS) rbdict.o
	$(LINK) -o rbdict rbdict.o $(RBOBJS)

run: rbdict
	./rbdict

debug: rbdict
	gdb rbdict

clean:
	rm -rf $(RBOBJS) rbdict rbdict.o

rbdict.o: rbdict.c
	$(COMPILE) -o rbdict.o rbdict.c

../rb_tree/red_black_tree.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/list.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/misc.o: 
	cd ../rb_tree; make -f Makefile

rbdict-nomain.o: rbdict.c rbdict-nomain.c
	$(COMPILE) -o rbdict-nomain.o rbdict-nomain.c

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/rbdict-submission.zip *
