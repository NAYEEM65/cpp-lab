//5.implement singly linked list
#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {

int ch, val;
   cout<<"1) Item insert"<<endl;
   cout<<"2) Display"<<endl;
   cout<<"3) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be entered:"<<endl;
            cin>>val;
            insert(val);
            cout<<val;
            cout<<" has been entered"<<endl;
            break;
         }
         case 2: {
            cout<<"The linked list is: ";
            display();
            cout<<"\n\n";
            break;
         }
         case 3: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=3);
   return 0;
}

