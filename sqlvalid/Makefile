# Makefile for sqlvalid task
#
# to compile sqlvalid, type
#
#   make
#

COMPILE = gcc -I../sqlutil -g -c 
LINK = gcc

SQL = ../sqlutil

SQLOBJS = ../sqlutil/sqlutil.o

# note: make builds the first target (sqlvalid) by default:

sqlvalid: $(SQLOBJS) sqlvalid.o
	$(LINK) -o sqlvalid sqlvalid.o $(SQLOBJS) -l sqlite3

run: sqlvalid
	./sqlvalid

debug: sqlvalid
	gdb sqlvalid

clean:
	rm -rf $(SQLOBJS) sqlvalid sqlvalid.o

sqlvalid.o: sqlvalid.c
	$(COMPILE) -o sqlvalid.o sqlvalid.c

$(SQL)/sqlutil.o: $(SQL)/sqlutil.c $(SQL)/sqlutil.h
	cd $(SQL); $(COMPILE) -o sqlutil.o sqlutil.c

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/sqlvalid-submission.zip *
