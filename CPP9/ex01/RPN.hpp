#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <limits>

class RPN{
    public:
        RPN(std::string input);
        RPN(const RPN &rhs);
        RPN &operator=(const RPN &rhs);
        ~RPN();

    private:
        RPN();
        std::stack<long>     _value;
};
