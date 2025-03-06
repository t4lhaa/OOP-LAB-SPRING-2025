#include<iostream>
using namespace std;

class Apartment{
    string ID;
    string address;
    string* ownerName;
    public:
    Apartment(string ID, string address, string name):ID(ID),address(address){
        ownerName = new string(name);
    }

    Apartment(Apartment &a){
        ID = a.ID;
        address = a.address;
        ownerName = a.ownerName;
    }
    ~Apartment(){
        delete ownerName;
    }
    void display() const {
        cout <<"Apartment ID: "<<ID << endl;
        cout <<"Owner: " << *ownerName << endl;
        cout <<"Address: " << address<< endl;
    }

};


int main(){
    Apartment a1("834","Hunaid City","Talha");
    a1.display();
    cout<<endl; 
    Apartment a2 = a1;
    a2.display();

    return 0;
}
