#include<iostream>
using namespace std;

// Class is like creating a new data type
class Car{
    public:
        float price;
        int model_no;
        char name[20];

        void print(){
            cout<<"Name "<<name<<endl;
            cout<<"Model number "<<model_no<<endl;
            cout<<"Price "<<price<<endl;
        }

        float get_discounted_price(float dis){
            return price - price*(1.0 * dis);        
        }
};

int main(){
    // Creating an object of defined data type
    Car c1;
    c1.name[0] = 'B';
    c1.name[1] = 'M';
    c1.name[2] = 'W';
    c1.price = 1000;
    c1.model_no = 1234;
    cout<<sizeof(c1)<<endl;// cout<<sizeof(Car) -> says this much of memeory used if we create object of this type

    // Trying to print data members of given class with provided information
    cout<<c1.name<<" with model no. "<<c1.model_no<<" has price "<<c1.price<<endl;
    cout<<"- - - - - - - - - - - - - - - - - "<<endl;
    c1.print();
    cout<<endl;
    cout<<"Discounted price is "<<c1.get_discounted_price(0.30)<<endl;

    return 0;
}