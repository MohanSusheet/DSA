#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TreeNode
{
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){} //Empty Constructor
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

TreeNode* buildTree(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, map<int, int>&inorderMap)
{
    if(preStart > preEnd || inStart > inEnd)return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int rootIdxInorder = inorderMap[preorder[preStart]];
    int leftToRootCountInorder = rootIdxInorder - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + leftToRootCountInorder, inorder, inStart, rootIdxInorder - 1, inorderMap);

    root->right = buildTree(preorder, preStart + leftToRootCountInorder + 1, preEnd, inorder, rootIdxInorder + 1, inEnd, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    //T.C --> O(N) + O(log n)[insertion in map]
    //S.C -->O(N) [map] 
    map<int, int> inorderMap;

    for(int i = 0; i < inorder.size(); i++)
    {
        inorderMap[inorder[i]] = i;
    }

    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
}

int main()
{
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};

    TreeNode *root = buildTree(preorder, inorder);
    return 0;
}