CFLAGS+=$(shell python-config --cflags)
LDFLAGS+=$(shell python-config --ldflags)

main: main.o
	g++ -o $@ $? $(LDFLAGS)

%.o: %.cxx
	@echo hello
	g++ $(CFLAGS) -fPIC -c $< -o $@ 


