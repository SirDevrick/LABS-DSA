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

void printList(struct node *headRef) {
  while (headRef != NULL) {
    printf("%d -> ", headRef->data);
    headRef = headRef->next;
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
  struct node *tmp = NULL;
  while (*headRef) {
    tmp = *headRef;
    *headRef = (*headRef)->next;
    free(tmp);
  }
  /* *headRef = NULL; */
}

void insertNth() {}

void insertNth_Test() { struct node *head = NULL; }

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
  int len = lenghtList(myList);
  printf("%d\n", len);
}

void tailTest() {
  struct node *head = NULL;
  struct node *tail;
  int i;
  Push(&head, 1);
  tail = head;
  /* Push(&head, 2); */
  /* printList(head); */
  // Esto es lo mismo que hacerlo con la flechita
  /* Push(&((*tail).next), 3); */
  /* tail = tail->next; */
  /* Push(&head, 4); */
  /* Push(&(tail->next), 5); */
  for (int i = 2; i < 5; ++i) {
    // Hacert con la aritemitca de punteros es lo mismo que hacerlo con flechita
    Push(&((*tail).next), i);
    /* Push(&(tail->next), i); */
    tail = tail->next;
  }
  printList(head);
}

void tailDummyTest() {
  struct node dummy;
  // Dummy node is temporarily the first node
  struct node *tail = &dummy; // Start the tail at the dummy.
                              // Build the list on dummy.next (aka tail->next)
  int i;
  dummy.next = NULL;
  for (i = 2; i < 6; i++) {
    Push(&(tail->next), i);
    tail = tail->next;
  }
  // En este caso me esta imprimiendo el valor de dummy tambien pero es basura
  printList(&dummy);
  // The real result list is now in dummy.next
  // dummy.next == {1, 2, 3, 4, 5};
}

struct node *reverseList(struct node *head) {
  if (!head || !(head->next))
    return head;

  struct node *reverse = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;

  return reverse;
}

void reverseListTest() {
  struct node *head = BuildOneTwoThree();
  printList(head);
  head = reverseList(head);
  printList(head);
}

int main() {
  /* lenghtTest(); */
  /* deleteListTest(); */
  /* tailTest(); */
  /* tailDummyTest(); */
  reverseListTest();
  return 0;
}
