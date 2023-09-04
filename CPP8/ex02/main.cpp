#include "MutantStack.hpp"

#include <list>

int main()
{
    std::cout << "Test with MutantStack and int\n" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\nTest with MutantStack and string\n" << std::endl;

    MutantStack<std::string> mstackString;
    mstackString.push("john");
    mstackString.push("alice");
    std::cout << mstackString.top() << std::endl;
    mstackString.pop();
    std::cout << mstackString.size() << std::endl;
    mstackString.push("Victor");
    mstackString.push("alain");
    mstackString.push("george");
    //[...]
    mstackString.push("fenda");
    MutantStack<std::string>::iterator its = mstackString.begin();
    MutantStack<std::string>::iterator itse = mstackString.end();
    ++its;
    --its;
    while (its != itse)
    {
        std::cout << *its << std::endl;
        ++its;
    }
    std::stack<std::string> ss(mstackString);

    std::cout << "\nTest with containeur list and int\n" << std::endl;

    /* List */

    std::list<int> mstacklist;
    mstacklist.push_back(5);
    mstacklist.push_back(17);
    std::cout << mstacklist.back() << std::endl;
    mstacklist.pop_back();
    std::cout << mstacklist.size() << std::endl;
    mstacklist.push_back(3);
    mstacklist.push_back(5);
    mstacklist.push_back(737);
    //[...]
    mstacklist.push_back(0);
    std::list<int>::iterator itl = mstacklist.begin();
    std::list<int>::iterator itle = mstacklist.end();
    ++itl;
    --itl;
    while (itl != itle)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::list<int> sl(mstacklist);
    return (0);
}