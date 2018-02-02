# Makefile for cexp
#
# to compile cmcmd, type
#
# make
#

COMPILE = gcc -g -c
LINK = gcc

CMD = ../cmcmd
OBJS = aduc.o cmd.o cmtio.o
HDRS = $(CMD)/aduc.h $(CMD)/cmd.h $(CMD)/cmtio.h

# note: make builds the first target (cmcmd) by default:

cmcmd: $(OBJS)
	$(LINK) -o cmcmd $(OBJS)

run: cmcmd
	./cmcmd

debug: cmcmd
	gdb cmcmd

clean:
	rm -rf $(OBJS)

aduc.o: $(CMD)/aduc.c $(HDRS)
	$(COMPILE) -o aduc.o -I$(CMD) $(CMD)/aduc.c

cmtio.o: $(CMD)/cmtio.c $(HDRS)
	$(COMPILE) -o cmtio.o -I$(CMD) $(CMD)/cmtio.c

cmd.o: cmd.c $(HDRS)
	$(COMPILE) -o cmd.o -I$(CMD) cmd.c

submit:
	rm -rf *.o cmcmd
	zip -r ~/exam-submission/cexp-submission.zip *
