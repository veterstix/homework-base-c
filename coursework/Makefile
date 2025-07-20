TARGET = temp-stat
CC = gcc
# make run DATAFILE=temperature_small.csv
DATAFILE = temperature_big.csv
SRC = main.c temp_api.c
OBJECTS = $(SRC:.c=.o)

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) -c $< -o $@

run0: all
	./$(TARGET)

run1: all
	./$(TARGET) -f $(DATAFILE)

run2: all
	./$(TARGET) -m 2

run3: all
	./$(TARGET) -f $(DATAFILE) -m 7

run: all
	./$(TARGET) -f $(DATAFILE)
	./$(TARGET) -f $(DATAFILE) -m 7

clean:
	rm -f $(TARGET) *.o

# just for fun
# tests

MONTHLIST = 1 2 3 4 5 6 7 8 9 10 11 12
define PROCESS_ITEM
	./$(TARGET) -f $(DATAFILE) -m $(1)
endef

tests:
	$(foreach item,$(MONTHLIST),$(call PROCESS_ITEM,$(item)))

