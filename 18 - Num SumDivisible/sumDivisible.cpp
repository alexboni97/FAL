
// ALEX GUILLERMO BONILLA TACO

#include <iostream>

#include <fstream>
using namespace std;

int sumatorio(int n, int &r) {
    int s;
    if (n == 0) {
        return s=0;
    }
    else {
        s = sumatorio(n / 10,r) + n % 10;
        r++;
    }
    return s;
}
bool sumdivisible(int n){
    bool loes;
    int r;
    if (n ==0) {
        loes = true;
    }
    else{
        r = 0;
        loes=(sumatorio(n,r)%r==0)&&sumdivisible(n/10);
    }
    return loes;
}
bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;
    if (!std::cin||n==0)
        return false;


    //Resolver problema
    
    //Escribir resultado
    
    if (sumdivisible(n))cout << "SI" << endl;
    else cout << "NO" << endl;
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