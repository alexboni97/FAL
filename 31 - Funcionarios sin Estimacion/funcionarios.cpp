//ALEX GUILLERMO BONILLA TACO
//E12

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) return false;


	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}