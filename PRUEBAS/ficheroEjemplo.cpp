#include<string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {
	string vuelo,nif;
	int asiento;
	ifstream fichE("datos.txt");
	ofstream fichS("salida.txt");
	fichE >> vuelo;
	fichS << vuelo<<endl;
	while (vuelo != "XX") {
		fichE >> asiento;
			fichS << asiento<< " ";

		while (asiento!= -1) {
			fichE >> nif;
			fichS << nif << endl;

			fichE >> asiento;
			fichS << asiento<<" ";
		}
		fichE >> vuelo;
		fichS <<endl<< vuelo<<endl;

	}

	return 0;
}