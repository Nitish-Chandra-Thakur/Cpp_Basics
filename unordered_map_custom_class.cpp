/* This program gets student details and stored in HashTable using unoreder_map. And return students 
   marks. */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Student{
    public:
        string fname;
        string lname;
        string rollno;
        Student(string fn, string ln, string rn){
            fname = fn;
            lname = ln;
            rollno = rn;
        }
    // This function is used for comparing according to the students roll number
        bool operator==(const Student &s)const{
            return rollno == s.rollno?true:false;
        }
};

class HashFun{
    public:
    // This function return hash-value index 
        size_t operator() (const Student &s)const{
            return s.fname.length() + s.lname.length();
        }
};

int main(){
    unordered_map<Student, int, HashFun> student;
    // Inserting Student details 
    Student s1("Nitish", "Thakur", "101");
    Student s2("Mohit", "Raj", "103");
    Student s3("Krishna", "Mohan", "105");
    Student s4("Nitish", "Kumar", "109");
    Student s5("Raja", "Thakur", "111");

    // Add student marks
    student[s1] = 90;
    student[s2] = 84;
    student[s3] = 93;
    student[s4] = 67;
    student[s5] = 76;

    for(auto s:student){
        cout<<s.first.fname<<" "<<s.first.lname<<" "<<"Marks: "<<s.second<<endl;
    }
    cout<<endl;

    // Getting marks of individual student
    cout<<"Marks of student is: "<<student[s3]<<endl;
    return 0;
}