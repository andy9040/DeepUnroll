#include <stdio.h>
#include <string.h>

typedef struct tnode tnode;

typedef struct{
	tnode *root;
}Tree;

struct tnode {
	int key;
	tnode *left, *right;
	tnode *p;
};

void insert(Tree *T, int n) {
	tnode *z;
	z = malloc(sizeof(tnode));
	z->key = n;
	z->left = z->right = NULL;
	tnode *y = NULL;
	tnode *x = T->root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
		z->p = y;
	}
	
	if (y == NULL) {
		T->root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}

int find_rec(tnode *node, int key) {
	if(node->key == key) return 1;
	if(node->left != NULL && find_rec(node->left, key)) return 1;
	if(node->right != NULL && find_rec(node->right, key)) return 1;
	return 0;
}

int find(Tree *tree, int key) {
	return find_rec(tree->root, key);
}

void print_preorder_rec(tnode *node){
	printf(" %d", node->key);
	if(node->left != NULL) print_preorder_rec(node->left);
	if(node->right != NULL) print_preorder_rec(node->right);
}

void print_preorder(Tree *tree) {
	print_preorder_rec(tree->root);
	printf("\n");
}

void print_inorder_rec(tnode *node){
	if(node->left != NULL) print_inorder_rec(node->left);
	printf(" %d", node->key);
	if(node->right != NULL) print_inorder_rec(node->right);
}

void print_inorder(Tree *tree) {
	print_inorder_rec(tree->root);
	printf("\n");
}

void print_postorder_rec(tnode *node){
	if(node->left != NULL) print_postorder_rec(node->left);
	if(node->right != NULL) print_postorder_rec(node->right);
	printf(" %d", node->key);
}

void print_postorder(Tree *tree) {
	print_postorder_rec(tree->root);
	printf("\n");
}

int main(void) {
	Tree T;
	T.root = NULL;
	int i, n, z;
	char command[7];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", command);
		if (strcmp(command, "insert") == 0) {
			scanf("%d", &z);
			insert(&T, z);
		}
		if (strcmp(command, "print") == 0) {
			print_inorder(&T);
			print_preorder(&T);
		}
		if (strcmp(command, "find") == 0) {
			scanf("%d", &z);
			if (find(&T, z)) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}