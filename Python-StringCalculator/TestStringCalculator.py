import StringCalculator
import unittest
import random
import re

class TestStringCalculator(unittest.TestCase):
    
    def setUp(self):
        self.calc = StringCalculator.StringCalculator()

    def test_empy_string(self):
        self.assertEqual(self.calc.add(""), 0)
    def test_one_string(self):
        self.assertEqual(self.calc.add("1"), 1)
    def test_two_strings(self):
        self.assertEqual(self.calc.add("1,2"), 3)
        self.assertEqual(self.calc.add("3,4"), 7)
    def test_three_strings(self):
        self.assertEqual(self.calc.add("1,2,3"), 6)
    def test_random_number_strings(self):
        randNum = random.randint(1, 1000)
        randomNumbers = random.sample(range(1, 1000), randNum)
        randomString = ','.join([str(n) for n in randomNumbers])
        self.assertEqual(self.calc.add(randomString), sum(randomNumbers))
    def test_handle_new_line(self):
        self.assertEqual(self.calc.add(r'1\n2,3'), 6)
    def test_regex_api(self):
        simple = re.compile('abc')
        testString = r'abc'
        testString2 = r'aaaabc'
        testString3 = r'//?\n'

        # match returns something only if the string BEGINS with the regex
        self.assertIsNotNone(simple.match(testString))
        self.assertIsNone(simple.match(testString2))
        self.assertEqual(simple.match(testString).group(), 'abc')
        self.assertEqual(simple.search(testString2).group(), 'abc')

        regex = re.compile(r'^(//?).\\n')
        regex = regex.match(testString3)
        self.assertIsNotNone(regex)
        self.assertEqual(regex.group().replace('//','').replace(r'\n',''), '?')
        self.assertEqual(regex.end(), 5)
    def test_different_delimiter(self):
        self.assertEqual(self.calc.add(r'//x\n1x2x3x4'), 10)
    def test_negative_number_raises_exception(self):
        self.assertRaises(Exception, self.calc.add, '-1,2')
    def test_numbers_above_1000_ignored(self):
        self.assertEqual(self.calc.add('1,2,3000'), 3)
    def test_regex_api_long_delim(self):
        inputStr = r'[%][$][%%]'
        regex = re.compile(r'\[(.+?)\]')
        delim = []
        while inputStr:
            search = regex.search(inputStr)
            delim.append(search.group(1))
            inputStr = inputStr[search.end():]
        self.assertEqual(delim, ['%','$','%%'])
    def test_long_delimiter(self):
        inputString = r'//***\n1***2***3'
        self.assertEqual(self.calc.add(inputString), 6)
    def test_multi_delimiter(self):
        inputString = r'//[%][*]\n1%2*2'
        self.assertEqual(self.calc.add(inputString), 5)

if __name__ == '__main__':
    unittest.main()
