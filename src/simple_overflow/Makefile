CC      = gcc
CFLAGS  = -O0 -ggdb -fno-stack-protector -no-pie
LDFLAGS =

TARGET  = simple_overflow
SRC     = $(TARGET).c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
