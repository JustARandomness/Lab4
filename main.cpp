#include <iostream>
#include <vector>
#include "ErrorInfo.hpp"
#include "RandEnter.hpp"
#include "Options.hpp"
#include "BinaryTree.hpp"


int main() {
    int traversalEnter;
    int menuEnter;
    int numTypeEnter;
    BinaryTree<int> binaryTree;
    for (int i = 0; i < 10; ++i) {
        binaryTree.Insert(binaryTree.CreateTreeElement(RandEnterInt()));
    }
    std::cout << binaryTree;
    std::cout << "\n";
    binaryTree.Map([](auto x) {return x*2;});
    std::cout << binaryTree;
    return 0;
}
