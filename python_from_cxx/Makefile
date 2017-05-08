
CFLAGS +=$(subst -Wstrict-prototypes,,$(shell python3.5-config --cflags))
LDFLAGS+=$(subst -Wstrict-prototypes,,$(shell python3.5-config --ldflags))

# the so file has to be _example.so. otherwise, you'll get the error:
#     ImportError: dynamic module does not define module export function (PyInit_example)
_cb.so: ObjWithPyCallback_wrap.o ObjWithCallback.o
	g++ -shared $? -o $@

ObjWithPyCallback_wrap.cxx: ObjWithPyCallback.i
	swig -c++ -python $<

%.o: %.cxx
	g++ $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf *.o ObjWithPyCallback_wrap.o ObjWithPyCallback_wrap.cxx _cb.so _cb.so cb.py __pycache__ 

test: _cb.so
	python3.5 example.py
