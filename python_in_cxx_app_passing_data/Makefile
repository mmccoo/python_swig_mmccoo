CFLAGS +=$(subst -Wstrict-prototypes,,$(shell python3.5-config --cflags))
LDFLAGS+=$(subst -Wstrict-prototypes,,$(shell python3.5-config --ldflags))

test: main
	export PYTHONPATH=.;./main multiply multiply 3 2

main: main.o
	g++ -o $@ $? $(LDFLAGS)

%.o: %.cxx
	g++ -I. $(CFLAGS) -g -fPIC -c $< -o $@ 


clean:
	rm -f *.o main
