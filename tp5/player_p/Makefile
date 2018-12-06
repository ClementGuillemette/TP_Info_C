SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -I..# a completer
LDFLAGS= 
NAME=p1

all: $(OBJS)
	gcc -v -o $(NAME).so -shared $(OBJS)

clean: 
	rm $(OBJS)
	rm $(NAME).so
