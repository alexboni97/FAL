//ALEX GUILLERMO BONILLA TACO

#include <iostream>
#include <fstream>
#include <vector>
#include<climits>

using namespace std;

/*
ACLARACIONES:
v: vector donde se almacenaran las temperaturas
v.size= numero de elementos del vector
n=v.size
pos= posicion que divide el vector

ESPECIFICACION:
PRE={v.size>0 ^0<=p<v.size}
bool bienDivido(vector[]v,int n,int pos) dev bool b
POS={b= Vi,j:0<=i<=p<j<n:v[i]<v[j]}
*/

//funcion que resuelve el problema
/*
el coste asintotico de esta funcion es de O(n), donde n es el numero de elementos del vector, tiene este coste al sumar los dos costes de los bucles y las demas instrucciones son de coste costante
*/
bool bienDivido(vector <int>v,const int & n,const int & pos) {
    if(pos==n-1)return true;//coste O(1)
   int maxI=v[0],maxD=v[pos+1];
   for(int i=0;i<pos;i++){//coste=O(p)
        maxI=max(maxI,v[i+1]);
   }
   for(int i=pos+1;i<pos-1;i++){//coste=O(n-p)
        maxD=min(maxD,v[i+1]);
   }
   if(maxI<maxD)return true;
   else return false;
}


void resuelveCaso() {
    //resuelve aqui tu caso
    int n, pos;
       //Lee los datos
    cin >> n>> pos;
    vector<int>v(n);

    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
       //Calcula el resultado
    bool b=bienDivido(v,n,pos);
    //Escribe el resultado
    if (b) {
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