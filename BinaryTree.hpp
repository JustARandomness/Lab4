#include <iostream>
#include <cstring>
#include <cmath>

template<typename T>
class BinaryTree {
    private:
        class BinaryTreeElement {
            private:
                T value = 0;
                BinaryTreeElement* left;
                BinaryTreeElement* right;
            public:
                BinaryTreeElement() {
                    this->left = nullptr;
                    this->right = nullptr;
                }

                explicit BinaryTreeElement(T item) {
                    this->value = item;
                    this->right = nullptr;
                    this->left = nullptr;
                }
            public:
                T GetValue() {
                    return this->value;
                }

                BinaryTreeElement* GetLeft() {
                    return this->left;
                }

                BinaryTreeElement* GetRight() {
                    return this->right;
                }
            public:
                void SetValue(T item) {
                    this->value = item;
                }

                void SetRight(BinaryTreeElement* element) {
                    this->right = element;
                }

                void SetLeft(BinaryTreeElement* element) {
                    this->left = element;
                }
        };

        BinaryTreeElement* root = nullptr;

        void TreeToArray(BinaryTreeElement* rootElement, std::vector<T>* result) {
            if (rootElement->GetLeft() != nullptr) {
                TreeToArray(rootElement->GetLeft(), result);
            }
            result->push_back(rootElement->GetValue());
            if (rootElement->GetRight() != nullptr) {
                TreeToArray(rootElement->GetRight(), result);
            }
        }

        void ConvertTreeToString(int traversalType, std::string* treeToString, BinaryTreeElement* rootElement) {
            switch(traversalType) {
                case LeftRootRight:
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    treeToString->append(std::to_string(rootElement->GetValue()) + " ");
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    break;
                case RootLeftRight:
                    treeToString->append(std::to_string(rootElement->GetValue()) + " ");
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    break;
                case RootRightLeft:
                    treeToString->append(std::to_string(rootElement->GetValue()) + " ");
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    break;
                case LeftRightRoot:
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    treeToString->append(std::to_string(rootElement->GetValue()) + " ");
                    break;
                case RightLeftRoot:
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    treeToString->append(std::to_string(rootElement->GetValue()) + " ");
                    break;
                case RightRootLeft:
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    treeToString->append(std::to_string(rootElement->GetValue()) + " ");
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    break;
                default:
                    ErrorInfo errorInfo;
                    errorInfo.CopyErrorMsg(NoSuchOptionFoundMsg);
                    errorInfo.SetErrorCode(NoSuchOptionFoundCode);
                    throw errorInfo;
                    break;
            }
        };

        void Insert(BinaryTreeElement* rootElement, BinaryTreeElement* element) {
            if (element->GetValue() < rootElement->GetValue()) {
                if (rootElement->GetLeft() == nullptr) {
                    rootElement->SetLeft(element);
                }
                else {
                    Insert(rootElement->GetLeft(), element);
                }
            }
            else {
                if (rootElement->GetRight() == nullptr) {
                    rootElement->SetRight(element);
                }
                else {
                    Insert(rootElement->GetRight(), element);
                }
            }
        }


        template<typename Function>
        void Map(BinaryTreeElement* rootElement, Function function) {
            if (rootElement->GetLeft() != nullptr) {
                Map(rootElement->GetLeft(), function);
            }
            rootElement->SetValue(function(rootElement->GetValue()));
            if (rootElement->GetRight() != nullptr) {
                Map(rootElement->GetRight(), function);
            }
        }

        void Search(BinaryTreeElement* rootElement, T item) {
            if (item != rootElement->GetValue()) {
                if (item >= rootElement->GetValue()) {
                    if (rootElement->GetRight() != nullptr) {
                        Search(rootElement->GetRight(), item);
                    }
                    else {
                        ErrorInfo errorInfo;
                        errorInfo.SetErrorCode(NoElementFoundCode);
                        errorInfo.CopyErrorMsg(NoElementFoundMsg);
                        throw errorInfo;
                        return;
                    }
                }
                else {
                    if (rootElement->GetLeft() != nullptr) {
                        Search(rootElement->GetLeft(), item);
                    }
                    else {
                        ErrorInfo errorInfo;
                        errorInfo.SetErrorCode(NoElementFoundCode);
                        errorInfo.CopyErrorMsg(NoElementFoundMsg);
                        throw errorInfo;
                        return;
                    }
                }
            }
            else {
                std::cout << "There is element " << item << " in this tree\n";
                return;
            }
        }
    public:
        BinaryTree() = default;

        explicit BinaryTree(T item) {
            auto* newElement = new BinaryTreeElement(item);
            this->root = newElement;
        }
    public:
        void Insert(BinaryTreeElement* element) {
            if (this->root == nullptr) {
                this->root = element;
            }
            else {
                Insert(this->root, element);
            }
        }

        BinaryTreeElement* CreateTreeElement(T item) {
            auto* newElement = new BinaryTreeElement (item);
            return newElement;
        }

        void Search(T item) {
            Search(this->root, item);
        }

        template<typename Function>
        void Map(Function function) {
            Map(this->root, function);
        }

        std::string ConvertTreeToString(int traversalType) {
            auto* treeToString = new std::string;
            ConvertTreeToString(traversalType, treeToString, this->root);
            std::string result;
            result.append(*treeToString);
            delete treeToString;
            return result;
        }

        std::vector<T> TreeToSortedArray() {
            auto* newVector = new std::vector<T>;
            TreeToArray(this->root, newVector);
            std::vector<T> result(*newVector);
            delete newVector;
            return result;
        }

        BinaryTree BalancingTree() {
            std::vector<T> treeToSortedArray = this->TreeToSortedArray();
            BinaryTree binaryTree;
            binaryTree.Insert(this->CreateTreeElement(treeToSortedArray[(size(treeToSortedArray) / 2)]));
            for (int i = 0; i < size(treeToSortedArray) / 2; ++i) {
                binaryTree.Insert(this->CreateTreeElement(treeToSortedArray[i]));
            }
            for (int i = size(treeToSortedArray) / 2 + 1; i < size(treeToSortedArray); ++i) {
                binaryTree.Insert(this->CreateTreeElement(treeToSortedArray[i]));
            }
            return binaryTree;
        }

        friend std::ostream& operator<< (std::ostream& os, BinaryTree& binaryTree) {
            std::string convertTreeToString = binaryTree.ConvertTreeToString(LeftRootRight);
            for (int i = 0; i < size(convertTreeToString); ++i) {
                if (convertTreeToString[i] == '-') {
                    std::string temp;
                    temp.append(sizeof(char), convertTreeToString[i]);
                    ++i;
                    while (convertTreeToString[i] != ' ') {
                        temp.append(sizeof(char), convertTreeToString[i]);
                        ++i;
                    }
                    std::cout << temp;
                    std::cout << std::endl;
                }
                else if (convertTreeToString[i] != '-' && convertTreeToString[i] != ' ') {
                    std::string temp;
                    while (convertTreeToString[i] != ' ') {
                        temp.append(sizeof(char), convertTreeToString[i]);
                        ++i;
                    }
                    std::cout << temp;
                    std::cout << std::endl;
                }
                else {
                    continue;
                }
            }
            return os;
        }
};
