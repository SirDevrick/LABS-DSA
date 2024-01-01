#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *BuildOneTwoThree() {
  struct node *head = malloc(sizeof(struct node));
  /* struct node *second = NULL; */
  /* struct node *third = NULL; */

  head->next = (head->data = 1, malloc(sizeof(struct node)));
  head->next->next = (head->next->data = 2, malloc(sizeof(struct node)));
  head->next->next->next = (head->next->next->data = 3, NULL);

  /* head = malloc(sizeof(struct node)); */
  /* second = malloc(sizeof(struct node)); */
  /* third = malloc(sizeof(struct node)); */

  /* head->data = 1; */
  /* head->next = second; */

  /* second->data = 2; */
  /* second->next = third; */

  /* third->data = 3; */
  /* third->next = NULL; */

  return head;
}

void printList(struct node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void Push(struct node **headRef, int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = data;

  newNode->next = *headRef;
  *headRef = newNode;
}

int lenghtList(struct node *head) {
  /* struct node *current = head; */
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->next;
  }
  return count;
}

int countOcurrency(struct node *current, int data) {
  int count = 0;
  while (current) {
    if (current->data == data) {
      count++;
    }
    current = current->next;
  }
  return count;
}

void deleteList(struct node **headRef) {
  // Esto esta mal
  struct node *tmp = NULL;
  while (*headRef) {
    tmp = *headRef;
    *headRef = (*headRef)->next;
    free(tmp);
  }
  *headRef = NULL;
}

void insertNth() {}

void insertNth_Test() {
  struct node *head = NULL;

}

void lenghtTest() {
  struct node *list = BuildOneTwoThree();
  int len = lenghtList(list);
  printf("%d\n", len);
}

void countTest() {
  struct node *myList = BuildOneTwoThree();
  int count = countOcurrency(myList, 2);
  printf("%d", count);
}

void deleteListTest() {
  struct node *myList = BuildOneTwoThree();
  printList(myList);
  deleteList(&myList);
  printList(myList);
}

int main() {
  /* lenghtTest(); */
  deleteListTest();
  return 0;
}
