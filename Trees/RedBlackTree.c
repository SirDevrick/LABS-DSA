#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct node {
  int key;
  int color;
  struct node *parent;
  struct node *left;
  struct node *right;
};

struct node *createNode(int);
void insert_RB(struct node **, struct node *);
void RB_fixup(struct node **, struct node *);

int main() { return 0; }

struct node *createNode(int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->key = data;
  return newNode;
}

void insert_RB(struct node **Tree, struct node *z) {
  struct node *x_current_root = *Tree;
  struct node *y_current_father = NULL;

  while (x_current_root) {
    y_current_father = x_current_root;
    if (z->key < x_current_root->key)
      x_current_root = x_current_root->left;
    else
      x_current_root = x_current_root->right;
  }

  z->parent = y_current_father;

  if (!y_current_father)
    *Tree = z;
  else if (z->key < y_current_father->key)
    y_current_father->left = z;
  else
    y_current_father->right = z;

  z->left = NULL;
  z->right = NULL;
  z->color = RED;

  RB_fixup(Tree, z);
}

void RB_fixup(struct node **Tree, struct node *z) { (*Tree)->color = BLACK; }
