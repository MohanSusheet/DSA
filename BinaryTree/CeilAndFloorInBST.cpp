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

int ceilInBST(TreeNode* root, int target)
{
    //T.C --> O(LogN), S.C --> O(Log N)
    int ans = -1;

    while(root)
    {
        if(root->val == target)
        {
            ans = root->val;
            break;
        }
        else if(root->val > target)
        {
            ans = root->val;
            root = root->left;
        }
        else root = root->right;
    } 

    return ans;
}

int floorInBST(TreeNode* root, int target)
{
    //T.C --> O(LogN), S.C --> O(Log N)
    int ans = -1;

    while(root)
    {
        if(root->val == target)
        {
            ans = root->val;
            break;
        }
        else if(root->val < target)
        {
            ans = root->val;
            root = root->right;
        }
        else root = root->left;
    }

    return ans;
}

int ceilInBSTIterative(TreeNode* root, int target)
{
    //T.C --> O(H) i.e. (Log N or N), S.C --> O(1)
    int ans = -1;
    if(root == NULL)return ans;
    TreeNode* cur = root;

    while(cur)
    {
        if(cur->val == target)
        {
            ans = cur->val;
            return ans;  //or break
        }
        else if(cur->val < target)
        {
            cur = cur->right;
        }
        else
        {
            ans = cur->val; //potential ans
            cur = cur->left; //but we need to look for the smallest greater. hence looking for even smaller on root->left
        }
    }

    return ans;
}

int floorInBSTIterative(TreeNode* root, int target)
{
    //T.C --> O(H) i.e. (Log N or N), S.C --> O(1)
    int ans = -1;
    if(root == NULL)return ans;
    TreeNode* cur = root;

    while(cur)
    {
        if(cur->val == target)
        {
            ans = cur->val;
            return ans;  //or break
        }
        else if(cur->val < target)
        {
            ans = cur->val; //potential ans
            cur = cur->right;//but we need to look for the greatest smaller. hence looking for even smaller on root->right.
        }
        else
        {
            cur = cur->left; 
        }
    }

    return ans;
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

    int target = 20;

    cout<<"Ceil in given BST: "<<ceilInBST(root, target)<<"\nFloor in given BST: "<< floorInBST(root, target);

    cout<<"\n-----ITERATIVE Solution----- \nCeil in given BST: "<<ceilInBSTIterative(root, target)<<"\nFloor in given BST: "<< floorInBSTIterative(root, target);

    return 0;
}