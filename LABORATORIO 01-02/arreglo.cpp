#include<iostream>
#include"arrays.h"
#define max 10
using namespace std;

int main(){
    int x[max], op,opc,n=-1,dato,i;
    do{
        system("cls");
        cout<<"\n MENU";
        cout<<"\n=================";
        cout<<"\n1. ARRAY DESORDENADO";
        cout<<"\n2. ARRAY ORDENADO";
        cout<<"\n3. SALIR";
        cout<<"\n\t\t OPCION: ";
        cin>>op;
        switch(op){
            case 1:
                do
                {
                    system("cls");
                    cout<<"\n ARREGLOS DESORDENADOS";
                    cout<<"\n=================";
                    cout<<"\n1. INSERTAR";
                    cout<<"\n2. ELIMINAR";
                    cout<<"\n3. MODIFICAR";
                    cout<<"\n4. MOSTRAR";
                    cout<<"\n5. SALIR";
                    cout<<"\n\t\t OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:
                            cout<<"\n\t\t DATO A INSERTAR: ";cin>>dato;
                            inserta_d(x,n,max,dato);
                            mostrar(x,n);
                            break;
                        case 2:
                            cout<<"\n\t\t DATO A ELIMINAR: ";cin>>dato;
                            elimina_d(x,n,dato);
                            mostrar(x,n);
                            break;
                        case 3:
                            cout<<"\n\t\t DATO A MODIFICAR: ";cin>>dato;
                            modifica_d(x,n,dato);
                            mostrar(x,n);
                            break;
                        case 4:
                            cout<<"\n\t\t ARREGLO: ";
                            mostrar(x,n);
                            system("pause");
                            break;
                        case 5:
                            break;
                    }
                }
                while(opc!=5);
            case 2:
                do{
                    system("cls");
                    cout<<"\n ARREGLOS ORDENADOS";
                    cout<<"\n=================";
                    cout<<"\n1. INSERTAR";
                    cout<<"\n2. ELIMINAR";
                    cout<<"\n3. MODIFICAR";
                    cout<<"\n4. MOSTRAR";
                    cout<<"\n5. SALIR";
                    cout<<"\n\t\t OPCION: ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:
                            cout<<"\n\t\t DATO A INSERTAR: ";cin>>dato;
                            inserta_d(x,n,max,dato);
                            mostrar(x,n);
                            break;
                        case 2:
                            cout<<"\n\t\t DATO A ELIMINAR: ";cin>>dato;
                            elimina_d(x,n,dato);
                            mostrar(x,n);
                            break;
                        case 3:
                            cout<<"\n\t\t DATO A MODIFICAR: ";cin>>dato;
                            modifica_d(x,n,dato);
                            mostrar(x,n);
                            break;
                        case 4:
                            cout<<"\n\t\t ARREGLO: ";
                            mostrar(x,n);
                            system("pause");
                            break;
                        case 5:
                            break;
                    }
                }
				while(opc!=5);
        }
    }
	while(op!=3);
    return 0;
}