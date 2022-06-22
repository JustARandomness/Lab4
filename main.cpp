#include <iostream>
#include <vector>
#include "ErrorInfo.hpp"
#include "RandEnter.hpp"
#include "Options.hpp"
#include "BinaryTree.hpp"


int main() {
    int a[6] = {-1, 0, 1, 3, 7, 2};
    BinaryTree<int> binaryTree;
    for (int i : a) {
        binaryTree.Insert(binaryTree.CreateTreeElement(i));
    }

    std::cout << binaryTree;

    std::vector<int> temp = binaryTree.TreeToSortedArray();

    for (int i = 0; i < size(temp); ++i) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;

    binaryTree = binaryTree.BalancingTree();

    std::cout << binaryTree;

    try {
        binaryTree.Search(0);
    }
    catch (ErrorInfo errorInfo) {
        errorInfo.GetErrorMsg();
    }
    return 0;
}
