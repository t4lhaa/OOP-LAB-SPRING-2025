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
		price = 0;
		available = 1;
	}
	
	
	void setCar(string brand1, string m, float rent, bool a){
		
		brand =brand1;
		model = m;
		price = rent;
		available =  a;
	}
	
	void request(){
		
		if(!available){
			cout << "not avialble, car already rented" << endl;
		}
        else if(available){
			
			cout << "car available , booked" << endl;
			available = 0;
		}
	}
};

int main (){
	
	car car1;
	
	car1.request();
	
	
	return 0;
}
