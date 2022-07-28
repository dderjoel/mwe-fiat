
CFLGAS=-Wall -g
BIN=mwe.out

.PHONY: time

all: $(BIN)

%.o: %.c
	$(CC) $(CFLGAS) -c $(<) -o $(@)

$(BIN): main.o helper.o
	$(CC) $(CFLGAS) $(^) -lm -o $(@)

run: $(BIN)
	bash -c " time ./$(<) 100000"


clean:
	rm -f *.o $(BIN)
