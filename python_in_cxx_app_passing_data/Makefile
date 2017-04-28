CFLAGS +=$(subst -Wstrict-prototypes,,$(shell python3.5-config --cflags))
LDFLAGS+=$(subst -Wstrict-prototypes,,$(shell python3.5-config --ldflags))

test: main_function main_method
	export PYTHONPATH=.;./main_function multiply multiply 3 2
	export PYTHONPATH=.;./main_method multiply mc1 getvalue

main_function: main_function.o
	g++ -o $@ $? $(LDFLAGS)

main_method: main_method.o
	g++ -o $@ $? $(LDFLAGS)

%.o: %.cxx
	g++ -I. $(CFLAGS) -g -fPIC -c $< -o $@ 


clean:
	rm -f *.o main
