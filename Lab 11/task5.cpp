#include<iostream>
#include<stdexcept>
using namespace std;

class NegativeStockException:public exception{

};
class OverCapacityStockException:public exception{

};

template<typename T>
class Stock{
private:
T value;
int max;
public:
Stock(T value):value(value),max(100){}

void check(){
    if(value<0){
        throw NegativeStockException();
    }
    else if(value>max){
        throw OverCapacityStockException();
    }
    else{
        cout<<"stock is valid"<<endl;
    }
}
};

int main(){
    try
    {
        Stock<int> S1(-5);
        cout<<"Attempting Stock -5"<<endl;
        S1.check();
    }
    catch(NegativeStockException& e)
    {
        cout<<"Caught Negative Stock Exception "<<e.what() <<endl;
    }
    try
    {
        Stock<int> S2(50);
        cout<<"Attempting Stock 50"<<endl;
        S2.check();
        Stock<double> S3(120);
        cout<<"Attempting Stock 120"<<endl;
        S3.check();
    }
    catch(OverCapacityStockException& e)
    {
        cout<<"Caught Over Capacity Exception "<<e.what() <<endl;
    }
    
}
