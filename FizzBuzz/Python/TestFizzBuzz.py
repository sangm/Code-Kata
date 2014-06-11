import fizzBuzz
import unittest
import random

class TestFizzBuzz(unittest.TestCase):

    def setUp(self):
        self.fizz = fizzBuzz.FizzBuzz()
    
    def test_correct_numbers(self):
        self.assertEqual(self.fizz.fizzBuzz(1), '1')
        self.assertEqual(self.fizz.fizzBuzz(2), '2')
        self.assertEqual(self.fizz.fizzBuzz(3), 'fizz')
        self.assertEqual(self.fizz.fizzBuzz(4), '4')
        self.assertEqual(self.fizz.fizzBuzz(5), 'buzz')
        self.assertEqual(self.fizz.fizzBuzz(6), 'fizz')
        self.assertEqual(self.fizz.fizzBuzz(10), 'buzz')
        self.assertEqual(self.fizz.fizzBuzz(15), 'fizzbuzz')

if __name__ == '__main__':
    unittest.main()
