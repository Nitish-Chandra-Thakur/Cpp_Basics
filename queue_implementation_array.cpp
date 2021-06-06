#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int frnt, rear, curr_size, max_size;
    public:
    // Constructor for creating Queue class
        Queue(int default_size = 8){
            arr = new int[default_size];
            frnt = 0;
            max_size = default_size;
            rear = max_size - 1;
            curr_size = 0;
        }

        bool full(){
            return curr_size == max_size;
        }

        bool empty(){
            return curr_size == 0;
        }

        void push(int data){
            if(!full()){
                rear = (rear + 1)%max_size;
                arr[rear] = data;
                curr_size++;
            }
        }

        void pop(){
            if(!empty()){
                frnt = (frnt + 1)%max_size;
                curr_size--;
            }
        }

        int front(){
            if(!empty()){
                return arr[frnt];
            }
            return 0;
        }

        ~Queue(){
            if(arr != NULL){
                delete [] arr;
                arr = NULL;
            }
        }
};

int main(){
    Queue q;
    for(int i=0; i<12; i++)
        q.push(i);

    q.pop();
    q.pop();

    q.push(100);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}