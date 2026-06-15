CC      = gcc
CFLAGS  = -O0 -ggdb -fno-stack-protector -no-pie
LDFLAGS = -llzo2

TARGET = 3rd_party_vuln
SRC    = main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(TARGET)
