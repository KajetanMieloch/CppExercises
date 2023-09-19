#include <iostream>
#include <string>

using namespace std;

 
float readHeight(){
	float m;
	cout << "Podaj wzrost (w metrach np. 1.75)";
	cin >> m;
	return m;
}

int readMass(){
	int kg;
	cout << "Podaj wagę (w kilogramach np. 70)";
	cin >> kg;
	return kg;
}

float BMI(float m, int kg){
	return kg/(m*m);
}

void BMIprint(float BMI){
	cout << "BMI na poziomie: " << BMI << endl;
}

int main(){
	BMIprint( BMI( readHeight(), readMass() ) );
	return 0;
}
