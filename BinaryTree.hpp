#include <iostream>
#include <cstring>
#include <cmath>

int Left = 0;
int Right = 1;


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

                ~BinaryTreeElement() = default;
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
                    treeToString->append(std::to_string(rootElement->GetValue()).substr(0, std::to_string(rootElement->GetValue()).find(".") + 4) + " ");
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    break;
                case RootLeftRight:
                    treeToString->append(std::to_string(rootElement->GetValue()).substr(0, std::to_string(rootElement->GetValue()).find(".") + 4) + " ");
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    break;
                case RootRightLeft:
                    treeToString->append(std::to_string(rootElement->GetValue()).substr(0, std::to_string(rootElement->GetValue()).find(".") + 4) + " ");
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
                    treeToString->append(std::to_string(rootElement->GetValue()).substr(0, std::to_string(rootElement->GetValue()).find(".") + 4) + " ");
                    break;
                case RightLeftRoot:
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    if (rootElement->GetLeft() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetLeft());
                    }
                    treeToString->append(std::to_string(rootElement->GetValue()).substr(0, std::to_string(rootElement->GetValue()).find(".") + 4) + " ");
                    break;
                case RightRootLeft:
                    if (rootElement->GetRight() != nullptr) {
                        ConvertTreeToString(traversalType, treeToString, rootElement->GetRight());
                    }
                    treeToString->append(std::to_string(rootElement->GetValue()).substr(0, std::to_string(rootElement->GetValue()).find(".") + 4) + " ");
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

        void Contains(BinaryTreeElement* rootElement, T item) {
            if (item != rootElement->GetValue()) {
                if (item >= rootElement->GetValue()) {
                    if (rootElement->GetRight() != nullptr) {
                        Contains(rootElement->GetRight(), item);
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
                        Contains(rootElement->GetLeft(), item);
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

        BinaryTreeElement* SearchNode(BinaryTreeElement* rootElement, T value) {
            if (rootElement->GetValue() != value) {
                if (rootElement->GetValue() >= value) {
                    if (rootElement->GetLeft() != nullptr) {
                        SearchNode(rootElement->GetLeft(), value);
                    }
                    else {
                        ErrorInfo errorInfo;
                        errorInfo.SetErrorCode(NoElementFoundCode);
                        errorInfo.CopyErrorMsg(NoElementFoundMsg);
                        throw errorInfo;
                    }
                }
                else {
                    if (rootElement->GetRight() != nullptr) {
                        SearchNode(rootElement->GetRight(), value);
                    }
                    else {
                        ErrorInfo errorInfo;
                        errorInfo.SetErrorCode(NoElementFoundCode);
                        errorInfo.CopyErrorMsg(NoElementFoundMsg);
                        throw errorInfo;
                    }
                }
            }
            else {
                return rootElement;
            }
        }

    public:
        BinaryTree() = default;

        explicit BinaryTree(T item) {
            auto* newElement = new BinaryTreeElement(item);
            this->root = newElement;
        }

        BinaryTree(const BinaryTree& treeToCopy) {
            if (treeToCopy.root != nullptr) {
                this->root = new BinaryTreeElement(treeToCopy.root->GetValue());
                CopyElement(this->root, treeToCopy.root->GetLeft(), Left);
                CopyElement(this->root, treeToCopy.root->GetRight(), Right);
            }
            else {
                this->root = nullptr;
            }
        }

        void deleteBinaryTree(BinaryTreeElement* element) {
            if (element != nullptr) {
                deleteBinaryTree(element->GetLeft());
                deleteBinaryTree(element->GetRight());
                delete element;
            }
        }

        ~BinaryTree() {
            deleteBinaryTree(this->root);
        }

        void CopyElement(BinaryTreeElement* prevElement, BinaryTreeElement* elementToCopy, int position) {
            if (elementToCopy != nullptr) {
                auto* newElement = new BinaryTreeElement(elementToCopy->GetValue());
                if (position == Left) {
                    prevElement->SetLeft(newElement);
                }
                else {
                    prevElement->SetRight(newElement);
                }
                CopyElement(newElement, elementToCopy->GetLeft(), Left);
                CopyElement(newElement, elementToCopy->GetRight(), Right);
            }
        }
    public:
        BinaryTreeElement* GetRoot() {
            return this->root;
        }

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
            if (this->root == nullptr) {
                ErrorInfo errorInfo;
                errorInfo.SetErrorCode(NoTreeCreatedCode);
                errorInfo.CopyErrorMsg(NoTreeCreatedMsg);
                throw errorInfo;
                return;
            }
            Contains(this->root, item);
        }

        template<typename Function>
        BinaryTree Map(Function function) {
            BinaryTree newBinaryTree(*this);
            Map(newBinaryTree.root, function);
            return  newBinaryTree;
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

        BinaryTree BalanceTree() {
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

        BinaryTree GetSubTree(T value) {
            BinaryTreeElement* subRoot = nullptr;
            try {
                BinaryTreeElement* temp = SearchNode(this->root, value);
                subRoot = new BinaryTreeElement(temp->GetValue());
                CopyElement(subRoot, temp->GetLeft(), Left);
                CopyElement(subRoot, temp->GetRight(), Right);
            } catch (ErrorInfo errorInfo) {
                errorInfo.GetErrorMsg();

            }
            return subRoot;
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

        BinaryTree& operator=(const BinaryTree binaryTree) {
            deleteBinaryTree(this->root);
            if (binaryTree.root != nullptr) {
                this->root = new BinaryTreeElement(binaryTree.root->GetValue());
                CopyElement(this->root, binaryTree.root->GetLeft(), Left);
                CopyElement(this->root, binaryTree.root->GetRight(), Right);
            }
            return *this;
        }
};
