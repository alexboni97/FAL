//ALEX GUILLERMO BONILLA TACO



#include <iostream>
#include <fstream>
#include <vector>
#include<climits>
using namespace std;

/*int minimoD(vector<int>v, const int& pos) {
    size_t indice = pos + 1;
    if (indice == v.size()) return INT_MAX;
    int minimo = v[indice];
    indice++;
    while (indice < v.size()) {
        if (minimo > v[indice]) minimo = v[indice];
        indice++;
    }
    return minimo;
}
int maxI(vector<int>v,const int &pos){
    size_t indice = 0;
    int maximo=v[indice];
    if (indice == pos) {
        return maximo;
    }
    indice++;
    while (indice <= pos) {
        if (maximo < v[indice]) maximo = v[indice];
        indice++;
    }
    return maximo;
}*/
bool bienDivido(vector <int>v,const int & pos) {
    /*if (minimoD(v, pos) > maxI(v, pos)) {
    return true;
    }
    else
    {
        return false;
    }*/
    int i = 0;
    int j = pos + 1;
    int max, min;
    max = v[i];
    min = v[j];
    while (i <= pos || j < v.size() && max < min) {
        
    }
    return false;
}


void resuelveCaso() {
    //resuelve aqui tu caso
    int tamV, pos;
       //Lee los datos
    cin >> tamV >> pos;
    vector<int>v(tamV);

    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
       //Calcula el resultado
    bienDivido(v,pos);
    //Escribe el resultado
    if (bienDivido(v,pos)) {
        cout << "SI\n";
    }
    else
    {
        cout << "NO\n";
    }

    
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
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