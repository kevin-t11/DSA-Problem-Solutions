/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    private:
        void traverseLeft(Node* root, vector<int> &ans)
        {
            if((root == NULL) || (root->left == NULL && root->right == NULL) )
                return;
                
            ans.push_back(root->data);
            
            if(root->left)
                traverseLeft(root->left, ans);
            else
                traverseLeft(root->right, ans);
        }
        
        void traverseLeaf(Node* root, vector<int> &ans)
        {
            if(root == NULL)
                return ;
                
            if(root->left == NULL && root->right == NULL)
            {
                ans.push_back(root->data);
                return ;
            }
            
            traverseLeaf(root->left, ans);
            traverseLeaf(root->right, ans);
        }
        
        void traverseRight(Node* root, vector<int> &ans)
        {
            if((root == NULL) || (root->left == NULL && root->right == NULL) )
                return;
            
            if(root->right)
                traverseRight(root->right, ans);
            else
                traverseRight(root->left, ans);
                
            // wapas aaye tab root ka data print karva lo bcz in right part we have to print in reverse order excluding leaf node
            
            ans.push_back(root->data);
            
        }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        //basecase
        if(root == NULL)
        {
            return ans;
        }
        
        ans.push_back(root->data);
        
        //left part traverse excluding leaf node
        traverseLeft(root->left , ans);
        
        //traverse leaf node
        
        //left subtree
        traverseLeaf(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
        //traverse Right part 
        traverseRight(root->right, ans);
        
        return ans;
        
    }
};