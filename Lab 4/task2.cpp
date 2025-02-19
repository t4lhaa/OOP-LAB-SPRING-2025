#include<iostream>

using namespace std;



class car{
	private :
	string brand;
	string model;
	float price;
	int available;
	
	public :
	
	car(){
		
		brand ="unknown";
		model = "generic";
		price = 10;
		available = 1;
	}
	Car(string brand1, string m, float rent, bool a){
		
		brand =brand1;
		model = m;
		price = rent;
		available =  a;
	}
	
	void setCar(string brand1, string m, float rent, bool a){
		
		brand =brand1;
		model = m;
		price = rent;
		available =  a;
	}
	
	void request(int days){
		
		if(!available){
			cout << "not avialble, car already rented" << endl;
		}
        else if(available){
			if(days>5 && days<10){
				price=price*0.95;
			}
			else if(days>10){
				price=price*0.90;
			}
			cout << "car available , booked" << endl;
			cout<<"price: $"<<price;
			available = 0;
		}
	}
};

int main (){
	
	car car1;
	
	car1.request(11);
	
	
	return 0;
}
