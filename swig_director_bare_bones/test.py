

import unittest
import example

class MyFoo(example.Foo):
    def callback(self):
        print("hello from the python callback function")
        return 1

class TestFooDirector(unittest.TestCase):

    def test_cpp_version(self):
        f1 = example.Foo();
        example.set_foo(f1);
        self.assertEqual(example.call_foo_callback(), -1)

    def test_python_version(self):
        f2 = MyFoo();
        example.set_foo(f2);
        self.assertEqual(example.call_foo_callback(), 1)

        
if __name__ == '__main__':
    unittest.main()
