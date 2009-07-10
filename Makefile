
PROGRAMS = hello-ansi hello-errno hello5in1

all: $(PROGRAMS)

hello-ansi: hello-ansi.c

hello-errno: hello-errno.c

hello5in1: hello5in1.c

clean:
	rm -f $(PROGRAMS)
	rm -f a.out
	rm -f *.o

