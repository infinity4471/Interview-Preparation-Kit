/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

   The Node struct is defined as follows:
   struct Node {
   int data;
   Node* left;
   Node* right;
   }
   */
bool checkBST_helper( Node* root, int& minim, int& maxim ) {
    if( root == nullptr ) return true;
    if( !checkBST_helper( root->left, minim, maxim ) || root->data <= maxim ) return false;
    int temp_min = minim;
    minim = 2*1e9;
    if( !checkBST_helper( root->right, minim, maxim ) || root->data >= minim ) return false;
    minim = min( root->data, temp_min );
    maxim = max( root->data, maxim );
    return true;
}
bool checkBST(Node* root) {
    int minim = 2*1e9, maxim = -2*1e9;
    return checkBST_helper( root, minim, maxim );
}
