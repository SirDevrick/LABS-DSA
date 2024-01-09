#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

void Push(struct node **headRef, int data) {
  struct node *newNode = malloc(sizeof(struct node));
  (*newNode).data = data;

  (*newNode).next = *headRef;
  *headRef = newNode;
}

void printList(struct node *headRef) {
  while (headRef != NULL) {
    printf("%d -> ", headRef->data);
    headRef = headRef->next;
  }
  printf("\n");
}

int LenghtList(struct node *headRef) {
  int len = 0;
  while (headRef) {
    len++;
    headRef = (*headRef).next;
  }

  return len;
}

int Count(Node **headRef, int data) {
  int count = 0;
  while (*headRef) {
    if (data == (**headRef).data)
      count++;
    *headRef = (**headRef).next;
  }
  return count;
}

int GetNth(Node *headRef, int idx) {
  assert(idx >= 0 && idx < LenghtList(headRef));
  while (idx != 0) {
    headRef = (*headRef).next;
    idx--;
  }
  return (*headRef).data;
}

void LenghtTest() {
  struct node *head = NULL;
  Push(&head, 1);
  Push(&head, 2);
  Push(&head, 3);

  int len = LenghtList(head);
  printf("%d\n", len);
}

void DeleteListDommie(Node **headRef) {
  if (*headRef == NULL)
    return;
  else {
    DeleteListDommie(&((*headRef)->next));
    free(*headRef);
    *headRef = NULL;
  }
}

void DeleteListChad(Node **headRef) {
  Node *current = *headRef;
  Node *aux = *headRef;
  while (aux != NULL) {
    aux = aux->next;
    free(current);
    current = aux;
  }
  *headRef = NULL;
}

// Aqui deberia ir la funcion POP()
int Pop(struct node** headRef) {
  int poped = (*headRef)->data;
  struct node* current = (*headRef)->next;
  free(*headRef);
  *headRef = current;
  return poped;
}

void InsertNth(Node **headRef, int idx, int data) {
  assert(idx >= 0 && idx <= LenghtList(*headRef));
  Node *previus = NULL;
  Node *current = *headRef;
  // Caso especial no necesito hacer nada, el Push se ecarga de meter el nodo en
  // el frente
  if (!*headRef || idx == 0)
    Push(headRef, data);
  else {
    for (int i = 0; i < idx - 1; i++) {
      current = current->next;
    }
    Push(&(current->next), data);
  }
}

void InsertNthTest() {
  struct node *head = NULL;
  InsertNth(&head, 0, 13);
  InsertNth(&head, 1, 42);
  InsertNth(&head, 1, 777);
  InsertNth(&head, 2, 5);
  printList(head);
  DeleteListChad(&head);
}

void CountTest() {
  struct node *head = NULL;
  Push(&head, 2);
  Push(&head, 2);
  Push(&head, 2);

  int len = Count(&head, 2);
  printf("%d\n", len);
}

void GetNthTest() {
  struct node *head = NULL;
  Push(&head, 1);
  Push(&head, 2);
  Push(&head, 3);

  int len = GetNth(head, 2);
  printf("%d\n", len);
}

void DeleteTest() {
  struct node *head = NULL;
  Push(&head, 3);
  Push(&head, 2);
  Push(&head, 5);
  DeleteListDommie(&head);
  int len = LenghtList(head);
  printf("%d\n", len);
}

void DeleteChadTest() {
  struct node *head = NULL;
  Push(&head, 3);
  Push(&head, 2);
  Push(&head, 5);
  DeleteListChad(&head);
  int len = LenghtList(head);
  printf("%d\n", len);
}

void popTest() {
  struct node *head = NULL;
  Push(&head, 1);
  Push(&head, 2);
  Push(&head, 3);

  printList(head);

  printf("Pop: %d\n", Pop(&head));
  /* Pop(&head); */

  printList(head);
}

int main() {
  /* LenghtTest(); */
  /* CountTest(); */
  /* GetNthTest(); */
  /* DeleteTest(); */
  /* DeleteChadTest(); */
  /* InsertNthTest(); */
  popTest();
  return 0;
}
