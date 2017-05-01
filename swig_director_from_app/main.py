
import example

class MyFoo(example.Foo):
    def one(self):
        print("this is the new foo")
        return 1

    def two(self, str):
        print("this is the other two {}".format(str))
        return 2

foo = MyFoo();
example.register_cb(foo);
    
print("done with main.py")
