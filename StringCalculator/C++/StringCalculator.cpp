#include "StringCalculator.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>


int StringCalculator::add(std::string num) 
{
    if (num.length() == 0) 
        return 0;
    int result;
    std::vector<int> nums;
    
    size_t index = num.find("\\n");
    while (index != std::string::npos) {
        num.replace(index, std::string("\\n").length(), ",");
        index = num.find("\\n");
    }

    std::istringstream ss(num);
    std::string token;

    while(std::getline(ss, token, ',')) {
        std::istringstream(token) >> result;
        nums.push_back(result);
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
}
