CFLAGS +=$(subst -Wstrict-prototypes,,$(shell python3.5-config --cflags))
LDFLAGS+=$(subst -Wstrict-prototypes,,$(shell python3.5-config --ldflags))


main: main.o
	g++ -o $@ $? $(LDFLAGS)

%.o: %.cxx
	g++ $(CFLAGS) -fPIC -c $< -o $@ 


clean:
	rm -f *.o main
