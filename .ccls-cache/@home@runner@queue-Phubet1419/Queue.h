#define price_1 100
#define price_2 20
#define price_3 50
#include <math.h>
#include <stdio.h>

typedef struct {
  NodePtr headPtr, tailPtr;
  int size;
} Queue;

void enqueue_struct(Queue *q, int x, int y) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node) {
    new_node->order_number = x;
    new_node->qty = y;
    new_node->nextPtr = NULL;

    if (q->headPtr == NULL)
      q->headPtr = new_node;

    else
      q->tailPtr->nextPtr = new_node;

    q->tailPtr = new_node;
    q->size++;
  }
}

int dequeue_struct(Queue *q) {
  NodePtr t = q->headPtr;
  int price;
  int cost = t->qty;
  if (q->size > 0) {
    switch (t->order_number) {
    case 1:
      printf("Ramen\n");
      price = price_1 * cost;
      break;
    case 2:
      printf("Somtum\n");
      price = price_2 * cost;
      break;
    case 3:
      printf("KFC\n");
      price = price_3 * cost;
      break;
    default:
      printf("No food\n");
      price = 0;
      break;
    }
    // int value= t->data;
    // q->headPtr=t->nextPtr;
    // if(q->headPtr==NULL)
    //    q->tailPtr==NULL;
    // q->size--;
    // free(t);
    // return value;
    q->headPtr = t->nextPtr;
    if (q->headPtr == NULL)
      q->tailPtr == NULL;
    free(t);
    q->size--;
    return price;
  }
  // printf("Empty queue");
  return 0;
}
