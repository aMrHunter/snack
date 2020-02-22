.PHONY:clean
CC=gcc
CFLAGSS=-Wall -g
BIN=bin/snack
OBJS=obj/main.o obj/disp.o obj/data.o obj/tools.o obj/active.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGSS) $^ -o $@
obj/%.o:src/%.c
	$(CC) $(CFLAGSS) -c $< -Iinc -o $@
clean:
	rm -f obj/*.o $(BIN)
