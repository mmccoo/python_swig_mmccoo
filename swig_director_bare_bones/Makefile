
CFLAGS +=$(subst -Wstrict-prototypes,,$(shell python3.5-config --cflags))
LDFLAGS+=$(subst -Wstrict-prototypes,,$(shell python3.5-config --ldflags))

# the so file has to be _example.so. otherwise, you'll get the error:
#     ImportError: dynamic module does not define module export function (PyInit_example)
_example.so: example_wrap.o example.o
	g++ $(LDFLAGS) -shared $? -o _example.so

example.o example_wrap.cxx: example.hxx

example_wrap.cxx: example.i
	swig -c++ -python -oh $(@:.cxx=.hxx) $< 

%.o: %.cxx
	g++ -I. $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf *.o __pycache__ example_wrap.cxx example_wrap.hxx example_wrap.o example.so example.py _example.so

test: _example.so
	python3.5 test.py
