#include <iostream>
using namespace std;

class Calculadora {
    private:
    double primero;   
    double segundo;
    bool comprobar();

    public:
    Calculadora() {
    primero = 0;
    segundo = 0;
    }
    void setNumeros(double a, double b);
    int getPrimero(); 
    int getSegundo();
    int sumar();
    int restar();
    int multiplicar();
    bool dividir();  
};

    bool Calculadora::comprobar(){
        if (primero == 0 || segundo == 0) {
            return false;
        }
        return true;
    }

    void Calculadora::setNumeros(double a, double b) {
        primero = a;
        segundo = b;
    }
    int Calculadora::getPrimero() {
        return primero;
    }
    int Calculadora::getSegundo() {
        return segundo;
    }
    int Calculadora::sumar() {
        return primero + segundo;
    }
    int Calculadora::restar() {
        return primero - segundo;
    }
    int Calculadora::multiplicar() {
        return primero * segundo;
    }
    bool Calculadora::dividir() {
       if (comprobar()) {
        cout << primero / segundo << endl;
        return true;
        }
        else {  
        cout << "No se puede dividir por cero." << endl;  
        return false;
        }
    }


int main() {
    int menu;
    double a, b;
    Calculadora Casio;
    while (menu != 7) {
        cout << "=== Calculadora ===" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Ingresar números" << endl;
        cout << "6. Mostrar números" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> menu;
        switch (menu) {
            case 1:
                cout << "Suma: " << Casio.sumar() << endl;
                break;
            case 2:
            cout << "Resta: " << Casio.restar() << endl;
            break;
        case 3:
            cout << "Multiplicación: " << Casio.multiplicar() << endl;
            break;
        case 4:
            cout << "División: ";
            Casio.dividir();
            break;
        case 5:
            cout << "Ingrese el primer número: ";
            cin >> a;
            cout << "Ingrese el segundo número: ";
            cin >> b;
            Casio.setNumeros(a, b);
            break;
        case 6:
            cout << "Primer número: " << Casio.getPrimero() << endl;
            cout << "Segundo número: " << Casio.getSegundo() << endl;
            break;
        case 7:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
    }
}
return 0;
}