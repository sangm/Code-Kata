#include <cassert>
#include <iostream>
#include <vector>

int chop(int n, std::vector<int> v) 
{
    if (v.size() == 0) return -1;
    if (v[0] == n) return 0;
    return -1;
}

int main() 
{
    assert(-1 == chop(1, std::vector<int> {}));
    assert(-1 == chop(1, std::vector<int> {0}));
    assert(0 == chop(1, std::vector<int> {1}));
    assert(0 == chop(1, std::vector<int> {1}));
    assert(0 == chop(1, std::vector<int> {1}));
    assert(0 == chop(1, std::vector<int> {1}));
    assert(0 == chop(1, std::vector<int> {1}));

    assert(-1 == chop(3, std::vector<int> {}));
    assert(-1 == chop(3, std::vector<int> {1}));
    assert(0  == chop(1, std::vector<int> {1}));
//
    assert(0  == chop(1, std::vector<int> {1, 3, 5}));
    assert(1  == chop(3, std::vector<int> {1, 3, 5}));
    assert(2  == chop(5, std::vector<int> {1, 3, 5}));
    assert(-1 == chop(0, std::vector<int> {1, 3, 5}));
    assert(-1 == chop(2, std::vector<int> {1, 3, 5}));
    assert(-1 == chop(4, std::vector<int> {1, 3, 5}));
    assert(-1 == chop(6, std::vector<int> {1, 3, 5}));
//
    assert(0  == chop(1, std::vector<int> {1, 3, 5, 7}));
    assert(1  == chop(3, std::vector<int> {1, 3, 5, 7}));
    assert(2  == chop(5, std::vector<int> {1, 3, 5, 7}));
    assert(3  == chop(7, std::vector<int> {1, 3, 5, 7}));
    assert(-1 == chop(0, std::vector<int> {1, 3, 5, 7}));
    assert(-1 == chop(2, std::vector<int> {1, 3, 5, 7}));
    assert(-1 == chop(4, std::vector<int> {1, 3, 5, 7}));
    assert(-1 == chop(6, std::vector<int> {1, 3, 5, 7}));
    assert(-1 == chop(8, std::vector<int> {1, 3, 5, 7}));

    std::cout << "All tests passed\n";
}
