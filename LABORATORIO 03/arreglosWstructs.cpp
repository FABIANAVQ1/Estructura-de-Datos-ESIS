#include<iostream>
#include<string.h> 
#define MAX 10
using namespace std; 

struct alumno {
    char codi[10], nomb[20]; 
    float nota1, nota2, prom;
};

void inserta_d(alumno *, int &); 
void elimina_d(alumno *, int &); 
void modifica_d(alumno *, int &); 
int buscar_o(alumno *, int, const char *);
void inserta_o(alumno *, int &); 
void elimina_o(alumno *, int &); 
void modifica_o(alumno *, int &); 
void mostrar(alumno *, int); 

int main() {
    alumno x[MAX];
    int op, opc, n = -1, i;
    do {
        system("cls");
        cout << "\n\tM E N U";
        cout << "\n ==================";
        cout << "\n\n1. ARRAY DESORDENADO";
        cout << "\n\n2. ARRAY ORDENADO";
        cout << "\n\n3. S A L I R";
        cout << "\n\n\t\t\t OPCION:  ";
        cin >> op;
        switch (op) {
            case 1:
                do {
                    system("cls");
                    cout << "\n\n\nARREGLOS DESORDENADOS";
                    cout << "\n==========================";
                    cout << "\n\n1. INSERTAR";
                    cout << "\n\n2. ELIMINAR";
                    cout << "\n\n3. MODIFICAR";
                    cout << "\n\n4. MOSTRAR";
                    cout << "\n\n5. S A L I R";
                    cout << "\n\n\t\t\t OPCION:  ";
                    cin >> opc;
                    system("cls");
                    switch (opc) {
                        case 1:
                            inserta_d(x, n);
                            mostrar(x, n);
                            break;
                        case 2:
                            elimina_d(x, n);
                            mostrar(x, n);
                            break;
                        case 3:
                            modifica_d(x, n);    
                            mostrar(x, n);
                            break;
                        case 4:
                            mostrar(x, n);
                            system("pause");
                            break;
                        case 5:
                            break;
                    }
                } while (opc > 0 && opc < 5);
                break;
            case 2:
                do {
                    system("cls");
                    cout << "ARREGLOS ORDENADOS";
                    cout << "\n==========================";
                    cout << "\n\n1. INSERTAR";
                    cout << "\n\n2. ELIMINAR";
                    cout << "\n\n3. MODIFICAR";
                    cout << "\n\n4. MOSTRAR";
                    cout << "\n\n5. S A L I R";
                    cout << "\n\n\t\t\t OPCION:  ";
                    cin >> opc;
                    system("cls");
                    switch (opc) {
                        case 1:
                            inserta_o(x, n);
                            mostrar(x, n);
                            break;
                        case 2:
                            elimina_o(x, n);
                            mostrar(x, n);
                            break;
                        case 3:
                            modifica_o(x, n);    
                            mostrar(x, n);
                            break;
                        case 4:
                            mostrar(x, n);
                            system("pause");
                            break;
                        case 5:
                            break;
                    }
                } while (opc > 0 && opc < 5);
                break;
            case 3:
                break;
        }
    } while (op > 0 && op < 3);
    return 0;
}

void inserta_d(alumno *x, int &n) {
    int i, j, cen;
    char codigo[10];
    if (n < MAX - 1) {
        cen = 0;
        i = 0;
        cout << "\n\n\nDATOS DEL REGISTRO: ";
        cout << "\n\n\t\t CODIGO : ";
        cin >> codigo;
        if (n > -1) {
            while ((i <= n) && (cen == 0)) {
                if (strcmp(x[i].codi, codigo) == 0) {
                    cen = 1;
                } else {
                    i++;
                }
            }
        }
        if (cen == 0) {
            n++;
            strcpy(x[i].codi, codigo); 
            cout << "\n\n\t\tNOMBRE: "; cin >> x[i].nomb;
            cout << "\n\n\t\tNOTA 1 : "; cin >> x[i].nota1; 
            cout << "\n\n\t\tNOTA 2 : "; cin >> x[i].nota2; 
            x[i].prom = (x[i].nota1 + x[i].nota2) / 2;
            cout << "\n\n\t\tPROMEDIO: " << x[i].prom;
        } else {
            cout << "\n\n\n\nEL DATO YA ESTA REGISTRADO EN LA BASE DE DATOS. No se realizo la inserción.....";
        }
    } else {
        cout << "\n\n\t\tEL ARREGLO ESTA LLENO. No se inserto ningun dato...";
    }
}

void elimina_d(alumno *x, int &n) {
    int i, j, cen;
    char codigo[10];
    cout << "\n\t\tDATO A ELIMINAR : \n\n";
    cout << "\tCODIGO : "; cin >> codigo;
    if (n > -1) {
        i = 0;
        cen = 0;
        while ((i <= n) && (cen == 0)) {
            if (strcmp(x[i].codi, codigo) == 0) {
                cen = 1;
                n--;
                for (j = i; j <= n; j++) x[j] = x[j + 1];
            } else {
                i++;
            }
        }
        if (cen == 0)
            cout << "\n\n\t\t" << codigo << " NO ESTA EN EL ARREGLO\n\n";
    } else {
        cout << "\n\n\nEL ARREGLO ESTA VACIO...\n\n\n"; 
        system("pause");
    }
}

void modifica_d(alumno *x, int &n) {
    int i, cen, op;
    char codigo1[10];
    cout << "\n\t\tCODIGO DEL REGISTRO A MODIFICAR : \n\n"; 
    cout << "\tCODIGO: "; cin >> codigo1;
    if (n > -1) {
        i = 0;
        cen = 0;
        while ((i <= n) && (cen == 0)) {
            if (strcmp(x[i].codi, codigo1) == 0) {
                cen = 1;
                cout << "\n\n\tQUE CAMPO DESEA MODIFICAR? \n\n";
                cout << "1. CODIGO\t2. NOMBRE\t3. NOTA 1\t4. NOTA 2\n\n";
                cout << "OPCION:  "; cin >> op;
                switch (op) {
                    case 1:
                        cout << "\nINGRESA EL CODIGO CORRECTO: "; cin >> x[i].codi;
                        break;
                    case 2:
                        cout << "\nINGRESA EL NOMBRE CORRECTO: "; cin >> x[i].nomb;
                        break;
                    case 3:
                        cout << "\nINGRESA LA NOTA 1 CORRECTA: "; cin >> x[i].nota1; 
                        x[i].prom = (x[i].nota1 + x[i].nota2) / 2;
                        break;
                    case 4:
                        cout << "\nINGRESA LA NOTA 2 CORRECTA : "; cin >> x[i].nota2; 
                        x[i].prom = (x[i].nota1 + x[i].nota2) / 2;
                        break;
                }
            } else {
                i++;
            }
        }
        if (cen == 0) {
            cout << "\n\n\t\tEL CODIGO " << codigo1 << " NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    } else {
        cout << "\n\n\nEL ARREGLO ESTA VACIO...\n\n\n"; 
        system("pause");
    }
}

int buscar_o(alumno *x, int n, const char *codigo) {
    int i = 0;
    while (i <= n && strcmp(x[i].codi, codigo) < 0) {
        i++;
    }
    if (i > n || strcmp(x[i].codi, codigo) > 0)
        return -i;
    else
        return i;
}

void inserta_o(alumno *x, int &n) {
    if (n < MAX - 1) {
        char codigo[10];
        cout << "\n\n\nDATOS DEL REGISTRO: ";
        cout << "\n\n\t\t CODIGO : ";
        cin >> codigo;
        int pos = buscar_o(x, n, codigo);
        if (pos < 0) {
            pos = -pos;
            n++;
            for (int i = n; i > pos; i--) {
                x[i] = x[i - 1];
            }
            strcpy(x[pos].codi, codigo);
            cout << "\n\n\t\tNOMBRE: "; cin >> x[pos].nomb;
            cout << "\n\n\t\tNOTA 1 : "; cin >> x[pos].nota1; 
            cout << "\n\n\t\tNOTA 2 : "; cin >> x[pos].nota2; 
            x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
            cout << "\n\n\t\tPROMEDIO: " << x[pos].prom;
        } else {
            cout << "\n\n\n\nEL DATO YA ESTA REGISTRADO EN LA BASE DE DATOS. No se realizo la inserción.....";
        }
    } else {
        cout << "\n\n\t\tEL ARREGLO ESTA LLENO. No se inserto ningun dato...";
    }
}

void elimina_o(alumno *x, int &n) {
    char codigo[10];
    cout << "\n\t\tDATO A ELIMINAR : \n\n";
    cout << "\tCODIGO : "; cin >> codigo;
    int pos = buscar_o(x, n, codigo);
    if (pos >= 0) {
        for (int i = pos; i < n; i++) {
            x[i] = x[i + 1];
        }
        n--;
    } else {
        cout << "\n\n\t\t" << codigo << " NO ESTA EN EL ARREGLO\n\n";
    }
}

void modifica_o(alumno *x, int &n) {
    char codigo[10];
    cout << "\n\t\tCODIGO DEL REGISTRO A MODIFICAR : \n\n"; 
    cout << "\tCODIGO: "; cin >> codigo;
    int pos = buscar_o(x, n, codigo);
    if (pos >= 0) {
        int op;
        cout << "\n\n\tQUE CAMPO DESEA MODIFICAR? \n\n";
        cout << "1. CODIGO\t2. NOMBRE\t3. NOTA 1\t4. NOTA 2\n\n";
        cout << "OPCION:  "; cin >> op;
        switch (op) {
            case 1:
                cout << "\nINGRESA EL CODIGO CORRECTO: "; cin >> x[pos].codi;
                break;
            case 2:
                cout << "\nINGRESA EL NOMBRE CORRECTO: "; cin >> x[pos].nomb;
                break;
            case 3:
                cout << "\nINGRESA LA NOTA 1 CORRECTA: "; cin >> x[pos].nota1; 
                x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
                break;
            case 4:
                cout << "\nINGRESA LA NOTA 2 CORRECTA : "; cin >> x[pos].nota2; 
                x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
                break;
        }
    } else {
        cout << "\n\n\nEL ARREGLO ESTA VACIO...\n\n\n"; 
        system("pause");
    }
}

void mostrar(alumno *x, int n) 
{
    int i;
    for (i = 0; i <= n; i++) {
        cout << "\nx[" << i + 1 << "]  :  \n\n";
        cout << "\n\n\t\tCODIGO: " << x[i].codi;
        cout << "\n\n\t\tNOMBRE : " << x[i].nomb; 
        cout << "\n\n\t\tNOTA 1 : " << x[i].nota1; 
        cout << "\n\n\t\tNOTA 2 : " << x[i].nota2;
        cout << "\n\n\t\tPROMEDIO : " << x[i].prom;
    }
    cout << endl;
}
