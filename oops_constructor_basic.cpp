#include<iostream>
#include<cstring>
using namespace std;

class Car{
    private:
        float price;
    public:
        char name[20];
        int model_no;
    // Setter method for private data memeber price
        void set_price(float p){
            float msp = 100;
            if(p > msp){
                price = p;
            }
            else
                price = msp;
        }
    // Getter method for private data member price
        float get_price(){
            return price;
        }
    // Creating and rewriting default contructor
        Car(){
            cout<<"By Default Constructor"<<endl;
        }
    // Creating another constructor with parameter, so it is called parametrised constructtor
        Car (char *n, int m, float p){
            strcpy(name, n);
            model_no = m;
            price = p;
        }

    // Copy Constructor look like by-default as
        Car(Car &x){
            cout<<"Copy Constructor object ";
            price = x.price;
            model_no = x.model_no;
            strcpy(name, x.name);
        }

        void print(){
            cout<<"Name "<<name<<" Model no. "<<model_no<<" has price "<<price;
        }
};

int main(){
    Car b;        // This will call default constructor that is rewriting by programmer
    Car c("BMW", 9874, 1000);   // Call Constructor with passed parameter

    Car d("Audi", 7896, 2000);      // Call Constructor with passed parameter
    
    //b.print();
    //cout<<endl;
    c.print();
    cout<<endl;

    cout<<"Car D - ";
    d.print();          // Printing Constructor values with given parameter
    cout<<endl;

    Car e(d);  // Copy Constructor, as object "e" is passed with other created object
    //Car f = d;  // Callling or creating Copy Constructor in another way
    cout<<"Car E - ";
    e.set_price(3000);  // Using setter method for price (pvt data member) updation of copy constructor object
    e.model_no = 123456;// Directly update the value of copy constructor object as given data member is public
    e.print();
    return 0;
}