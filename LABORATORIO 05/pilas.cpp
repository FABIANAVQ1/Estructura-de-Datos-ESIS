#include <iostream>
using namespace std;
#define MAX 100

void insertarPila(int pila[], int &tope, int dato) {
    if (tope < MAX - 1) {
        tope++;
        pila[tope] = dato;
        cout << "El valor " << dato << " se ha insertado correctamente en la pila." << endl;
    } else {
        cout << "Desbordamiento de pila." << endl;
    }
}

void eliminarPila(int pila[], int &tope) {
    if (tope >= 0) {
        int dato = pila[tope];
        tope--;
        cout << "El valor " << dato << " se ha eliminado de la pila." << endl;
    } else {
        cout << "Subdesbordamiento de pila." << endl;
    }
}

int main() {
    int pila[MAX];
    int tope = -1;
    int opcion;
    int valor;

    do {
        cout << "------------" << endl;
        cout << "PILAS" << endl;
        cout << "------------" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Salir" << endl;
        cout << "------------" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor entero para insertar en la pila: ";
                cin >> valor;
                insertarPila(pila, tope, valor);
                break;
            case 2:
                eliminarPila(pila, tope);
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}
