CC      = gcc
CFLAGS  = -O0 -ggdb -fstack-protector-all -no-pie
LDFLAGS = -z execstack

TARGET  = binary-exploitation-canary-bypass
SRC     = $(TARGET).c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
