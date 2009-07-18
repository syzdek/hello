
PROGRAMS = hello-ansi hello-errno hello-sine hello5in1

all: $(PROGRAMS)

$(PROGRAMS):

clean:
	rm -f $(PROGRAMS)
	rm -f a.out
	rm -f *.o

