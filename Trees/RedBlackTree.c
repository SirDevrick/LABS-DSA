#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct node {
  int data;
  int color;
  struct node *parent;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->color = RED;
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

int main() { return 0; }
