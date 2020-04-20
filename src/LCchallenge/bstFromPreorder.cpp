#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int info) {
        val = info;
        left = NULL;
        right = NULL;
    }    
};

TreeNode* bstFromPreorderHelper(vector<int>& preorder, int& index, int min, int max)
{
    if (index >= preorder.size()) {
        return NULL;
    }

    TreeNode* root = NULL;
    if (preorder[index] > min && preorder[index] < max) {
        root = new TreeNode(preorder[index]);
        index++;
        root->left = bstFromPreorderHelper(preorder, index, min, root->val);
        root->right = bstFromPreorderHelper(preorder, index, root->val, max);
    }

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    if (preorder.size() == 0) {
        return NULL;
    }
    int index = 0;
    return bstFromPreorderHelper(preorder, index, INT_MIN, INT_MAX);
}

void printPreorder(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() 
{
    vector<int> preorder;
    // [8,5,1,7,10,12]
    preorder.push_back(8);
    preorder.push_back(5);
    preorder.push_back(1);
    preorder.push_back(7);
    preorder.push_back(10);
    preorder.push_back(12);

    TreeNode* root = bstFromPreorder(preorder);
    cout << "Preorder traversal of constructed tree: " << endl;
    printPreorder(root);
    cout << endl;

    return 0;
}