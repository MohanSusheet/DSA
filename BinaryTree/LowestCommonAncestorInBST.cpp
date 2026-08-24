#include<iostream>

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

TreeNode* findLowestCommenAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    //Approach: There can only be 4 cases.
    //Case 1: Both nodes "p" & "q" are smaller than the root node. Then both lie in the Left Subtree.
    //Case 2: Both nodes "p" & "q" are greater than the root node. Then both lie in the Right Subtree.
    //Case 3: One of the nodes is smaller and one is greater than the root node. In that case Root itself is the LCA
    //Case 4: One of node p or q is the root and the other lies in its either subtree. In that case also the root itself is the LCA
    //T.C --> O(H), S.C --> O(H) [stack space], average case : H = LogN, skewed Tree: H = N
    if(root == NULL)return root;

    if(p->val < root->val && q->val < root->val)
    {
        return findLowestCommenAncestor(root->left, p, q);
    }
    if(p->val > root->val && q->val > root->val)
    {
        return findLowestCommenAncestor(root->right, p, q);
    }

    return root;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(21);
    root->right->right->left = new TreeNode(19);
    root->right->right->right = new TreeNode(25);

    TreeNode* lowestCommenAncestor = findLowestCommenAncestor(root, root->left->right, root->right);

    cout<<"LCA of given Binary Search Tree is: "<<lowestCommenAncestor->val;

    return 0;
}