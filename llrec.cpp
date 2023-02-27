#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot_recursive(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == nullptr) {
    return;
  }
  Node* tmp = head->next;
  llpivot_recursive(tmp, smaller, larger, pivot);
  if (head->val < pivot) {
    head->next = smaller;
    smaller = head;
  } else {
    head->next = larger;
    larger = head;
  }
  head = next;
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
 smaller = nullptr;
 larger = nullptr;
 llpivot_recursive(head, smaller, larger, pivot);
}
