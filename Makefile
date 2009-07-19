
PROGRAMS = hello-ansi hello-elipse hello-errno hello-sine hello5in1

all: $(PROGRAMS)

hello5in1: hello5in1.c

hello-ansi: hello-ansi.c

hello-elipse: hello-elipse.c
	$(CC) -o hello-elipse hello-elipse.c -lm

hello-errno: hello-errno.c

hello-sine: hello-sine.c
	$(CC) -o hello-sine hello-sine.c -lm

$(PROGRAMS):

clean:
	rm -f $(PROGRAMS)
	rm -f a.out
	rm -f *.o

