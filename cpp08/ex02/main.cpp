#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

void print_separator(const std::string& title) {
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main()
{
    // --- MUTANT STACK SECTION ---
    print_separator("Testing MutantStack");
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top:  " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); // Testing copy to base class

    // --- STD::LIST SECTION ---
    // The subject asks to replace MutantStack with std::list to show 
    // the output is identical.
    print_separator("Testing std::list (Comparison)");
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    // std::list doesn't have 'top()', it uses 'back()'
    std::cout << "Back: " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator it_l = mlist.begin();
    std::list<int>::iterator ite_l = mlist.end();
    
    ++it_l;
    --it_l;
    while (it_l != ite_l) {
        std::cout << *it_l << std::endl;
        ++it_l;
    }

    return 0;
}
