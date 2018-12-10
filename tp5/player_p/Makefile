SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -I.. -fPIC# a completer
LDFLAGS= 
NAME1=p1
NAME2=p2
NAME3=p3
NAME4=p4

all: $(OBJS)
	gcc -v -o $(NAME1).so -shared player1.o
	gcc -v -o $(NAME2).so -shared player2.o
	gcc -v -o $(NAME3).so -shared player3.o
	gcc -v -o $(NAME4).so -shared player4.o

clean: 
	rm $(OBJS)
	rm $(NAME1).so
	rm $(NAME2).so
	rm $(NAME3).so
	rm $(NAME4).so
