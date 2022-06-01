//6. implement reverse linked list
#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

// To create a demo we have to construct a linked list and this
// function is to push the elements to the list.
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}

// Function to reverse the list
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

// To check our program
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Driver function
int main() {
    struct node *head = NULL;


int ch, val;
   cout<<"1) Push in list"<<endl;
   cout<<"2) Linked List Before Reversing"<<endl;
   cout<<"3) Linked List After Reversing"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(&head, val);
            cout<<val;
            cout<<" has been pushed"<<endl;
            break;
         }
         case 2: {
            cout << "Linked List Before Reversing: ";
            printnodes(head);
            reverse(&head);
            cout<<"\n";
            break;
         }
         case 3: {
            cout << endl;
            cout << "Linked List After Reversing: ";
            printnodes(head);
            cout<<"\n";
         }
         case 4: {
             cout<<endl;
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
