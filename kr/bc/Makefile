CC = gcc
CFLAGS = -Wall -g
SRC = implements.c bc.c
OBJ = $(SRC:.c=.o)
EXEC = bc

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)   # 这里必须是Tab缩进

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@  # 这里也必须是Tab缩进

clean:
	rm -f $(OBJ) $(EXEC)