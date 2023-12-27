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

void lenghtTest() {
  struct node *list = BuildOneTwoThree();
  int len = lenghtList(list);
  printf("%d\n", len);
}

void countTest() {
  struct node* myList = BuildOneTwoThree();
  int count = countOcurrency(myList, 2);
}



int main() {
  lenghtTest();
  return 0;
}
