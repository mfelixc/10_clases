#include <iostream>
#include <string>
using namespace std;

class Boligrafo {
private:
    int tinta;
    string color;
public:
    Boligrafo() {
        tinta = 100;
        color = "Azul";
    }
    int getTinta();
    string getColor();
    bool setColor(string c);
    void escribir(int gasto);
    void recargar(int cantidad);
    void mostrarEstado();
};

int Boligrafo::getTinta() {
    return tinta;
}

string Boligrafo::getColor() {
    return color;
}

bool Boligrafo::setColor(string c) {
    if (c == "Azul" || c == "Rojo" || c == "Verde" || c == "Negro") {
        color = c;
        return true;
    }
    cout << "Color no válido. Los colores válidos son: Azul, Rojo, Verde y Negro." << endl;
    return false;
}

void Boligrafo::escribir(int gasto) {
    if (gasto <= 0) {
        cout << "El gasto debe ser mayor que 0." << endl;
    }
    else if (tinta >= gasto) {
        tinta -= gasto;
    }
    else {
        cout << "No hay suficiente tinta para escribir." << endl;
    }
}

void Boligrafo::recargar(int cantidad) {
    if (cantidad > 0 && tinta + cantidad <= 100) {
        tinta += cantidad;
    }
    else {
        cout << "Cantidad no válida para recargar." << endl;
    }
}

void Boligrafo::mostrarEstado() {
    cout << "Tinta: " << tinta << endl;
    cout << "Color: " << color << endl;
}

int main() {
    Boligrafo boligrafo1;  
    int menu = 0;

    do {
        cout << "\n=== Boligrafo ===" << endl;
        cout << "1. Escribir" << endl;
        cout << "2. Recargar" << endl;
        cout << "3. Mostrar estado" << endl;
        cout << "4. Cambiar color" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> menu;

        switch (menu) {
        case 1: {
            int gasto;
            cout << "Ingrese la cantidad de tinta a gastar: ";
            cin >> gasto;
            boligrafo1.escribir(gasto);
            cout << "Tinta restante: " << boligrafo1.getTinta() << endl;
            cout << "Tinta gastada: " << gasto << endl;
            break;
        }
        case 2: {
            int cantidad;
            cout << "Ingrese la cantidad de tinta a recargar: ";
            cin >> cantidad;
            boligrafo1.recargar(cantidad);
            cout << "Tinta restante: " << boligrafo1.getTinta() << endl;
            break;
        }
        case 3:
            boligrafo1.mostrarEstado();
            break;
        case 4: {
            string nuevoColor;
            cout << "Ingrese el nuevo color: ";
            cin >> nuevoColor;
            boligrafo1.setColor(nuevoColor);
            break;
        }
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (menu != 5);

    return 0;
}