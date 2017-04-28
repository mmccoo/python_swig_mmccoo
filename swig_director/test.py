

import unittest
import example

class MyFoo(example.Foo):
    def one(self):
        print("this is the new foo")
        return 1

    def two(self, str):
        print("this is the other two {}".format(str))
        return 2

class TestStringMethods(unittest.TestCase):

    def test_fact(self):
        self.assertEqual(example.fact(5), 120)

    def test_isupper(self):
        self.assertTrue(example.my_mod(7,3), 1)

    def test_my_var(self):
        self.assertEqual(example.cvar.My_variable, 3.0)
        example.cvar.My_variable = 10
        self.assertEqual(example.cvar.My_variable, 10.0)
        self.assertEqual(example.get_var(), 10.0)

    def test_director(self):
        foo = example.Foo();
        self.assertEqual(foo.one(), -1)
        self.assertEqual(foo.two("the arg"), -2)
        self.assertEqual(example.call_director(foo), -3)

    def test_director(self):
        foo = MyFoo()
        self.assertEqual(foo.one(), 1)
        self.assertEqual(foo.two("the arg"), 2)
        self.assertEqual(example.call_director(foo), 3)
        
if __name__ == '__main__':
    unittest.main()
