//NOMBRE y APELLIDOS: Sergio S�nchez Carrasco. E53

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


/*
EXPLICACI�N DEL EJERCICIO:

Se trata de un ejercicio de vuelta atr�s en el cual tenemos que conseguir matricular a un alumno, consiguiendo 
cumplir las restricciones.

DATOS DEL PROBLEMA:

Los datos que nos ofrece el ejercicio son:

    � int n: N�mero de asignaturas
    � int C: N�mero de cr�ditos m�nimo que tiene que cumplir para poder matricularse.
    � vector<char> aprobadas_suspensas: Vector con las asignaturas ya aprobas (A) y las que quedan por aprobar (N).
    � vector<int> r: Vector de prerrequisitos, r[i] representa qu� asignatura debe estar aprobada para matricularse de i.
    � vector<int> creditos_asignaturas: Cr�ditos como consecuencia de matricularse de cierta asignatura.
    � vector<int> coste_asignaturas: Coste que tiene matricularse de la asignatura i.

�RBOL DE EXPLORACI�N:

El �rbol de exploraci�n que he planteado es un �rbol de profundidad n (0...n-1 asignaturas) y de anchura dos. Es, por tanto, un �rbol binario
para el cual decidimos para cada nivel (para cada asignatura) si nos matriculamos o no nos matriculamos.

COSTE:

Como consecuencia del �rbol de exploraci�n, el coste de nuestro algoritmo pertenece al O(2^n)

RESTRICCIONES:

    -EXPL�CITAS:

        � Los cr�ditos de las asignaturas en las que nos matriculemos tiene que ser >=C, siendo C el n�mero de cr�ditos.
        � Algunas de las n asignaturas tienen un prerrequisito.
        � Estos prerrequisitos se muestran en un vector para el cual para la asignatura i nos muestra qu� asignatura hay que tener aprobada.

    -IMPL�CITAS:
        
        � Sabemos que asignaturas est�n o no aprobadas.
        � El coste de las asignaturas debe de ser M�NIMO.

MARCADORES:

Los marcadores nos ayudan a realizar la poda de factibilidad por ejemplo. Suponen un peque�o aumento en el coste en espacio.
Los marcadores que he utilizado son:

    �vector<bool> solucion_parcial: True si podemos matricularnos de la asignatura.
    �vector<bool> solucion_mejor: Asignaturas que hemos cogido en el mejor de los casos.
    �int costeParcial: Coste de la rama que estamos explorando 
    �int costeMejor: Coste mejor para el caso base del algoritmo
    �int creditosParciales: Creditos de la rama que estamos explorando.
    �int creditos_caso_mejor: Creditos de los que nos matricular�amos en el caso de que llegamos al mejor caso. 
    �bool llegamos_a_solucion: Si hemos llegado a una soluci�n factible o no.


PODA DE OPTIMALIDAD:





*/
void asignaturas_sin_poda(const vector<char>& aprobadas_suspensas, const vector<int>& r, const vector<int>& creditos_asignaturas, const vector<int>& coste_asignaturas,
int n, int C, vector<bool>& solucion_parcial, vector<bool>& solucion_mejor, int& costeParcial, int& costeMejor, int& creditos_parciales,
int& creditos_caso_mejor, int k, bool &llegamos_a_solucion) {

    //Hijo izquierdo. Cogemos la asignatura. Pero comprobamos que la podamos coger...
    if (aprobadas_suspensas[k]!='A' && (r[k]==-1|| aprobadas_suspensas[r[k]]=='A'))
    {
        solucion_parcial[k] = true; //Podemos coger el objeto.

        /*MARCAJE*/
        costeParcial += coste_asignaturas[k];   
        creditos_parciales += creditos_asignaturas[k]; 
        
        if (k == n-1)
        {
            //Comprobar que el n�mero de cr�ditos es correcto
            if (creditos_parciales >= C)
            {
                //Comprobar que el coste es m�nimo
                if (costeParcial< costeMejor)
                {
                    llegamos_a_solucion = true;
                    costeMejor = costeParcial;
                    solucion_mejor = solucion_parcial;
                    creditos_caso_mejor = creditos_parciales;
                }
            }
        }
        else
        {
            asignaturas_sin_poda(aprobadas_suspensas, r, creditos_asignaturas, coste_asignaturas, n, C, solucion_parcial,
                solucion_mejor, costeParcial, costeMejor, creditos_parciales, creditos_caso_mejor, k + 1, llegamos_a_solucion);
        }
        
        
        /*DESMARCAJE*/
        costeParcial -= coste_asignaturas[k];
        creditos_parciales -= creditos_asignaturas[k];
    }

    //Hijo derecho: No cogemos el objeto
    solucion_parcial[k] = false;

    if (k==n-1)
    {
        //Comprobar que el n�mero de cr�ditos es correcto
        if (creditos_parciales >= C)
        {
            //Comprobar que el coste es m�nimo
            if (costeParcial < costeMejor)
            {
                llegamos_a_solucion = true;
                costeMejor = costeParcial;
                solucion_mejor = solucion_parcial;
                creditos_caso_mejor = creditos_parciales;
            }
        }
    }
    else
    {
        asignaturas_sin_poda(aprobadas_suspensas, r, creditos_asignaturas, coste_asignaturas, n, C, solucion_parcial,
            solucion_mejor, costeParcial, costeMejor, creditos_parciales, creditos_caso_mejor, k + 1, llegamos_a_solucion);
    }
}

void resuelveCaso() {

    int n;//N�mero de asignaturas
    int C;//N�mero de cr�ditos m�nimo que tiene que cumplir para poder matricularse.

    cin >> n >> C;

    vector<char> aprobadas_suspensas(n); //Vector con las asignaturas ya aprobas (A) y las que quedan por aprobar (N).
    vector<int> r(n);//Vector de prerrequisitos, r[i] representa qu� asignatura debe estar aprobada para matricularse de i.
    vector<int> creditos_asignaturas(n);//Cr�ditos como consecuencia de matricularse de cierta asignatura.
    vector<int> coste_asignaturas(n); //Coste que tiene matricularse de la asignatura i.

    for (int i = 0; i < n; i++)
    {
        cin >> aprobadas_suspensas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> creditos_asignaturas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> coste_asignaturas[i];
    }
   
    vector<bool> solucion_parcial(n, false);//True si podemos matricularnos de la asignatura.
    vector<bool> solucion_mejor(n, false); //Asignaturas que hemos cogido en el mejor de los casos.
    int costeParcial = 0;
    int costeMejor = 100000;
    int creditosParciales=0;
    int creditos_caso_mejor;
    bool llegamos_a_solucion=false;

    asignaturas_sin_poda(aprobadas_suspensas, r, creditos_asignaturas, coste_asignaturas, n, C, solucion_parcial,
        solucion_mejor, costeParcial, costeMejor, creditosParciales, creditos_caso_mejor, 0, llegamos_a_solucion);

    if (!llegamos_a_solucion)
    {
        cout << "NO\n";
    }
    else
    {
        cout << costeMejor << endl;
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