import StringCalculator
import unittest
import random
import re

class TestStringCalculator(unittest.TestCase):
    
    def setUp(self):
        self.stringCalc = StringCalculator.StringCalculator()

    def test_empty_string(self):
        self.assertEqual(self.stringCalc.add(""), 0)
    def test_one_string(self):
        self.assertEqual(self.stringCalc.add("1"), 1)
        self.assertEqual(self.stringCalc.add("2"), 2)
    def test_two_strings(self):
        self.assertEqual(self.stringCalc.add("1,2"), 3)
        self.assertEqual(self.stringCalc.add("5,6"), 11)
    def test_one_random_string(self):
        randomNum = random.randint(1, 10000)
        self.assertEqual(self.stringCalc.add(str(randomNum)), randomNum)
    def test_two_random_strings(self):
        randomNumOne = random.randint(1, 100)
        randomNumTwo = random.randint(2, 10000)
        inputNums = ','.join([str(randomNumOne), str(randomNumTwo)])
        self.assertTrue(isinstance(inputNums,str))
        self.assertEqual(self.stringCalc.add(inputNums), randomNumOne+randomNumTwo)
    def test_three_strings(self):
        self.assertEqual(self.stringCalc.add('1,2,3'), 6)
        self.assertEqual(self.stringCalc.add('3,5,6,7'), 21)
    def test_random_number_of_strings(self):
        randomNum = random.randint(1, 100)
        randomList = random.sample(range(1000), randomNum)
        sumNum = sum(randomList)
        inputNums = ','.join([str(x) for x in randomList])
        self.assertEqual(self.stringCalc.add(inputNums), sumNum)
    def test_newline_character(self):
        inputNums = '1\n2,3'
        self.assertEqual(self.stringCalc.add(inputNums), 6)
    def test_regex_api(self):
        testString1 = 'abc'
        simple = re.compile('abc')
        self.assertEqual(simple.search(testString1).group(), testString1)

        testString = r'//;\n1;2'
        regex = re.compile(r'^(//?).\\n')
        self.assertEqual(regex.search(testString).group(), r'//;\n')

        index = regex.search(testString).end()
        self.assertEqual(testString[index:], '1;2')
    def test_default_delimiter(self):
        inputString = r'//?\n1?2?3'
        self.assertEqual(self.stringCalc.add(inputString), 6)




    






if __name__ == '__main__':
    unittest.main()
