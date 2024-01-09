#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data) {
  struct node* node = malloc(sizeof(struct node));
  (*node).data = data;
  (*node).left = NULL;
  (*node).right = NULL;

  return node;
}
struct node* insert(struct node* node, int data) {
 // 1. If the tree is empty, return a new, single node
  if (!node) {
    return newNode(data);
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->data) 
      node->left = insert(node->left, data);
    else 
      node->right = insert(node->right, data);
    return node; // return the (unchanged) node pointer
  }
}

struct node* build123(){
  struct node* myNode = NULL;
  myNode = insert(myNode, 2);
  myNode = insert(myNode, 1);
  myNode = insert(myNode, 3);
  return myNode;
}

/* void inOrder(struct node* node, int *argc, int *argv) { */
/*   if (node == NULL) */
/*     *argc = 0; */
/*   else { */
/*     inOrder(node->left, argc, argv++); */
/*     (*argc)++; */
/*     *argv = node->data; */
/*     inOrder(node->right, argc, argv++); */
/*   } */
/* } */

int Size(struct node* root) {
  if (!root)
    return 0;
  else
    return 1 + Size(root->left) + Size(root->right);
}

int maxDepth(struct node* node) {
  if(!node)
    return 0;
  else {
    int l = maxDepth(node->left);
    int r = maxDepth(node->right);
    return 1 + (l > r ? l: r);
  }
}

void printTree(struct node* node) {
  if (!node)
    return;
  else {
    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
  }
}

void TreePostOrder(struct node* node) {
  if (!node)
    return;
  else {
    printTree(node->left);
    printTree(node->right);
    printf("%d ", node->data);
  }
}

int hasPathSum(struct node* root, int sum) {
  if (!root)
    return sum == 0;
  sum = sum - root->data;
  hasPathSum(root->left, sum);
  hasPathSum(root->right, sum);
  return sum;
}

void printArray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void printPathRecursion(struct node* node, int* path, int cont) {
  *(path + cont) = node->data;
  cont++;
  if (!node->left && !node->right)
    printArray(path, cont);
  else {
    printPathRecursion(node->left, path, cont);
    printPathRecursion(node->right, path, cont);
  }
}

void printPaths(struct node* node) {
  int a[256];
  if(node)
    printPathRecursion(node, a, 0);
}

void SizeTest() {
  struct node* root = build123();
  int size = Size(root);
  printf("%d ", size);
}

void maxDepthTest() {
  struct node* root = build123();
  int depth = maxDepth(root);
  printf("%d \n", depth);
  printf("InOrder: \n");
  printTree(root);
  printf("\nPosOrder: \n");
  TreePostOrder(root);
}


int main () {
  /* SizeTest(); */
  maxDepthTest();
  return 0;
}
