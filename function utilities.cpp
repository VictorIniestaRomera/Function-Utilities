#include <iostream>

#include "items.h"
#include "dictionary.h"
#include "core.h"

int main() {
    /*util::Items<int> it;
    it.push_back(1);
    it.push_back(7);
    it.insert(it.begin(), 8);

    util::Items<int> it2;
    it2.fill(4, 9);
    
    std::cout << it;
    std::cout << std::endl;
    std::cout << it2;

    it.swap(it2);
    it2.copy(2, it);

    std::cout << std::endl;
    std::cout << it;
    std::cout << std::endl;
    std::cout << it2;*/

    /*Dictionary<int, char> dic;
    dic.insert(1, 'a');
    dic.insert(2, 'b');
    std::cout << dic.at(0);
    dic.remove(1);
    std::cout << dic.at(0);*/

    util::Core<int>* cor = new util::Core<int>();
    util::Core<int>* cor2 = new util::Core<int>();
    util::Core<int>* cor3 = new util::Core<int>();

    cor->push_back(1);
    cor->push_front(2);
    cor->push_front(9);
    cor->push_back(3);

    cor2->copy(cor);
    cor2->pop_back();

    cor3->copy(cor2);

    std::cout << cor;
    std::cout << std::endl;
    std::cout << cor2;
    std::cout << std::endl;
    std::cout << cor3;
}