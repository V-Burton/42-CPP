#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN{
    public:
        RPN(std::string input);
        RPN(const RPN &rhs);
        RPN &operator=(const RPN &rhs);
        ~RPN();

    private:
        RPN();
        std::stack<int>     _value;
};
