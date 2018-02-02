# Makefile for sqlex task
#
# to compile sqlex, type
#
#   make
#

COMPILE = gcc -I../sqlutil -g -c 
LINK = gcc

SQL = ../sqlutil

SQLOBJS = ../sqlutil/sqlutil.o

# note: make builds the first target (sqlex) by default:

sqlex: $(SQLOBJS) sqlex.o
	$(LINK) -o sqlex sqlex.o $(SQLOBJS) -l sqlite3

run: sqlex
	./sqlex

debug: sqlex
	gdb sqlex

clean:
	rm -rf $(SQLOBJS) sqlex sqlex.o

sqlex.o: sqlex.c
	$(COMPILE) -o sqlex.o sqlex.c

$(SQL)/sqlutil.o: $(SQL)/sqlutil.c $(SQL)/sqlutil.h
	cd $(SQL); $(COMPILE) -o sqlutil.o sqlutil.c

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/sqlex-submission.zip *
