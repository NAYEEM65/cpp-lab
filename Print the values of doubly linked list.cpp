#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *previous;
    struct node *next;
};

//Represent the head and tail of the doubly linked list
struct node *head, *tail = NULL;

//addNode() will add a node to the list
void addNode(int data) {
    //Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    //If list is empty
    if(head == NULL) {
        //Both head and tail will point to newNode
        head = tail = newNode;
        //head's previous will point to NULL
        head->previous = NULL;
        //tail's next will point to NULL, as it is the last node of the list
        tail->next = NULL;
    }
    else {
        //newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        //newNode's previous will point to tail
        newNode->previous = tail;
        //newNode will become new tail
        tail = newNode;
        //As it is last node, tail's next will point to NULL
        tail->next = NULL;
    }
}

//display() will print out the nodes of the list
void display() {
    //Node current will point to head
    struct node *current = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of doubly linked list: \n");
    while(current != NULL) {
        //Prints each node by incrementing pointer.
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{

int ch, val;
   cout<<"1) AddNode"<<endl;
   cout<<"2) Display"<<endl;
   cout<<"3) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be Enqueued:"<<endl;
            cin>>val;
            addNode(val);
            break;
         }
         case 2: {
            display();
            cout<<"\n";
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

