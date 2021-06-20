/* This program take name and age of n-persons and sorting the largest k-person like if we take n=100000
   and looking for first 10 aged person from given pool of persons*/
#include<iostream>
#include<queue>
using namespace std;

class Person{
    public:
        string name;
        int age;
        Person(){

        }
        Person(string n, int a){
            name = n;
            age = a;
        }
};

// This class is used for comparing ages of two persons
class PersonCompare{
    public:
        bool operator()(Person A, Person B){    // operator overloading is used and work as functor
            return A.age < B.age;
        }
};



int main(){
    int n;
    cin>>n;

    priority_queue<Person, vector<Person>, PersonCompare> pq;
    for(int i=0; i<n; i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name, age);
        pq.push(p); 
    }
    cout<<endl;
    int k
    cin>>k;;
    for(int i=0; i<k; i++){
        Person p = pq.top();
        cout<<p.name<<" "<<p.age<<endl;
        pq.pop();
    }

    return 0;
}