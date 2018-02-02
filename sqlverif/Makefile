# Makefile for sqlverif task
#
# to compile sqlverif, type
#
#   make
#

COMPILE = gcc -I../sqlutil -g -c 
LINK = gcc

SQL = ../sqlutil

SQLOBJS = ../sqlutil/sqlutil.o 

# note: make builds the first target (sqlverif) by default:

sqlverif: $(SQLOBJS) sqlverif.o
	$(LINK) -o sqlverif sqlverif.o $(SQLOBJS) -l sqlite3

run: sqlverif
	./sqlverif

debug: sqlverif
	gdb sqlverif

clean:
	rm -rf $(SQLOBJS) sqlverif sqlverif.o

sqlverif.o: sqlverif.c
	$(COMPILE) -o sqlverif.o sqlverif.c

$(SQL)/sqlutil.o: $(SQL)/sqlutil.c $(SQL)/sqlutil.h
	cd $(SQL); $(COMPILE) -o sqlutil.o sqlutil.c

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/sqlvalid-submission.zip *
