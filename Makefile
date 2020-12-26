src = $(wildcard src/*.c)
obj = $(src:.c=.o)

CFLAGS = -Wall -O3 -march=x86-64 -s -Iinclude -std=gnu99
LDFLAGS = -lm

lumamist.exe: $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	del /S /Q *.o lumamist.exe
