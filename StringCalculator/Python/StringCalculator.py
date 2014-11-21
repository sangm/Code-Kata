import unittest
import re

class StringCalculator(object):
    def s_sum(self, numbers):
        numbers = [int(_) for _ in numbers if int(_) <= 1000]
        neg_numbers = filter(lambda x: str(x) if x < 0 else None, numbers)
        if neg_numbers:
            error_message = ','.join(str(_) for _ in neg_numbers)
            raise Exception("Negative Numbers: [%s]" % error_message)
        return sum(numbers)
    def s_match(self, delimiter, numbers):
        pattern = re.compile(r'//\[?(.+?)\]?(?:\[(.+?)\])?\n(.+)')
        match = pattern.match(numbers)
        if match:
            groups = filter(lambda x: x, match.groups())
            numbers = groups[-1]
            delimiter =  '|'.join([re.escape(_) for _ in groups[:-1]])
        return (delimiter + '|\n',numbers)
    def s_add(self, numbers):
        if len(numbers) == 0: return 0
        (delimiter,numbers) = self.s_match(',',numbers)
        numbers = re.split(delimiter,numbers)
        return self.s_sum(numbers)

class StringCalculatorTest(unittest.TestCase):
    def setUp(self):
        self.s_add = StringCalculator().s_add
    def test_returns_zero_given_empty_string(self):
        self.assertEqual(0, self.s_add(""))
    def test_returns_number_given_single_number(self):
        self.assertEqual(1, self.s_add("1"))
        self.assertEqual(2, self.s_add("2"))
        self.assertEqual(3, self.s_add("3"))
    def test_returns_sum_of_two_numbers(self):
        self.assertEqual(3, self.s_add("1,2"))
    def test_returns_sum_of_any_numbers(self):
        self.assertEqual(10, self.s_add("1,1,1,1,1,1,1,1,1,1"))
        self.assertEqual(20, self.s_add("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1"))
    def test_handles_newline_characters(self):
        self.assertEqual(6, self.s_add("1\n2,3"))
    def test_handles_changing_delimiter(self):
        self.assertEqual(3, self.s_add("//;\n1;2"))
    def test_throws_exception_if_negative_number_is_given(self):
        with self.assertRaises(Exception) as context:
            self.s_add("-1,-2,3")
        self.assertEqual("Negative Numbers: [-1,-2]", context.exception.message)
    def test_ignores_numbers_greater_than_1000(self):
        self.assertEqual(1001, self.s_add("1000,1"))
        self.assertEqual(1000, self.s_add("1000, 1001"))
    def test_delimiters_can_be_of_any_length_given_format(self):
        self.assertEqual(6, self.s_add("//[***]\n1***2***3"))
    def test_multiple_delimiters(self):
        self.assertEqual(6, self.s_add("//[*][%]\n1*2%3"))
    def test_multiple_delimiters_can_be_multiple_characters(self):
        self.assertEqual(6, self.s_add("//[***][%%%]\n1***2%%%3"))

class RegexPythonTest(unittest.TestCase):
    """ Testing how the regex library is implemented in Python """
    def test_compile_pattern_for_single_character(self):
        pattern = re.compile('a')
        match = pattern.match('a')
        self.assertTrue(match)
    def test_compile_pattern_to_match_any_character(self):
        pattern = re.compile(r'\w')
        match = pattern.match('a')
        for i in xrange(10):
            match = pattern.match(str(i))
            self.assertTrue(match)
    def test_compile_pattern_for_groups(self):
        pattern = re.compile(r'(\w)(\w)')
        match = pattern.match('ab')
        self.assertEqual(2, len(match.groups()))
    def test_compile_pattern_capture_delimitter(self):
        pattern = re.compile(r'//(.)\n(.+)')
        match = pattern.match('//;\n1;2')
        self.assertTrue(match)
        groups = match.groups()
        self.assertEqual(2, len(match.groups()))
        self.assertEqual(';', groups[0])
        self.assertEqual('1;2',groups[1])
    def test_extract_multiple_delimiters(self):
        string = "//[***]\n1***2***3"
        pattern = re.compile(r'//\[(.+(?=\])+)\]\n(.+)')
        match = pattern.match(string)
        self.assertTrue(match)
        groups = match.groups()
        self.assertEqual(2, len(match.groups()))
        self.assertEqual('***', groups[0])
        self.assertEqual('1***2***3', groups[1])
    def test_how_regex_pattern_handles_combination_of_both_single_and_multiple_delimiters(self):
        pattern = re.compile(r'//\[(.+(?=\])+)\]\n(.+)|//(.)\n(.+)')
        match = pattern.match('//;\n1;2')
        self.assertTrue(match)
        groups = match.groups()
        self.assertEqual(4, len(groups)) # Python matches all the possible groups, in this case, the first 2 groups are None
        groups = filter(lambda x: x, groups) # Filter out all the None values
        self.assertEqual(2, len(groups))
        self.assertEqual(';', groups[0])
        self.assertEqual('1;2', groups[1])

        match = pattern.match('//[***]\n1***2***3')
        self.assertTrue(match)
        groups = match.groups()
        self.assertEqual(4, len(groups))
        groups = filter(lambda x: x, groups)
        self.assertEqual(2, len(groups))
        self.assertEqual('***', groups[0])
        self.assertEqual('1***2***3', groups[1])
    def test_how_regex_pattern_handles_splitting_with_special_characters(self):
        string = '1***2***3' # have to call re.escape to match arbitrary literal string
        self.assertEqual(re.split(re.escape('***'), string), ['1','2','3'])
    def test_regex_pattern_extracts_multiple_delimiters(self):
        string = '//[*][%]\n1*2%3'
        pattern = re.compile(r'//((?:\[.\])+)\n(.+)')
        match = pattern.match(string)
        self.assertTrue(match)
        self.assertEqual('[*][%]', match.group(1))
        
if __name__ == '__main__':
    unittest.main()
