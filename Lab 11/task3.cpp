#include<iostream>
#include<stdexcept>

using namespace std;

class invalidtemperatureexception : public exception {

};

		template <typename T>
		T converttofahrenheit(T celsius){
			if(celsius < -273.15){
				throw invalidtemperatureexception();
			}
			
			return celsius*(9/5) + 32;
		}

int main (){
	
	
	try {
		float temp = -300;
		
		cout << "attempting to convert -300" <<endl;
			converttofahrenheit(-300);
			
		}
		
		catch(invalidtemperatureexception & e){
			cout << "Caught InvalidTemperatureException - what(): " << e.what();
		}
			return 0;
	}
	
	
