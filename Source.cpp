#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
        Node* temp;
        if (root.getValue() <= value) {
            if (root.getValue() == value) {
                return true;
            }
            else {
                if (root.getRight() != NULL) {
                    temp = root.getRight();
                    return contains(*temp, value);
                }
                else {
                    return false;
                }
            }
        }
        else {
            if (root.getValue() == value) {
                return true;
            }
            else {
                if (root.getLeft() != NULL) {
                    temp = root.getLeft();
                    return contains(*temp, value);
                }
                else
                    return false;
            }
        }

    }
};

#ifndef RunTests
int main()
{
    //Node n1(1, NULL, NULL);
    //Node n3(3, NULL, NULL);
    //Node n2(2, &n1, &n3);

    

    Node n1(1, nullptr, nullptr);
    Node n3(3, nullptr, nullptr);
    Node n5(5, nullptr, nullptr);
    Node n7(7, nullptr, nullptr);

    Node n2(2, &n1, &n3);
    Node n6(6, &n5, &n7);

    Node n4(4, &n2, &n6);
    std::cout << BinarySearchTree::contains(n6, 3);

}
#endif