CC=gcc
LDFLAGS=`pkg-config --libs cairo`
CFLAGS=`pkg-config --cflags cairo`

all: vn

vn: src/main.c
	$(CC) $(CFLAGS) src/main.c -o vn $(LDFLAGS)

clean:
	rm vn
