
#include<bits/stdc++.h>

using namespace std;
#define N 5
int stack1[5], stack2[5]; // declaration of two stacks
// declaration of top variables.
int top1=-1, top2=-1;
int count=0;
// inserting the elements in stack1.
void push1(int data)
{
// Condition to check whether the stack1 is full or not.
 if(top1==N-1)
{
   cout<<"Stack is overflow...";
}
else
{
   top1++;   // Incrementing the value of top1
   stack1[top1]=data;  // pushing the data into stack1
}
}
// Removing the elements from the stack1.
int pop1()
{
// Condition to check whether the stack1 is empty or not.
if(top1==-1)
{
   cout<<"Stack is empty..";
}
else
{
   int a=stack1[top1];  // Assigning the topmost value of stack1 to 'a' variable.
   top1--;  // decrementing the value of top1.
   return a;
}
}
// pushing the data into the stack2.
void push2(int x)
{
//  Condition to check whether the stack2 is full or not
if(top2==N-1)
{
   cout<<"Stack is full..";
}
else
{
    top2++;   // incrementing the value of top2.
    stack2[top2]=x;  // assigning the 'x' value to the Stack2

}
}
// Removing the elements from the Stack2
int pop2()
{
   int element = stack2[top2];  // assigning the topmost value to element
   top2--;  // decrement the value of top2
   return element;
}
// inserting the data into the Queue
void enqueue(int x)
{

        while(top1!=-1)
        {
            push2(pop1());
        }
        push1(x);
         while(top2!=-1)
        {
            push1(pop2());
        }

}
// deleting the data from the Queue
int dequeue()
{
    int element = stack1[top1];
    top1--;
    return element;
 }
// displaying the data of the Queue
void display()
{
    cout<<"\n";
   for(int i=top1; i>=0;i--)
  {
     cout<<stack1[i]<<" ";
  }
  cout<<"\n";
}
int main()
{

  int ch, val;
   cout<<"1) Enqueue (Insert Element)"<<endl;
   cout<<"2) Dequeue (Delete Element)"<<endl;
   cout<<"3) Display"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be entered:"<<endl;
            cin>>val;
            enqueue(val);
            cout<<val;
            cout<<" has been entered"<<endl;
            break;
         }
         case 2: {
            int d  = dequeue();
            cout<<"The deleted element is ";
            cout<<d;
            cout<<"\n\n";
            break;
         }
         case 3: {
            display();
            break;
         }case 4: {
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
