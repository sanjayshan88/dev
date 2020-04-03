#include <iostream>
#include "heightBalanced.hpp"

using namespace std;

TreeNode* newNode(int val)
{
    TreeNode *t = new TreeNode();
    t->info = val;
    t->left = NULL;
    t->right = NULL;
}

int isHeightBalancedHelper(TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    // postorder
    int lh = isHeightBalancedHelper(root->left);
    int rh = isHeightBalancedHelper(root->right);

    if (lh == -1 || rh == -1) {
        return -1;
    }

    if (abs(lh - rh) > 1) {
        return -1;
    }

    return 1 + max(lh, rh);
}

bool isHeightBalanced(TreeNode* root)
{
    if (root == NULL) {
        return true;
    }

    return (isHeightBalancedHelper(root) != -1);
}

int main()
{

    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << isHeightBalanced(root) << endl;

    root->left->left->left = newNode(6);
    root->left->left->left->right = newNode(7);

    cout << isHeightBalanced(root) << endl;

    return 0;
}