#include <iostream>
#include <iomanip>

const int RootLeftRight = 1;
const int RootRightLeft = 2;
const int LeftRightRoot = 3;
const int LeftRootRight = 4;
const int RightLeftRoot = 5;
const int RightRootLeft = 6;

void PrintNumTypeOptions() {
    std::cout << "\n1. Integer numbers\n";
    std::cout << "2. Real numbers\n";
}

void PrintBinaryTreeTraversalOptions() {
    std::cout << "Enter desired traversal:\n";
    std::cout << "\n";
    std::cout << "1. RootLeftRight" << "\n";
    std::cout << "2. RootRightLeft" << "\n";
    std::cout << "3. LeftRightRoot" << "\n";
    std::cout << "4. LeftRootRight" << "\n";
    std::cout << "5. RightLeftRoot" << "\n";
    std::cout << "6. RightRootLeft" << "\n";
    std::cout << "\n";
}

void PrintMenuOptions() {
    std::cout << "\n1. Insert element" << "\n";
    std::cout << "2. Balance tree" << "\n";
    std::cout << "3. Multiply every tree element by number" << "\n";
    std::cout << "4. Search for an element" << "\n";
    std::cout << "5. Print tree" << "\n";
    std::cout << "6. End program" << "\n";
    std::cout << "7. Run tests" << "\n";
    std::cout << "\n";
}

void PrintRandEnterOptions() {
    std::cout << "\n1. Random input" << "\n";
    std::cout << "2. Input from keyboard" << "\n";
}