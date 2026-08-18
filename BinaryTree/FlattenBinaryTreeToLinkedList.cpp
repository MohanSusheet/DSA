#include<iostream>
#include<vector>
#include<stack>

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

TreeNode* previous = NULL;

void flattenBinaryTree1(TreeNode* root)
{
    //Approach 1.
    //using global variable "prev"
    //T.C --> O(N), S.C --> O(H) Balanced tree: O(logN) and for Skewed tree: O(N) i.e. the height of tree
    if(root == NULL)return;

    //Traversing in Reverse Postorder manner [Right, Left, Root]
    flattenBinaryTree1(root->right);
    flattenBinaryTree1(root->left);

    root->left = NULL;
    root->right = previous;
    previous = root;
}

void flattenBinaryTree2(TreeNode* root)
{
    //Approach 2: using Stack with same Rev Postorder Traversal[Right, Left, Root]
    //T.C --> O(N), S.C --> O(H) Balanced tree: O(logN) and for Skewed tree: O(N) i.e. the height of tree
    if(root == NULL)return;

    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty())
    {
        TreeNode* cur = st.top();
        st.pop();

        if(cur->right)st.push(cur->right);
        if(cur->left)st.push(cur->left);

        if(!st.empty())cur->right = st.top();
        cur->left = nullptr;
    }
}

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->right->right->left->right = new TreeNode(19);

    flattenBinaryTree1(root); //Approach 1: using global variable to track the prev node
    flattenBinaryTree2(root);
    return 0;
}