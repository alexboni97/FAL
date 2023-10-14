#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Estructura para representar una celda en el laberinto
struct Cell {
    int row;
    int col;
    int cost;

    Cell(int r, int c, int cost) : row(r), col(c), cost(cost) {}

    // Sobrecargamos el operador de comparación para usar con la cola de prioridad
    bool operator>(const Cell& other) const {
        return cost > other.cost;
    }
};

// Movimientos posibles (arriba, abajo, izquierda, derecha)
const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

// Definiciones de tipos
using TipoDatos = vector<vector<int>>;
using TipoSolucion = int;

// Función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {
    int rows = datos.size();
    int cols = datos[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    // Inicializamos la distancia desde el punto de inicio
    dist[0][0] = datos[0][0];
    pq.push(Cell(0, 0, datos[0][0]));

    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();

        if (current.row == rows - 1 && current.col == cols - 1) {
            return current.cost; // Hemos llegado a la esquina inferior derecha
        }

        // Exploramos los movimientos posibles
        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                int newCost = current.cost + datos[newRow][newCol];
                if (newCost < dist[newRow][newCol]) {
                    dist[newRow][newCol] = newCost;
                    pq.push(Cell(newRow, newCol, newCost));
                }
            }
        }
    }

    return -1; // No se encontró un camino válido
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int rows, cols;
    cin >> rows >> cols;

    TipoDatos datos(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> datos[i][j];
        }
    }

    TipoSolucion sol = resolver(datos);
    cout << sol << endl;
}

int main() {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
