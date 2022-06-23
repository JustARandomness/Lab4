#include <iostream>
#include <vector>
#include "ErrorInfo.hpp"
#include "RandEnter.hpp"
#include "Options.hpp"
#include "BinaryTree.hpp"
#include <variant>


int main() {
    srand(time(NULL));

    ErrorInfo errorInfo;
    errorInfo.SetErrorCode(NoErrYetCode);

    int menuEnter;
    int traversalEnter;
    int numTypeEnter;
    int endProgram = 0;
    int randEnter;
    double doubleNumber = 0.0;

    PrintNumTypeOptions();

    while (errorInfo.GetErrorCode() != NoErrorCode) {
        std::cin >> numTypeEnter;
        if (numTypeEnter == 1 || numTypeEnter == 2) {
            errorInfo.SetErrorCode(NoErrorCode);
            break;
        }
        else {
            errorInfo.SetErrorCode(NoSuchOptionFoundCode);
            errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
            errorInfo.GetErrorMsg();
        }
    }

    errorInfo.SetErrorCode(NoErrYetCode);

    std::variant<BinaryTree<int>, BinaryTree<double>> treeVar;

    while (endProgram != 1) {
        PrintMenuOptions();
        std::cin >> menuEnter;
        switch(menuEnter) {
            case 1:
                PrintRandEnterOptions();
                while (errorInfo.GetErrorCode() != NoErrorCode) {
                    std::cin >> randEnter;
                    if (randEnter == 1 || randEnter == 2) {
                        errorInfo.SetErrorCode(NoErrorCode);
                        break;
                    }
                    else {
                        errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                        errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                        errorInfo.GetErrorMsg();
                    }
                }

                errorInfo.SetErrorCode(NoErrYetCode);

                if (numTypeEnter == 1) {
                    if (randEnter == 1) {
                        doubleNumber = RandEnterInt();
                        std::visit([&treeVar, doubleNumber](auto binaryTree) {
                            binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                            treeVar = binaryTree;
                        }, treeVar);
                    }
                    else {
                        std::cout << "Enter number you want to insert:\n";
                        while (errorInfo.GetErrorCode() != NoErrorCode) {
                            std::cin >> doubleNumber;
                            if (int(doubleNumber) != doubleNumber) {
                                errorInfo.SetErrorCode(WrongNumTypeCode);
                                errorInfo.CopyErrorMsg(WrongNumTypeMsg);
                                errorInfo.GetErrorMsg();
                            } else {
                                errorInfo.SetErrorCode(NoErrorCode);
                                break;
                            }
                        }

                        errorInfo.SetErrorCode(NoErrYetCode);

                        std::visit([&treeVar, doubleNumber](auto binaryTree) {
                            binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                            treeVar = binaryTree;
                        }, treeVar);
                    }
                }
                else {
                    if (randEnter == 1) {
                        doubleNumber = RandEnterDouble();
                        std::cout << doubleNumber;
                        std::visit([&treeVar, doubleNumber](auto binaryTree) {
                            binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                            treeVar = binaryTree;
                        }, treeVar);
                    }
                    else {
                        std::cin >> doubleNumber;
                        std::visit([&treeVar, doubleNumber](auto binaryTree) {
                            binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                            treeVar = binaryTree;
                        }, treeVar);
                    }
                }
                break;
            case 2:
                std::visit([&treeVar](auto binaryTree) { binaryTree = binaryTree.BalanceTree(); treeVar = binaryTree;}, treeVar);
                std::cout << "\nTree is now balanced\n";
                break;
            case 3:
                if (numTypeEnter == 1) {
                    while (errorInfo.GetErrorCode() != NoErrorCode) {
                        std::cin >> doubleNumber;
                        if (int(doubleNumber) != doubleNumber) {
                            errorInfo.SetErrorCode(WrongNumTypeCode);
                            errorInfo.CopyErrorMsg(WrongNumTypeMsg);
                            errorInfo.GetErrorMsg();
                        }
                        else {
                            errorInfo.SetErrorCode(NoErrorCode);
                            break;
                        }
                    }

                    errorInfo.SetErrorCode(NoErrYetCode);

                    std::visit([&treeVar, doubleNumber](auto binaryTree) {binaryTree.Map([doubleNumber](auto x) {return x * doubleNumber;}); treeVar = binaryTree;}, treeVar);
                }
                else {
                    std::cin >> doubleNumber;
                    std::visit([&treeVar, doubleNumber](auto binaryTree) {binaryTree.Map([doubleNumber](auto x) {return x * doubleNumber;}); treeVar = binaryTree;}, treeVar);
                }
                break;
            case 4:
                std::cout << "Enter number you want to find:\n";
                std::cin >> doubleNumber;
                try {
                    std::visit([doubleNumber](auto binaryTree) {binaryTree.Search(doubleNumber);}, treeVar);
                }
                catch(ErrorInfo errorInfo1) {
                    errorInfo.GetErrorMsg();
                    std::cout << std::endl;
                }
                break;
            case 5:
                PrintBinaryTreeTraversalOptions();

                while (errorInfo.GetErrorCode() != NoErrorCode) {
                    std::cin >> traversalEnter;
                    if (traversalEnter == 1 || traversalEnter == 2 || traversalEnter == 3 || traversalEnter == 4 || traversalEnter == 5 || traversalEnter == 6) {
                        errorInfo.SetErrorCode(NoErrorCode);
                        break;
                    }
                    else {
                        errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                        errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                        errorInfo.GetErrorMsg();
                    }
                }

                errorInfo.SetErrorCode(NoErrYetCode);

                std::cout << std::visit([traversalEnter](auto binaryTree) {return binaryTree.ConvertTreeToString(traversalEnter);}, treeVar);
                break;
            case 6:
                endProgram = 1;
                break;
            default:
                errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                errorInfo.GetErrorMsg();
                break;
        }
    }
    return 0;
}
