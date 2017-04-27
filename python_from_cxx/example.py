import cb

def foo(x=None):
    print("Hello from Foo!")
    # I'd like x to be a reference to a ObjWithPyCallback object.
    print(x)

def bar(x=None):
    print("Hello from Bar!")
    # I'd like x to be a reference to a ObjWithPyCallback object.
    print(x)


class myclass(cb.ObjWithPyCallback):
    def __init__(self):
        print("in my init")
        cb.ObjWithPyCallback.__init__(self)
        self.setCallback(lambda: self.mymethod())

    def mymethod(self):
        print("Hello from my method")

    
o = cb.ObjWithPyCallback()
o.setCallback(foo)
o.call()

o2 = cb.ObjWithPyCallback()
o.setCallback(bar)
o.call()

mc = myclass()
mc.call()

def redefinedmethod(self):
    print("hello from the new method")

myclass.mymethod = redefinedmethod
mc.call()

print(str(o))


