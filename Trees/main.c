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
  return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
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

void mirror(struct node* node) {
  if (!node)
    return;
  else {
    struct node* tmp = NULL;
    mirror(node->left);
    mirror(node->right);
    tmp = node->left;
    node->left = node->right;
    node->right = tmp;
  }
}

void doubleTree(struct node* node) {
  struct node* old = NULL;
  if (!node)
    return;
  else {
    doubleTree(node->left);
    doubleTree(node->right);

    /* insert(node, node->data); */
    old = node->left;
    node->left = newNode(node->data);
    node->left->left = old;
  }
}

void printLinkedList(struct node* head) {
  struct node* current = head;
  do {
    printf("%d ", current->data);
    current = current->right;
  } while (current != head);
}

struct node* treeToList(struct node* root) {
  if (!root) return NULL;
  struct node* leftList = treeToList(root->left);
  struct node* rightList = treeToList(root->right);

  root->left = root;
  root->right = root;
  if (leftList) {
    leftList->left->right = root;
    root->left = leftList->left;
    leftList->left = root;
  }

  if (rightList) {
    root->right = rightList;
    rightList->left->right = root;
    root->left = rightList->left;
    rightList->left = root;
  }
  return root;
}

void treeToListTest(){
  struct node* tree = NULL;
  tree = insert(tree, 1);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 4);
  tree = insert(tree, 5);
  tree = insert(tree, 6);
  tree = insert(tree, 7);
  /* printTree(tree); */
  struct node* list = treeToList(tree);
  printLinkedList(list);
}

/* void transplant(struct node* node, struct node* u, struct node* v) { */
/*   if () */

/* } */

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

void hasPathSumTest(){
  struct node* root = build123();
  int result = hasPathSum(root, 6);
  printf("%d \n", result);
}

void printPathsTest() {
  struct node* root = build123();
  printPaths(root);
}

void mirrorTest() {
  struct node* root = build123();
  printTree(root);

  mirror(root);

  printf("\n");
  printTree(root);
}

void doubleTreeTest() {
  struct node* root = build123();
  printTree(root);

  doubleTree(root);

  printf("\n");
  printTree(root);
}

int main () {
  /* SizeTest(); */
  /* maxDepthTest(); */
  /* hasPathSumTest(); */
  /* printPathsTest(); */
  /* mirrorTest(); */
  /* doubleTreeTest(); */
  treeToListTest();
  return 0;
}
