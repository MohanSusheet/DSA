#include<iostream>
#include<vector>
#include<queue>
#include<set>
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

bool checkTree(TreeNode* root) 
{
    //the problem is not to check the entire left and right subtree. instead just immediate children
    //T.C --> O(N), S.C --> O(H)
    if(root == NULL)return true;
    //Leaf node always satisfies the property
    if(root->left == NULL && root->right == NULL)return true;

    int left = (root->left)? root->left->val : 0;
    int right = (root->right)? root->right->val : 0;

    return root->val == left + right && checkTree(root->left) && checkTree(root->right);
}


int main()
{
    TreeNode* root = new TreeNode(10, new TreeNode(3), new TreeNode(4));

    int targetNode = 7;
    cout<<checkTree(root);
    
    return 0;
}