#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//String meses a un int
int mesaNum(const string& mes) {
    string meses[] = { "Jan", "Feb","Mar","Apr","May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    for (int i = 0; i < 12; i++) {
        if (mes == meses[i]) return i + 1;
    }
    return 0;
}

struct Fecha {
    int mes, dia, hora, minuto, segundo;
    string ip, mensaje;
};

Fecha obtenerFecha(string& linea) {
    string mesStr, horaStr, diaStr, ipStr, mensaje;

    stringstream ss(linea);
    ss >> mesStr >> diaStr >> horaStr >> ipStr;
    //Detalles de tiempo
    int mes = mesaNum(mesStr);
    int dia = stoi(diaStr);


    int hora = stoi(horaStr.substr(0, 2));
    int minuto = stoi(horaStr.substr(3, 2));
    int segundo = stoi(horaStr.substr(6, 2));

    //Mensaje de razón error
    getline(ss, mensaje);


    return { mes, dia, hora, minuto, segundo, ipStr, mensaje };

}

//Ordenar

//Busqueda


int main() {
    ifstream fileB("bitacora.txt");
    //borrar
    if (!fileB.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    vector<string> lineas;
    string linea;

    while (getline(fileB, linea)) {
        lineas.push_back(linea);
    }

    fileB.close();

    return 0;
}