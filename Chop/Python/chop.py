import unittest

def chop(n, li):
    if (len(li) == 0): return -1
    
    left = 0; right = len(li) - 1;
    while(left <= right):
        mid = (left + right) / 2
        midElement = li[mid]
        if (n == midElement): return mid
        elif (n < midElement): right = mid - 1
        elif (n > midElement): left = mid + 1
    return -1

class ChopTest(unittest.TestCase):
    def test_Should_Return_Negative_One_If_List_Is_Empty(self):
        self.assertEqual(-1, chop(3, []))
    def test_Should_Return_Negative_One_If_Not_In_List(self):
        self.assertEqual(-1, chop(3, [1]))
    def test_Should_Return_Index_If_Single_Item_In_A_List(self):
        self.assertEqual(0, chop(1, [1]))
    def test_Should_Return_Index_Given_List_Is_Longer_Than_One(self):
        self.assertEqual(0, chop(0, [0, 1, 2]))
    def test_Should_Return_Index_That_Is_Not_The_First_Index(self):
        self.assertEqual(1, chop(0, [1, 0, 2]))
    def test_Should_Return_Correct_Output_Given_Tests_From_CodeKata(self):
        self.assertEqual(-1, chop(3, []))
        self.assertEqual(-1, chop(3, [1]))
        self.assertEqual(0,  chop(1, [1]))
        self.assertEqual(0,  chop(1, [1, 3, 5]))
        self.assertEqual(1,  chop(3, [1, 3, 5]))
        self.assertEqual(2,  chop(5, [1, 3, 5]))
        self.assertEqual(-1, chop(0, [1, 3, 5]))
        self.assertEqual(-1, chop(2, [1, 3, 5]))
        self.assertEqual(-1, chop(4, [1, 3, 5]))
        self.assertEqual(-1, chop(6, [1, 3, 5]))
        self.assertEqual(0,  chop(1, [1, 3, 5, 7]))
        self.assertEqual(1,  chop(3, [1, 3, 5, 7]))
        self.assertEqual(2,  chop(5, [1, 3, 5, 7]))
        self.assertEqual(3,  chop(7, [1, 3, 5, 7]))
        self.assertEqual(-1, chop(0, [1, 3, 5, 7]))
        self.assertEqual(-1, chop(2, [1, 3, 5, 7]))
        self.assertEqual(-1, chop(4, [1, 3, 5, 7]))
        self.assertEqual(-1, chop(6, [1, 3, 5, 7]))
        self.assertEqual(-1, chop(8, [1, 3, 5, 7]))

if __name__ == '__main__':
    unittest.main()
