#include <cmath>
#include <iostream>

template <typename T> class list {
  class node {
  public:
    T data;
    node *next = nullptr;
    node *prev = nullptr;
  };
  int size = 0;
  node *head = nullptr;
  node *tail = nullptr;

public:

  T get_head(){return head->data;}

  T get_tail(){return tail->data;}

  int get_size(){return size;}

  bool empty(){return head == nullptr&&tail == nullptr && size == 0;}

  void insert_head(T data) {
    node *temp = new node;
    temp->next = head;
    temp->data = data;
    head = temp;
    if(head->next) head->next->prev = head;
    else tail = head;
    size++;
  }

  void insert_tail(T data) {
    node *temp = new node;
    temp->data = data;
    temp->prev = tail;
    if(tail) tail->next = temp;
    tail = temp;
    if(!temp->prev) head = tail;
    size++;
  }

  void insert(T data, int position){
    if(position == 0) insert_head(data);
    else if(position == size) insert_tail(data);
    else if(position <= size){
      node *temp = head;
      for(int i{1} ; i < position ; i++) temp = temp->next;
      node *newnode = new node;
      newnode->data = data;
      newnode->next = temp->next;
      newnode->prev = temp;
      newnode->next->prev = newnode;
      temp->next = newnode;
      size++;
    }
  }

  T pop_head(){
    if(head){
      T returner = head->data;
      node *temp = head;
      head = head->next;
      delete temp;
      if(head) head->prev = nullptr;
      else tail = nullptr;
      size--;
      return returner;
    }
    return NAN;
  }

  T pop_tail(){
    if(tail){
      T returner = tail->data;
      node *temp = tail;
      tail = tail->prev;
      delete temp;
      if(tail) tail->next = nullptr;
      else head = nullptr;
      size--;
      return returner;
    }
    return NAN;
  }

  T pop(int position){
    if(position == 0) return pop_head();
    else if (position == size -1) return pop_tail();
    else if (position < size) {
      node *temp = head;
      for(int i{1} ; i < position ; i++) temp = temp->next;
      node *newnode = temp->next->next;
      T returner = temp->next->data;
      delete temp->next;
      temp->next = newnode;
      newnode->prev = temp;
      size--;
      return returner;
    }
    return NAN;
  }

  void print_list_from_head(){
    node *temp = head;
    std::cout<<"head to tail: ";
    while (temp) {
      temp->next? std::cout<<temp->data<<" -> ":std::cout<<temp->data<<" -> null";
      temp = temp->next;
    }
  }

  void print_list_from_tail(){
    node *temp = tail;
    std::cout<<"tail to head: ";
    while (temp) {
      temp->prev? std::cout<<temp->data<<" -> ":std::cout<<temp->data<<" -> null";
      temp = temp->prev;
    }
  }
};

int main(){
  list<int> newlist;
  
  std::cout<<"tesing insert head:-\n";
  for (int i{1} ; i <= 6 ; i++) newlist.insert_head(i);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();

  std::cout<<"\ntesting pop head:-\n";
  for(int i{0} ; i < 7 ; i++){
    std::cout<<newlist.pop_head()<<" poped, ";
    newlist.print_list_from_head();
    std::cout<<std::endl;
    newlist.print_list_from_tail();
    std::cout<<std::endl;
  }

  std::cout<<"\ntesting insert tail\n";
  for (int i{1} ; i <= 6 ; i++) newlist.insert_tail(i);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();

  std::cout<<"\ntesting pop tail:-\n";
  for(int i{0} ; i < 7 ; i++){
    std::cout<<newlist.pop_tail()<<" pop:-\n";
    newlist.print_list_from_head();
    std::cout<<std::endl;
    newlist.print_list_from_tail();
    std::cout<<std::endl;
  }

  std::cout<<"\ntesting insert:-\n";
  std::cout<<"list before insertion\n";
  for(int i{1} ; i < 5 ; i++) newlist.insert_head(i);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\ninserting 100 at index 2 gives:-\n";
  newlist.insert(100, 2);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\ninserting 500 at index 0 gives:-\n";
  newlist.insert(500, 0);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\ninserting 300 at index 6 gives:-\n";
  newlist.insert(300, 6);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\ninsert out of bound gives:-\n";
  newlist.insert(50001515, 99);
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();

  std::cout<<"\n\ntesting pop\n";
  std::cout<<"list before poping\n";
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\npoping index 2 gives:-\n";
  std::cout<<newlist.pop(2)<<" has been poped\n";
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\npoping index 0 gives:-\n";
  std::cout<<newlist.pop(0)<<" has been poped\n";
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\npoping index 1 gives:-\n";
  std::cout<<newlist.pop(1)<<" has been poped\n";
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\npoping index 3 gives:-\n";
  std::cout<<newlist.pop(3)<<" has been poped\n";
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();
  std::cout<<"\npoping out of bound gives:-\n";
  std::cout<<newlist.pop(100)<<" has been poped\n";
  newlist.print_list_from_head();
  std::cout<<std::endl;
  newlist.print_list_from_tail();

  std::cout<<"\ntesting get_size: "<<newlist.get_size();

  std::cout<<"\ntesting get_head: "<<newlist.get_head();

  std::cout<<"\ntesting get_tail: "<<newlist.get_tail();

  std::cout<<"\ntesting is empty: "<<newlist.empty();

  std::cout<<"\n\nemptying the list the testing empty() again";

  for (int i{0} ; i <= 2 ; i++) newlist.pop_head();

  std::cout<<"\ntesting get_size: "<<newlist.get_size();

  std::cout<<"\ntesting is empty: "<<newlist.empty();
}
