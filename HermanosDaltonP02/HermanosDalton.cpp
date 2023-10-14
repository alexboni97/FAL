// ALEX GUILLERMO BONILLA TACO 

#include <iostream>
#include<vector>
#include <fstream>
using namespace std;
/*
{Vi: 0<=i<v.size:v[i]>=1 ^v[i] <= 1000000 ^ v.size>0}
fun esDalton(vector<int>v)  dev bool b
{b=(Vi: 0<=i<v.size()-1:v[i]>v[i+1]} V
{v=(Vi: 0<=i<v.size()-1:v[i]<v[i+1]}
*/

const int MAX_P = 100000;


bool esDalton(vector<int>vinetas) {
    bool dalton=true;
    int i = 1;
    while (i<vinetas.size()-1&&dalton)
    {
        if (vinetas[i - 1] < vinetas[i]&& vinetas[i] < vinetas[i+1]) {
            dalton = true;
            i++;
        }
        else if (vinetas[i - 1] > vinetas[i]&& vinetas[i] > vinetas[i+1]) {
            dalton = true;
            i++;
        }
        else {
            i++;
            dalton = false;
        }
    }
    
    return dalton;
}


bool resuelveCaso() {
    int nPer;
    
    //Leer caso de prueba: cin>>...
    cin >> nPer;
    vector<int>vinetas(nPer);
    for (int i = 0; i < nPer; i++) {
        cin >> vinetas[i];
    }

    if (!std::cin||nPer==0)
        return false;

    //Resolver problema
    //Escribir resultado
    if (esDalton(vinetas)) cout << "DALTON\n" ;
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