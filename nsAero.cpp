
#include "aerolinea.h"
#include <iostream>
#include <string>

using namespace std;

inline void limpiarPantalla() {
    system("cls");
}

namespace aero {
    typedef struct {
        int n;
        int op;
        int q;
        int numAv;
        int Vueln;
        int Avionn;
        bool ele;
        string aero;
    } TAero;

    void RY(TAero *ptr) {
        ptr->n = ptr->op = ptr->q = 0;
        ptr->Vueln = ptr->numAv = ptr->Avionn = 0;
        ptr->ele = false;

        cout << "Cuantas aerolineas vas a registrar? ";
        cin >> ptr->n;
        Aerolinea *p = new Aerolinea[ptr->n];

        do {
            cout << "1.- Registrar aerolinea." << endl;
            cout << "2.- Ver aerolineas disponibles." << endl;
            cout << "3.- Agregar avion a la flota." << endl;
            cout << "4.- Mostrar aviones." << endl;
            cout << "5.- Agregar vuelo." << endl;
            cout << "6.- Mostrar vuelos." << endl;
            cout << "7.- Eliminar vuelo." << endl;
            cout << "8.- Eliminar avion." << endl;
            cout << "9.- Hacer reservacion." << endl;
            cout << "10.- Mostrar reservaciones." << endl;
            cout << "11.- Salir." << endl;
            cout << "Que deseas hacer? ";
            cin >> ptr->op;
            cout << endl;

            switch (ptr->op) {
                case 1:
                    limpiarPantalla();
                    cout << "El numero de aerolineas que puedes registrar es " << ptr->n - ptr->q << endl;
                    if (ptr->q < ptr->n) {
                        cout << "Ingresa el nombre de la aerolinea: ";
                        cin.ignore();
                        getline(cin, ptr->aero);
                        ptr->ele = false;
                        for (int i = 0; i < ptr->q; i++) {
                            if (p[i].Buscar(ptr->aero)) {
                                ptr->ele = true;
                                break;
                            }
                        }
                        if (!ptr->ele) {
                            p[ptr->q].Leer();
                            ptr->q++;
                        } else {
                            cout << "Esa aerolinea ya fue agregada" << endl;
                        }
                    } else {
                        cout << "Ya no puedes registrar más aerolineas " << endl;
                    }
                    cout << endl;
                    break;
                case 2:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    break;
                case 3:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿A qué aerolinea lo vas a agregar? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        p[ptr->numAv - 1].AgregarAvion();
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = 0;
                    break;
                case 4:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << "¿De qué aerolinea? ";
                        cin >> ptr->numAv;
                        p[ptr->numAv - 1].ImprimirAvion();
                        cout << endl;
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = 0;
                    break;
                case 5:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿A qué aerolinea lo vas a agregar? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        if (!p[ptr->numAv - 1].Es_vaciA()) {
                            p[ptr->numAv - 1].AgregarVuelo();
                        } else {
                            cout << "Primero tienes que agregar un avion a la flota de la aerolinea " << endl;
                        }
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = ptr->Avionn = 0;
                    break;
                case 6:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿De qué aerolinea deseas ver los vuelos? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        if (!p[ptr->numAv - 1].Es_vaciA()) {
                            p[ptr->numAv - 1].ImprimirVuel();
                        } else {
                            cout << "Primero tienes que agregar un avion a la flota de la aerolinea " << endl;
                        }
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = 0;
                    break;
                case 7:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿De qué aerolinea vas a eliminar el vuelo? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        if (!p[ptr->numAv - 1].Es_vaciA()) {
                            if (!p[ptr->numAv - 1].Es_vaciO()) {
                                p[ptr->numAv - 1].ImprimirVuel();
                                cout << "¿Qué vuelo vas a eliminar? ";
                                cin >> ptr->Vueln;
                                p[ptr->numAv - 1].EliminarVuelo(ptr->Vueln - 1);
                            } else {
                                cout << "Primero tienes que agregar un vuelo" << endl;
                            }
                        } else {
                            cout << "Primero tienes que agregar un avion a la flota " << endl;
                        }
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = ptr->Vueln = 0;
                    break;
                case 8:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿De qué aerolinea vas a eliminar el avion? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        if (!p[ptr->numAv - 1].Es_vaciA()) {
                            p[ptr->numAv - 1].ImprimirAvion();
                            cout << "¿Qué avion vas a eliminar? ";
                            cin >> ptr->Avionn;
                            p[ptr->numAv - 1].EliminarAvion(ptr->Avionn - 1);
                        } else {
                            cout << "Primero tienes que agregar un avion a la flota de la aerolinea " << endl;
                        }
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = ptr->Avionn = 0;
                    break;
                case 9:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿A qué aerolinea vas a hacer la reservacion? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        if (!p[ptr->numAv - 1].Es_vaciA()) {
                            if (!p[ptr->numAv - 1].Es_vaciO()) {
                                p[ptr->numAv - 1].Ims();
                                cout << "¿A qué avion vas a agregar la reservacion? ";
                                cin >> ptr->Avionn;
                                p[ptr->numAv - 1].HacerReser(ptr->Avionn - 1);
                            } else {
                                cout << "Primero tienes que agregar un vuelo a la aerolinea" << endl;
                            }
                        } else {
                            cout << "Primero tienes que agregar un avion a la flota de la aerolinea " << endl;
                        }
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = ptr->Avionn = 0;
                    break;
                case 10:
                    limpiarPantalla();
                    if (!p[0].Es_vacia(ptr->q)) {
                        cout << "Aerolineas disponibles: " << endl;
                        for (int i = 0; i < ptr->q; i++) {
                            cout << i + 1 << ".- ";
                            p[i].ImprimirNombre();
                        }
                        cout << endl;
                        do {
                            cout << "¿De qué aerolinea? ";
                            cin >> ptr->numAv;
                        } while (ptr->numAv <= 0);
                        if (!p[ptr->numAv - 1].Es_vaciA()) {
                            if (!p[ptr->numAv - 1].Es_vaciO()) {
                                p[ptr->numAv - 1].Ims();
                                cout << "¿De qué avion? ";
                                cin >> ptr->Avionn;
                                if (!p[ptr->numAv - 1].Sav(ptr->Avionn - 1)) {
                                    cout << "Reservacion: " << endl;
                                    p[ptr->numAv - 1].VerPasa(ptr->Avionn - 1);
                                } else {
                                    cout << "Primero tienes que hacer una reservacion." << endl;
                                }
                            } else {
                                cout << "Primero tienes que agregar un vuelo a la aerolinea" << endl;
                            }
                        } else {
                            cout << "Primero tienes que agregar un avion a la flota de la aerolinea " << endl;
                        }
                    } else {
                        cout << "Primero tienes que registrar un nombre de aerolinea " << endl;
                    }
                    cout << endl;
                    ptr->numAv = ptr->Avionn = 0;
                    break;
                case 11:
                    break;
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }
        } while (ptr->op != 11);

        delete[] p; 
    }
}
