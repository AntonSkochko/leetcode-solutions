typedef struct MyLinkedList {
  int val;
  struct MyLinkedList * next;
} MyLinkedList;


struct ListNode* reverseList(struct ListNode* head) {
  if(!head) return NULL;
  
  struct ListNode * new_head = head, *prev_head = head, *current_node = head;

  while(current_node->next){
    current_node = current_node->next;
    prev_head->next = current_node->next;
    current_node->next = new_head;
    new_head = current_node;
    current_node = prev_head;
  }
  
  return new_head;
}


struct ListNode* reverseList(struct ListNode* head) {
  if (!head || !head->next) return head;

  struct ListNode ** tail = reverseList(head->next);
  
  head->next->next = head;
  
  head->next = nullptr;
  
  return tail;
}
