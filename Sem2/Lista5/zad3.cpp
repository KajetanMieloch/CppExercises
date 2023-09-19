#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <vector>

using namespace std;

int wolno = 150000;
int normalnie = 80000;
int szybko;

void hud(){
	cout << "\x1b[102m **********WKRYTO PROMIENIOWANIE, ZACHOWAJ OSTROŻNOŚĆ**********" << "\x1b[0m"<< endl;
	cout << "\x1b[102m **************************************************************" << "\x1b[0m"<< endl;
	cout << "\x1b[102m **************************************************************" << "\x1b[0m"<< endl;
	cout << "\x1b[102m ***********BRAK UWAGI MOZE MIEĆ NASTĘPUJĄCY SKUTEK:***********" << "\x1b[0m"<< endl;
	cout << "\x1b[102m                               /$$                             " << "\x1b[0m"<< endl;
	cout << "\x1b[102m                               |__/                            " << "\x1b[0m"<< endl;
	cout << "\x1b[102m    /$$$$$$$ /$$$$$$/$$$$  /$$  /$$$$$$   /$$$$$$   /$$$$$$$   " << "\x1b[0m"<< endl;
	cout << "\x1b[102m    /$$_____/| $$_  $$_  $$| $$ /$$__  $$ /$$__  $$ /$$_____/  " << "\x1b[0m"<< endl;
	cout << "\x1b[102m   |  $$$$$$ | $$ \\ $$ \\ $$| $$| $$$$$$$$| $$  \\__/| $$        " << "\x1b[0m"<< endl;
	cout << "\x1b[102m    \\____  $$| $$ | $$ | $$| $$| $$_____/| $$      | $$        " << "\x1b[0m"<< endl;
	cout << "\x1b[102m   /$$$$$$$/| $$ | $$ | $$| $$|  $$$$$$$| $$      |  $$$$$$$   " << "\x1b[0m"<< endl;
	cout << "\x1b[102m   |_______/ |__/ |__/ |__/|__/ \\_______/|__/       \\_______/  " << "\x1b[0m"<< endl;
	cout << "\x1b[102m                                                               " << "\x1b[0m"<< endl;
	cout << "\x1b[102m                                                               " << "\x1b[0m"<< endl;
}
void clear() {
    cout << "\x1B[2J\x1B[H";
	hud();
}

void menuText(string str, int tempo){
	clear();
	for (int i = 0; i < str.size(); i++){
		usleep(tempo);
		cout << str[i]<<flush;
	}
}

int gameOver(){
	menuText("...", wolno);
	menuText("..", wolno);
	menuText(".", wolno);
	menuText("...to...?...Koniec?", wolno);
	menuText("A gdzie wybu...", wolno);
	system("clear");

	int W = 3000;
	int H = 1;
	int r = (255);
	int g = (255);
	int b = (255);


		for(int i=0;i<=H;i++){
		for(int i=0;i<=W;i++)
		{
			usleep(500);
			cout << "\x1b[48;2;" << r << ";" << g << ';' << b << "m" <<" \x1b[0m";
		
		}	
		}
		exit (EXIT_FAILURE);
		return 0;
}

int timerGra(float timer, string ciag){
	for(;;){
	cout << "Podopowiedz. Będziesz widział ciągi niezrozumiałych znaków" << endl;
	cout << "Wyszukaj cyfry i ZAPAMIĘTAJ JE" << endl;
	cout << "BĄDZ SZYBKI. REAKTOR NIE BĘDZIE NA CIEBIE CZEKAŁ!!!!" << endl;
	cout << ciag << endl;
	if(timer > 5){
		cout << "\x1b[102m Timer:" << timer << "\x1b[0m"<< endl;
	}else{
		cout << "\x1b[101m Timer:" << timer<< "\x1b[0m" << endl;
	}
	
	

	usleep(100000); //czeka sekunde przed odświerzeniem;
	timer -= 0.1;
	clear();
	if(timer <= 0){
		return 0;
	}

}	
}


string lvlHandler(int LEN, int ileCyfr, float timer){
	
	const char CHARS[] = "!@#$%^&*(){}~:?/><`|;\[],./abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int NUM_CHARS = sizeof(CHARS) - 1;
	
	string kodyDost;
	
	
	srand(time(0));

    string str;

    for (int i = 0; i < LEN; ++i)
    {
        int index = rand() % NUM_CHARS;

        str += CHARS[index];
    }
    
    if(ileCyfr > 1){
		for (int i = 0; i < ileCyfr; ++i)
			{
				int num = rand()%10;

				std::string num_str = std::to_string(num);

				int pos = rand()%2+(5*i)+2 % (str.length() + 1);

				str.insert(pos, num_str);
				
				kodyDost += num_str;
			}
		}
		else{
			for (int i = 0; i < ileCyfr; ++i)
				{
					int num = rand()%10;

					std::string num_str = std::to_string(num);

					int pos = rand()%LEN % (str.length() + 1);

					str.insert(pos, num_str);
					
					kodyDost += num_str;
				}
		}
    


	
	timerGra(timer, str);
	
	return kodyDost;
}

void lvlDesign(int LEN, int ileCyfr, float timer, bool ostatni = 0){
	string kod;
	string odp;
	usleep(1000000);
	kod = lvlHandler(LEN,ileCyfr,timer);
	menuText("Podaj kody dostepowe", normalnie);
	cout << kod << endl; //USUNAC PO DEBUGINGU
	cout << endl;
	cin >> odp;
	menuText("poprawna odpowiedź to.....", wolno);
	cout << kod << endl;
	usleep(200000);
	if(kod != odp and !ostatni){
		gameOver();
	}
	
	if(ostatni){
		menuText("Zrobiłem wszystko co w mojej mocy.....", wolno);
		menuText("GRATULACJE WYGRAŁEŚ!", wolno);
		menuText("Ale i tak.....", wolno);
		gameOver();
	}
}

void wygrana(){
	
	menuText("*ssh@reaktor.czarnobyl.gov.ua*", wolno);
	menuText("Myślisz że to możliwe?", normalnie);
	menuText("N I E", wolno);
	lvlDesign(1000,50,20,1);
}

void poziom4(){

	menuText("Sterownia", wolno);
	menuText("hehe", normalnie);
	menuText("no widzisz WSZYSCY popełniamy błędy", normalnie);
	menuText("...", normalnie);
	menuText("ALE NIE ATOMOWE IMBECYLU!", normalnie);
	menuText("*ssh@reaktor.czarnobyl.gov.ua*", normalnie);
	menuText("*podaj hasło*", normalnie);
	menuText("Łęcina podaj hasło...", normalnie);
	menuText("Domino zna...", normalnie);
	menuText("*Domino jest na L4*", normalnie);
	menuText("Włam się do reaktora!", normalnie);
	lvlDesign(200,4,12);
	wygrana();	
}

void poziom3(){

	menuText("Sterownia", wolno);
	menuText("Ufff.. udało ci się.", normalnie);
	menuText("*Łęcina opiera sie o konsole*", normalnie);
	menuText("...", normalnie);
	menuText("... i przez przypadek wpisał JEDNĄ CYFRĘ. Wiesz co ROBIĆ!.", normalnie);
	lvlDesign(200,1,12);
	poziom4();
	
}

void poziom2(){

	menuText("Sterownia", wolno);
	menuText("Wchodzisz do środka sterowni.", normalnie);
	menuText("Jeden twój kolega (Łęcina) wiedząc że to jego wina panicznie wpisuje komendy do komputera.", normalnie);
	menuText("Niestety popełnił błąd i przez przypadek wpisał JEDNĄ CYFRĘ. ZNAJDZ JĄ!.", normalnie);
	lvlDesign(100,1,8);
	poziom3();
	
}

void poziom1(){

	menuText("Korytarz przed sterownią", wolno);
	menuText("Przed sobą widzisz klawiature obok drzwi, musisz podać kod, aby wejść do sterowni", normalnie);
	lvlDesign(20,4,15);
	poziom2();
}


void wybor(string odp){
	if(odp == "T" or odp == "t"){
		poziom1();
	}
	else{
		gameOver();
	}
}

//\x1b[33m

void promyczek(){
cout << "                              " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                             " << "\x1b[100m" << " " << "\x1b[103m"<< " " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                            " << "\x1b[100m" << " " << "\x1b[103m"<< "   " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                           " << "\x1b[100m" << " " << "\x1b[103m"<< "     " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                          " << "\x1b[100m" << " " << "\x1b[103m"<< "       " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                         " << "\x1b[100m" << " " << "\x1b[103m"<< "         " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                        " << "\x1b[100m" << " " << "\x1b[103m"<< "           " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                       " << "\x1b[100m" << " " << "\x1b[103m"<< "             " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                      " << "\x1b[100m" << " " << "\x1b[103m"<< "               " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                     " << "\x1b[100m" << " " << "\x1b[103m"<< "                 " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                    " << "\x1b[100m" << " " << "\x1b[103m"<< "                   " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                   " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "        !!!!         " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                  " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "         !!!!          " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                 " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "          !!!!           " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "                " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "           !!!!            " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "               " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "            !!!!             " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "              " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "             !!!!              " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "             " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "              !!!!               " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "            " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "               !!!!                " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "           " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                !!!!                 " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "          " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                                       " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "         " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                  ####                   " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "        " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                   ####                    " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "       " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                                             " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "      " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "        _   ___      ____ _  __ _  __ _        " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "     " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "        | | | \\ \\ /\\ / / _` |/ _` |/ _` |        " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "    " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "         | |_| |\\ V  V / (_| | (_| | (_| |         " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "   " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "           \\__,_| \\_/\\_/ \\__,_|\\__, |\\__,_|          " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "  " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                           __/ |                       " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << " " << "\x1b[100m" << " " << "\x1b[103m\x1b[31m"<< "                           |___/                         " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
cout << "" << "\x1b[100m" << " " << "\x1b[100m\x1b[31m"<< "                                                           " << "\x1b[100m" << " " << "\x1b[0m"<< endl;
}
void menu(){
	string odp;
	
	promyczek();
	
	usleep(10000000);
	
	menuText("Czarnobylska Elektrownia Jądrowa  ", normalnie);
	menuText("26 kwietnia 1986 roku  ", normalnie);
	menuText("godzina 1:00  ", normalnie);
	menuText("dokładnie 23 minuty przed wybuchem  ", normalnie);
	menuText("czy chcesz zmienić bieg historii?  ", normalnie);
	menuText("teraz masz szanse  ", normalnie);
	menuText("podejmiesz próbe???  [T/N]", wolno);
	cout << endl;
	cin >> odp;
	wybor(odp);
	
}

int main(){
	menu();
}
