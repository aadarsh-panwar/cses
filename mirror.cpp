#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class TreeNode {
    public : 
    int value;
    TreeNode *left, *right;
    TreeNode(int value) {
        this->left = nullptr;
        this->right = nullptr;
    }
};

void mirror_image(TreeNode *root) {
    if(root == nullptr)
    return;
    swap(root->left, root->right);
    mirror_image(root->left);
    mirror_image(root->right);
}

1, 2,5, 2,2,2,2,2, 5,9,6,7,8
 2, 2,2,2,  2,2,2,5,6,8,9,1

freq > N/2

int main() {
    
    

    return 0;
}