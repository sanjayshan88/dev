#include <iostream>
#include <vector>
#include "levelOrderAvg.hpp"

using namespace std;

TreeNode* newNode(int val)
{
    TreeNode* t = new TreeNode();
    t->info = val;
    t->left = NULL;
    t->right = NULL;

    return t;
}

int height(TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void getLevelElems(TreeNode* root, int level, vector<int>& levelElems)
{
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        levelElems.push_back(root->info);
    } else if (level > 1) {
        getLevelElems(root->left, level-1, levelElems);
        getLevelElems(root->right, level-1, levelElems);
    }
}

void printLevelOrderAvg(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    int h = height(root);
    for (int i=1; i<=h; i++) {
        vector<int> elems;
        getLevelElems(root, i, elems);

        int sum = 0;
        for (int i=0; i<elems.size(); i++) {
            sum += elems[i];
        }
        double avg = (double)sum/elems.size();
        cout << "Avg at level " << i-1 << ": " << avg << endl;
    }
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

    printLevelOrderAvg(root);

    return 0;
}