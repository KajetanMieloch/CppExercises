#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

int main(){
			
	system("clear");
	
	for(;;){
		int W = 20 + rand() % 40;
		int H = 20;
		int r = (rand() % 255);
		int g = (rand() % 255);
		int b = (rand() % 255);


			for(int i=0;i<=H;i++){
			for(int i=0;i<=W;i++)
			{
				usleep(200 + rand() % 1000);
				cout << "\x1b[48;2;" << r << ";" << g << ';' << b << "m" <<" \x1b[0m";
			}
			cout << endl;
			}
			system("clear");	
			}

	
    return 0;
}
