//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
using namespace std;
/*
ESPECIFICACION

{0<temperaturas.size<=10000 ^ Vi:0<=i<temperaturas.size ^ -50<v[i]<=50 }
fun contarPicosValles(int temperaturas[10000], int nTemps) dev (int picos, int valles )


*/


const int MAX_DATOS = 10000;

void contarPicosValles(int temperaturas[], int nTemps, int& picos, int& valles) {

    if (nTemps > 2) {
        int i = 2;
        while (i < nTemps) {
            if (temperaturas[i - 2]<temperaturas[i - 1] && temperaturas[i - 1] > temperaturas[i]) {
                picos += 1;
            }
            if (temperaturas[i - 2] > temperaturas[i - 1] && temperaturas[i - 1] < temperaturas[i]) {
                valles += 1;
            }
            i++;
        }
    }

}

void resuelveCaso() {
    //resuelve aqui tu caso
       //Lee los datos
    int nTemp;
    int temperaturas[MAX_DATOS];
    cin >> nTemp;

    for (int i = 0; i < nTemp; i++) {
        cin >> temperaturas[i];
    }
    //Calcula el resultado
    int picos = 0;
    int valles = 0;
    contarPicosValles(temperaturas, nTemp, picos, valles);
    //Escribe el resultado
    cout << picos << "\t" << valles << endl;

}

int main() {
    // Para la entrada por fichero.

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    cin >> numCasos;
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