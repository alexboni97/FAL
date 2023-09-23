// ALEX GUILLERMO BONILLA TACO 

#include <iostream>

#include <fstream>
using namespace std;
const int MAX_P = 100000;
const int MAX_ALT = 1000000;


bool esDalton(int vinetas[], const int & nPer) {
    
    if (nPer < 2||nPer>MAX_P|| vinetas[0] == vinetas[1]) return false;
   
    if (vinetas[0] < vinetas[1]) {
        int i = 1;
        while (i < nPer) {
            if (vinetas[i - 1] > vinetas[i]||vinetas[i-1]<=0||vinetas[i]>MAX_ALT) return false;
            i++;
        }
   
    }
    
    else if (vinetas[0] > vinetas[1]) {
        int i = 1;
        while (i < nPer) {
            if (vinetas[i - 1] < vinetas[i] || vinetas[i] <= 0|| vinetas[i-1] > MAX_ALT) return false;
            i++;
        }
    }
    
    return true;
}


bool resuelveCaso() {
    int nPer;
    int vinetas[MAX_P];
    
    //Leer caso de prueba: cin>>...
    cin >> nPer;
    for (int i = 0; i < nPer; i++) {
        cin >> vinetas[i];
    }

    if (!std::cin||nPer==0)
        return false;

    //Resolver problema
    //Escribir resultado
    if (esDalton(vinetas, nPer)) cout << "DALTON\n" ;
    else
        cout << "DESCONOCIDOS\n";
    
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}