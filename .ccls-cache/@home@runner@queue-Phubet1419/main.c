#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

int main(int argc, char **argv) {
  // NodePtr headPtr=NULL;
  // NodePtr tailPtr=NULL;
  // For struct Queue
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;

  int i, x, cash = 0, peo = 1;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "x") == 0) {
      printf("customer no %d\n", peo);
      peo++;
      x = dequeue_struct(&q);
      if (x > 0) {
        printf("you have to pay %d\n", x);
        while (cash < x) {
          printf("cash:");
          scanf("%d", &cash);
        } // end while แล้ว

        if (cash == x) {
          printf("Thank you\n");
        } else if (cash > x)
          printf("Thank you \n Change is %d\n", cash - x);
        cash = 0;
      } // end if x>0
      else
        printf("thank you\n");

    } else {
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i + 1]));
      printf("My order is %d\n", atoi(argv[i]));
      i++;
    }
  }


printf("========================\n");
  if (q.size == 1) printf("There is 1 ppl left in the queue\n");
  else if (q.size > 1) printf("There are %d ppl left in the queue\n", q.size);
  printf("Clearing queue\n");
  while (q.size > 0)
    dequeue_struct(&q);
  return 0;
}
