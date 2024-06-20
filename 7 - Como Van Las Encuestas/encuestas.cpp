//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include<vector>
#include<math.h>

using namespace std;

int numValores(vector<int>v,long long &suma) {
    int i = 1;
    int num = 0;
    int contMin = 1;
    int minimo = v[0];
    
    while (i < v.size()) {
        if (minimo > v[i]) {
            suma = minimo * contMin + suma;
            minimo = v[i];
            num = num + contMin;
            contMin = 1;
        }
        else if (minimo == v[i]) {
            contMin++;
        }
        else if(minimo < v[i]) {
            suma += v[i];
            num++;
        }
        i++;
    }
    
    return num;
}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int tam,num=0;
    long long sum = 0;
    cin >> tam;
    vector<int>v(tam);

    for (size_t i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
       //Calcula el resultado
    num = numValores(v, sum);
       //Escribe el resultado
    cout << sum << " "<< num << endl;;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}