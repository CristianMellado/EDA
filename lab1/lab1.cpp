// lab1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

//calcular la distancia euclidiana
double dist_euclidiana(const vector<double>&a, const vector<double>&b) {
    double suma = 0.0;
    for (size_t i = 0; i < a.size(); i++) {
        double dif = a[i] - b[i];
        suma += dif * dif;
    }
    return sqrt(suma);
}
//genera los ptos aleatorios
vector<vector<double>> generar_puntos(int num_ptos, int dim){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    vector<vector<double>> puntos;

    for (int i = 0; i < num_ptos; i++) {
        vector <double> p(dim);
        for (int j = 0; j < dim; j++) {
            p[j] = dist(gen);
        }
        puntos.push_back(p);
    }
    return puntos;
}

//guarda en los csv
void guardar_dist(const vector<vector<double>> &puntos, int dim) {
    string filename = "distancias_" + to_string(dim) + ".csv";
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "error al abrir " << filename << endl;
        return;
    }
    file << "distancia\n";

    for (size_t i = 0; i < puntos.size(); i++) {
        for (size_t j = i + 1; j < puntos.size(); j++) {
            file << dist_euclidiana (puntos[i], puntos[j]) << "\n";
        }
    }
    file.close();
    cout << "archivo generado " << filename << endl;
}

int main() {
    int num_puntos = 100;
    vector<int> dimensiones = { 10, 50, 100 ,500, 1000, 2000, 5000 };

    for (int d : dimensiones) {
        auto puntos = generar_puntos(num_puntos, d);
        guardar_dist(puntos, d);
    }
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
