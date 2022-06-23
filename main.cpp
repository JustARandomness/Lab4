#include <iostream>
#include <vector>
#include "ErrorInfo.hpp"
#include "RandEnter.hpp"
#include "Options.hpp"
#include "BinaryTree.hpp"
#include <variant>
#include "Test.hpp"


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

    if (numTypeEnter == 1) {
        BinaryTree<int> binaryTree;
        while (endProgram != 1) {
            PrintMenuOptions();
            std::cin >> menuEnter;
            switch (menuEnter) {
                case 1:
                    PrintRandEnterOptions();
                    while (errorInfo.GetErrorCode() != NoErrorCode) {
                        std::cin >> randEnter;
                        if (randEnter == 1 || randEnter == 2) {
                            errorInfo.SetErrorCode(NoErrorCode);
                            break;
                        } else {
                            errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                            errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                            errorInfo.GetErrorMsg();
                        }
                    }

                    errorInfo.SetErrorCode(NoErrYetCode);

                    if (randEnter == 1) {
                        doubleNumber = RandEnterInt();
                        binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                    } else {
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

                        binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                    }
                    break;
                case 2:
                    binaryTree = binaryTree.BalanceTree();
                    std::cout << "\nTree is now balanced\n";
                    break;
                case 3:
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
                        binaryTree.Map([doubleNumber](auto x) { return x * doubleNumber; });
                    break;
                case 4:
                    std::cout << "Enter number you want to find:\n";
                    std::cin >> doubleNumber;
                    try {
                        binaryTree.Search(doubleNumber);
                    }
                    catch (ErrorInfo errorInfo1) {
                        errorInfo1.GetErrorMsg();
                        std::cout << std::endl;
                    }
                    break;
                case 5:
                    PrintBinaryTreeTraversalOptions();

                    while (errorInfo.GetErrorCode() != NoErrorCode) {
                        std::cin >> traversalEnter;
                        if (traversalEnter == 1 || traversalEnter == 2 || traversalEnter == 3 || traversalEnter == 4 ||
                            traversalEnter == 5 || traversalEnter == 6) {
                            errorInfo.SetErrorCode(NoErrorCode);
                            break;
                        } else {
                            errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                            errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                            errorInfo.GetErrorMsg();
                        }
                    }

                    errorInfo.SetErrorCode(NoErrYetCode);

                    std::cout << binaryTree.ConvertTreeToString(traversalEnter);
                    break;
                case 6:
                    endProgram = 1;
                    break;
                case 7:
                    Test();
                    break;
                default:
                    errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                    errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                    errorInfo.GetErrorMsg();
                    break;
            }
        }
    }
    else {
        BinaryTree<double> binaryTree;
        while (endProgram != 1) {
            PrintMenuOptions();
            std::cin >> menuEnter;
            switch (menuEnter) {
                case 1:
                    PrintRandEnterOptions();
                    while (errorInfo.GetErrorCode() != NoErrorCode) {
                        std::cin >> randEnter;
                        if (randEnter == 1 || randEnter == 2) {
                            errorInfo.SetErrorCode(NoErrorCode);
                            break;
                        } else {
                            errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                            errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                            errorInfo.GetErrorMsg();
                        }
                    }

                    errorInfo.SetErrorCode(NoErrYetCode);


                    if (randEnter == 1) {
                        doubleNumber = RandEnterDouble();
                        binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                    } else {
                        std::cin >> doubleNumber;
                        binaryTree.Insert(binaryTree.CreateTreeElement(doubleNumber));
                    }
                    break;
                case 2:
                    binaryTree = binaryTree.BalanceTree();
                    std::cout << "\nTree is now balanced\n";
                    break;
                case 3:
                    std::cin >> doubleNumber;
                    binaryTree.Map([doubleNumber](auto x) { return x * doubleNumber; });
                    break;
                case 4:
                    std::cout << "Enter number you want to find:\n";
                    std::cin >> doubleNumber;
                    try {
                        binaryTree.Search(doubleNumber);
                    }
                    catch (ErrorInfo errorInfo1) {
                        errorInfo1.GetErrorMsg();
                        std::cout << std::endl;
                    }
                    break;
                case 5:
                    PrintBinaryTreeTraversalOptions();

                    while (errorInfo.GetErrorCode() != NoErrorCode) {
                        std::cin >> traversalEnter;
                        if (traversalEnter == 1 || traversalEnter == 2 || traversalEnter == 3 || traversalEnter == 4 ||
                            traversalEnter == 5 || traversalEnter == 6) {
                            errorInfo.SetErrorCode(NoErrorCode);
                            break;
                        } else {
                            errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                            errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                            errorInfo.GetErrorMsg();
                        }
                    }

                    errorInfo.SetErrorCode(NoErrYetCode);

                    std::cout << binaryTree.ConvertTreeToString(traversalEnter);
                    break;
                case 6:
                    endProgram = 1;
                    break;
                case 7:
                    Test();
                    break;
                default:
                    errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                    errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                    errorInfo.GetErrorMsg();
                    break;
            }
        }
    }
    return 0;
}
