

import unittest
import example

class TestStringMethods(unittest.TestCase):

    def test_fact(self):
        self.assertEqual(example.fact(5), 120)

    def test_isupper(self):
        self.assertTrue(example.my_mod(7,3), 1)


if __name__ == '__main__':
    unittest.main()
