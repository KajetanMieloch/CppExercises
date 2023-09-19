#include <iostream>
using namespace std;

int main(){
    const int W = 100;
    const int H = 50;

    for(int j=0; j<H; j++){
		if (j%2==0){
		for(int i=0; i<W; i++){
            int r = (i/float(W))*10;
            int g = (i/float(H))*20;
            int b = (i/float(W))*200;
            if(i%2==0){
				cout << "\x1b[48;2;" << r << ";" << g << ';' << b << "m" <<" \x1b[0m";
			}else{
				cout << "\x1b[48;2;" << b << ";" << g << ';' << r << "m" <<" \x1b[0m";
			}

            
        }
		}else{
		for(int i=0; i<W; i++){
            int r = (i/float(W))*200;
            int g = (i/float(H))*50;
            int b = (i/float(W))*10;
            if(i%2==0){
				cout << "\x1b[48;2;" << r << ";" << g << ';' << b << "m" <<" \x1b[0m";
			}else{
				cout << "\x1b[48;2;" << b << ";" << g << ';' << r << "m" <<" \x1b[0m";
			}
        }
		}
        
        cout << endl;
    }
    return 0;
}
