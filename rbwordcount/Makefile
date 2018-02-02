# Makefile for rbwordcount task
#
# to compile rbwordcount, type
#
#   make
#

COMPILE = gcc -g -c
LINK = gcc

RBOBJS = ../rb_tree/red_black_tree.o ../rb_tree/list.o ../rb_tree/misc.o
TESTOBJS = rbwordcount-test.o rbwordcount-nomain.o ../cutest-1.5/cutest.o

# note: make builds the first target (rbwordcount) by default:

rbwordcount: $(RBOBJS) rbwordcount.o
	$(LINK) -o rbwordcount rbwordcount.o $(RBOBJS)

run: rbwordcount
	./rbwordcount

test: rbwordcount-test
	./rbwordcount-test

debug: rbwordcount
	gdb rbwordcount

clean:
	rm -rf $(RBOBJS) $(TESTOBJS) rbwordcount rbwordcount-test rbwordcount.o

rbwordcount.o: rbwordcount.c
	$(COMPILE) -o rbwordcount.o rbwordcount.c

../rb_tree/red_black_tree.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/list.o: 
	cd ../rb_tree; make -f Makefile

../rb_tree/misc.o: 
	cd ../rb_tree; make -f Makefile

rbwordcount-nomain.o: rbwordcount.c rbwordcount-nomain.c
	$(COMPILE) -o rbwordcount-nomain.o rbwordcount-nomain.c

../cutest-1.5/cutest.o: ../cutest-1.5/CuTest.c
	cd ../cutest-1.5; $(COMPILE) -o cutest.o CuTest.c

rbwordcount-test.o: rbwordcount-test.c
	$(COMPILE) -o rbwordcount-test.o rbwordcount-test.c

rbwordcount-test: $(RBOBJS) $(TESTOBJS)
	$(LINK) -o rbwordcount-test $(RBOBJS) $(TESTOBJS)

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/rbwordcount-submission.zip *
