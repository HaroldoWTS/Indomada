CC=gcc
LDFLAGS=`pkg-config --libs cairo`
CFLAGS=`pkg-config --cflags cairo`

all: bin/vn

bin/vn: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/vn $(LDFLAGS)

test:  all
	bin/vn
clean:
	rm bin/*
	rm out/*
