#include <iostream>
using namespace std;
  
int main()
{
	for(int i = 0; i <= 100; i++ ){
		cout << "\033[1;"<< i <<"m"<< "colour nr:"<< i <<"\033[0m\n";
	}
   
    return 0;
}

