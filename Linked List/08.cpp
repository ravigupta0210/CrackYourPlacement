// Multiply two linked lists


long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long a=0,b=0;
  while(l1){
      a = (a*10+l1->data)%1000000007;
      l1=l1->next;
  }
  while(l2){
      b = (b*10+l2->data)%1000000007;
      l2=l2->next;
  }
  return (a*b)%1000000007;
}
