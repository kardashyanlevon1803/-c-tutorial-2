#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class TreeNode {
private:
    int value;
    vector<shared_ptr<TreeNode>> children;

public:
    TreeNode(int value) {
        this->value = value;
    }

    int getValue() {
        return value;
    }

    void setValue(int value) {
        this->value = value;
    }

    void addChild(shared_ptr<TreeNode> child) {
        children.push_back(child);
    }

    vector<shared_ptr<TreeNode>> getChildren() {
        return children;
    }
};

class Tree {
private:
    shared_ptr<TreeNode> root;

    void printNode(shared_ptr<TreeNode> node, int level) {
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << node->getValue() << endl;
        for (auto child : node->getChildren()) {
            printNode(child, level + 1);
        }
    }

public:
    Tree(int rootValue) {
        root = make_shared<TreeNode>(rootValue);
    }

    shared_ptr<TreeNode> getRoot() {
        return root;
    }

    void print() {
        if (root != nullptr) {
            printNode(root, 0);
        }
    }
};

int main() {
    Tree tree(1);

    shared_ptr<TreeNode> root = tree.getRoot();

    shared_ptr<TreeNode> child1 = make_shared<TreeNode>(2);
    shared_ptr<TreeNode> child2 = make_shared<TreeNode>(3);
    shared_ptr<TreeNode> child3 = make_shared<TreeNode>(4);

    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);

    shared_ptr<TreeNode> child1_1 = make_shared<TreeNode>(5);
    shared_ptr<TreeNode> child1_2 = make_shared<TreeNode>(6);
    child1->addChild(child1_1);
    child1->addChild(child1_2);

    shared_ptr<TreeNode> child2_1 = make_shared<TreeNode>(7);
    child2->addChild(child2_1);

    cout << "Tree structure:" << endl;
    tree.print();

    return 0;
}