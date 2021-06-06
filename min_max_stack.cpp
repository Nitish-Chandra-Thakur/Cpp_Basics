/* Designing a stack class, that supports following operations - - - implementing using VECTOR - - -
   - Push(), Pop()
   - Top()
   - GetMin()
   - GetMax()     */

#include<iostream>
#include<vector>
using namespace std;

class MinMaxStack{
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

    public:
        void push(int data){
            int curr_min = data;
            int curr_max = data;
            if(stack.size()){
                curr_min = min(min_stack[stack.size()-1], data);
                curr_max = max(max_stack[stack.size()-1], data);
            }
            stack.push_back(data);
            min_stack.push_back(curr_min);
            max_stack.push_back(curr_max);
        }
        
        int GetMin(){
            return min_stack[min_stack.size() - 1];
        }

        int GetMax(){
            return max_stack[max_stack.size() - 1];
        }

        int top(){
            return stack[stack.size() - 1];
        }

        bool empty(){
            return stack.size() == 0;
        }

        void pop(){
            min_stack.pop_back();
            max_stack.pop_back();
            stack.pop_back();
        }

        void print(){
            for(int x:stack)
                cout<<x<<" ";
            cout<<endl;

            for(int x:min_stack)
                cout<<x<<" ";
            cout<<endl;

            for(int x:max_stack)
                cout<<x<<" ";
        }
};

int main(){
    MinMaxStack ms;
    ms.push(5);
    ms.push(1);
    ms.push(3);
    ms.push(2);
    ms.push(4);
    ms.push(17);
    ms.push(11);
    ms.push(8);

    ms.print();
    cout<<endl;

    cout<<ms.GetMax()<<endl;
    ms.pop();
    cout<<ms.GetMin()<<endl;
    cout<<ms.GetMax()<<endl;

    ms.pop();
    ms.pop();
    cout<<ms.top()<<endl;
    cout<<ms.GetMax()<<endl;

    return 0;
}