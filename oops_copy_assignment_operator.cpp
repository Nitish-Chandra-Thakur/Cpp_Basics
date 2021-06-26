#include<iostream>
#include<cstring>
using namespace std;

class Car{
    private:
        float price;

    public:
        char *name;  // This is a pointer that point to dynamically created name later
        int model_no;

    // This is SHALLOW COPY CONSTRUCTOR, that is also created by compiler by-default
        Car(float p, int m, char *n){
            cout<<"Shallow copy default constructor - ";
            price = p;
            model_no = m;
            name = new char[strlen(n)+1];
            strcpy(name, n);
    }

    void set_price(float p){
        float msp = 1000;
        if(p > msp)
            price = p;
        else
            price = msp;
    }
    // This Constructor will help to initializing default object 
        Car(){
            cout<<"Default Constructor "<<endl; 
        }
    // This is a Deep copy that is created by programmer for their implementation.
        Car(Car &x){
            cout<<"Deep copy constructor - ";
            price = x.price;
            model_no = x.model_no;
            name = new char[strlen(x.name)+1];
            strcpy(name, x.name);
        } 

    // Copy Assignment Operator concept
        void operator=(Car &x){
            cout<<"Copy Assignment operator - ";
            price = x.price;
            model_no = x.model_no;
            name = new char[strlen(x.name)+1];
            strcpy(name, x.name);
        } 
        
        void print(){
            cout<<"Name "<<name<<" Model no. "<<model_no<<" has price "<<price;
        }
};

int main(){
    Car c(2000, 99, "BMW");
    c.print();
    cout<<endl;

    Car d(c);       // Copy Constructor object - d that copy object - c elements
    d.name[0] = 'A';    // Changing name of Copying object - d
    d.set_price(5000);
    d.model_no = 987;
    d.print();
    cout<<endl;

    Car e;  // Creating an object
    e = c;  // Copying an object to newly created object, using copy assignment operator
    e.set_price(3500);
    e.name[0] = 'X';
    e.print();
    cout<<endl;
}