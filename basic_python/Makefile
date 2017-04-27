
CFLAGS +=$(subst -Wstrict-prototypes,,$(shell python3.5-config --cflags))
LDFLAGS+=$(subst -Wstrict-prototypes,,$(shell python3.5-config --ldflags))

# the so file has to be _example.so. otherwise, you'll get the error:
#     ImportError: dynamic module does not define module export function (PyInit_example)
_example.so: example_wrap.o example.o
	g++ $(LDFLAGS) -shared $? -o _example.so

example_wrap.cxx: example.i
	swig -c++ -python $<

%.o: %.cxx
	g++ $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -f *.o example_wrap.cxx example_wrap.o example.so example.py

test: _example.so
	python3.5 test.py
