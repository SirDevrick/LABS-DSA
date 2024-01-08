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
  if (node == NULL) {
    return(newNode(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);
    return(node); // return the (unchanged) node pointer
  }
}
/* int hasPathSum(struct node* root, int sum) { */
/*   if (!root) */
/*     return 0; */
/* } */

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

int main () {

  return 0;
}
