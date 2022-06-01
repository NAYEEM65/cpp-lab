//3. Implement stack using queue
#include <iostream>
#include <queue>
using namespace std;

class Stack {

    queue<int> primary_queue, secondary_queue;

    public:
        void push(int element){

            // enqueue in secondary_queue
            secondary_queue.push(element);

            // add elements of primary_queue to secondary_queue
            while(!primary_queue.empty()){
                secondary_queue.push(primary_queue.front());
                primary_queue.pop();
            }

            // swapping the queues
            queue<int> temp_queue = primary_queue;
            primary_queue = secondary_queue;
            secondary_queue = temp_queue;
        }

        void pop(){
            if(primary_queue.empty()){
                return;
            } else {
                primary_queue.pop();
                 cout<<"item popped "<<endl;
            }
        }

        int top(){
            if(primary_queue.empty()){
                return -1;
            } else {
                return primary_queue.front();
            }
        }

        void displayStack()
        {
            queue<int> temp_queue = primary_queue;

            while(!temp_queue.empty()){
                cout<<temp_queue.front()<<" ";
                temp_queue.pop();
            }
            cout<<"\n";

        }
};

int main(){

    Stack s;



    cout<<"Top: "<<s.top()<<"\n";



  int ch, val;
   cout<<"1) Enqueue"<<endl;
   cout<<"2) Dequeue"<<endl;
   cout<<"3) Display"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            s.push(val);
            break;
         }
         case 2: {

            s.pop();
            break;
         }
         case 3: {
             s.displayStack();
            break;
         }
         case 4: {
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
