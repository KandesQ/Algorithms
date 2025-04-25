#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* leftNode;
    struct TreeNode* rightNode;
};

// recursive func
int find_max_sum(struct TreeNode* root_ptr) {
    
    if (root_ptr->leftNode == NULL && root_ptr->rightNode == NULL) {
        return root_ptr->val;
    }

    int left_sum = find_max_sum(root_ptr->leftNode), // process left subtree
        right_sum = find_max_sum(root_ptr->rightNode); // process right subtree
    
    if (left_sum >= right_sum) {
        return left_sum + root_ptr->val;
    } else {
        return right_sum + root_ptr->val;
    }
}

void free_tree(struct TreeNode* root_ptr) {
    
    if (root_ptr->leftNode == NULL && root_ptr->rightNode == NULL) {
        free(root_ptr);
        return;
    }

    free_tree(root_ptr->leftNode);
    free_tree(root_ptr->rightNode);

    free(root_ptr);
}

int main() {
    struct TreeNode* left_ptr = malloc(sizeof(struct TreeNode));
    struct TreeNode* right_ptr = malloc(sizeof(struct TreeNode));

    left_ptr->val = 23;
    right_ptr->val = 51;

    struct TreeNode* root_ptr = malloc(sizeof(struct TreeNode));

    root_ptr->val = 1;

    root_ptr->leftNode = left_ptr;
    root_ptr->rightNode = right_ptr;

    printf("%d", find_max_sum(root_ptr));

    free_tree(root_ptr);

    return 0;
}