#include <iostream>

void Test() {
    BinaryTree<int> binaryTree;
    int a[3] = {1, 2, -3};
    for (auto i : a) {
        binaryTree.Insert(binaryTree.CreateTreeElement(i));
    }
    std::string basicString = binaryTree.ConvertTreeToString(RootLeftRight);
    if (basicString[0] == '1' && basicString[2] == '-' && basicString[3] == '3' && basicString[5] == '2') {
        std::cout << "\nInsert working properly\n";
        std::cout << "TreeToString working properly\n";
    }
    std::vector<int> vector = binaryTree.TreeToSortedArray();
    if (vector[0] == -3 && vector[1] == 1 && vector[2] == 2) {
        std::cout << "TreeToSortedArray working properly\n";
    }
    binaryTree.Map([](auto x) {return x * 2;});
    basicString = binaryTree.ConvertTreeToString(RootLeftRight);
    if (basicString[0] == '2' && basicString[2] == '-' && basicString[3] == '6' && basicString[5] == '4') {
        std::cout << "Map working properly\n";
    }
    int b[3] = {1, 2, 3};
    BinaryTree<int> newBinaryTree;
    for (auto i : b) {
        newBinaryTree.Insert(newBinaryTree.CreateTreeElement(i));
    }
    newBinaryTree.BalanceTree();
    basicString = newBinaryTree.ConvertTreeToString(LeftRootRight);
    if (basicString[0] == '1' && basicString[2] == '2' && basicString[4] == '3') {
        std::cout << "BalanceTree works properly\n";
    }
    std::cout << "\nTests finished\n";
}