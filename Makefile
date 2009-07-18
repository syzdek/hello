
PROGRAMS = hello-ansi hello-errno hello-sine hello5in1

all: $(PROGRAMS)

hello5in1: hello5in1.c

hello-ansi: hello-ansi.c

hello-errno: hello-errno.c

hello-sine: hello-sine.c
	$(CC) -o hello-sine hello-sine.c -lm

$(PROGRAMS):

clean:
	rm -f $(PROGRAMS)
	rm -f a.out
	rm -f *.o

