CC      = gcc
CFLAGS  = -O0 -ggdb -fno-stack-protector -no-pie
LDFLAGS = -z execstack

TARGET  = binary-exploitation-hijack-to-shellcode-w
SRC     = $(TARGET).c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
