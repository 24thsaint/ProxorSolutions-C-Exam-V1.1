# Makefile for exdst task
#
# to compile exdst, type
#
#   make
#

COMPILE = gcc -g -c
LINK = gcc

# note: make builds the first target (exdst) by default:

exdst: exdst.o
	$(LINK) -o exdst exdst.o -lm

run: exdst
	./exdst

debug: exdst
	gdb exdst

clean:
	rm -rf exdst exdst.o

exdst.o: exdst.c
	$(COMPILE) -o exdst.o exdst.c

submit:
	rm -rf *.o exdst
	zip -r ~/exam-submission/exdst-submission.zip *
