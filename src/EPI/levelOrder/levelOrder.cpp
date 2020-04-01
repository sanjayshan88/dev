#include <iostream>
#include <queue>
#include "levelOrder.hpp"

using namespace std;

TreeNode* newNode(int val)
{
    TreeNode* t = new TreeNode();
    t->info = val;
    t->left = NULL;
    t->right = NULL;

    return t;
}

void printInorder(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->info << " ";
    printInorder(root->right);
}

void printLevelOrder(TreeNode* root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *temp = q.front();
        cout << temp->info << " ";
        q.pop();

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main()
{
    TreeNode *root = newNode(314);
    root->left = newNode(6);
    root->right = newNode(6);
    root->left->left = newNode(271);
    root->left->right = newNode(561);
    root->right->left = newNode(2);
    root->right->right = newNode(271);
    root->left->left->left = newNode(28);
    root->left->left->right = newNode(0);
    root->left->right->right = newNode(3);
    root->left->right->right->left = newNode(17);
    root->right->left->right = newNode(1);
    root->right->left->right->left = newNode(401);
    root->right->left->right->right = newNode(257);
    root->right->left->right->left->right = newNode(641);
    root->right->right->right = newNode(28);

    printLevelOrder(root);

    return 0;
}