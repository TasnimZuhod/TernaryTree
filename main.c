#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* right;
    struct node* mid;
    int key;
}Node;

int sum = 0;
int findPathSum(Node* root, Node* target) {

    if(root == NULL)
		return 0;

	if(root == target)
		return sum + root -> key;

    if(root -> left != NULL) {
        sum =  findPathSum(root -> left, target);
        if (sum != 0)
            return sum + root -> key;
    }

    if(root -> mid != NULL) {
        sum =  findPathSum(root -> mid, target);
        if (sum != 0)
            return sum + root -> key;
    }

    if(root -> right != NULL) {
        sum =  findPathSum(root -> right, target);
        if (sum != 0)
		return sum + root -> key;
    }

}

int main()
{
    Node j = {0, 0, 0, 31};
    Node i = {0, 0, 0, 15};
    Node h = {0, 0, 0, 40};
    Node g = {0, 0, 0, 63};
    Node f = {0, 0, 0, 1};
    Node e = {0, 0, 0, 15};
    Node d = {0, 0, 0, 7};
    Node c = {&j, &i, &h, 85};
    Node b = {&g, &f, &e, 30};
	Node a = {&c, &b, &d, 10};

    Node *root = &a;

    Node x = {&j, &i, &h, 85};

    int sum = findPathSum(root, &f);

    if(sum == 0)
        printf("The target is not exist\n");
    else
        printf("The sum of the nodes between %d and the target = %d\n", root -> key, sum);

    return 0;
}
