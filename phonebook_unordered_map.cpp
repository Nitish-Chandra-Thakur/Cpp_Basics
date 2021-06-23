#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
// string store Name and vector<string> store multiple phone no. of same person
    unordered_map<string, vector<string>> phbook;

    phbook["Nitish"].push_back("9110166");
    phbook["Raja"].push_back("8760000");
    phbook["Mohit"].push_back("9015692");
    phbook["Krishna"].push_back("7569785");
    phbook["Krishna"].push_back("6009753");
    phbook["Siddharth"].push_back("9875612");
    phbook["Nitish"].push_back("8053645");
    phbook["Krishna"].push_back("8569712");

    for(auto p:phbook){
        cout<<p.first<<"->";
        for(auto m:p.second){
            cout<<m<<",";
        }
        cout<<endl;
    }

    return 0;
}