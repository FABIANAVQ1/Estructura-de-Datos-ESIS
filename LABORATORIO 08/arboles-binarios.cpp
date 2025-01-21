#include <iostream>
using namespace std;
struct nodo
{
    int inf;
    nodo *izq, *der;
};

void inserta_abb(nodo *&raiz,int dato);
void buscar_abb(nodo *raiz,int dato);
void elimina_abb(nodo *&raiz,int dato);
void preorden(nodo *raiz);
void inorden(nodo *raiz);
void postorden(nodo *raiz);
int main(void)
{
    nodo *raiz = NULL;
    int op,dato;
    char opc;
    system("cls");
    do
    {
        system("cls");
        cout<<"\t\tMENU - ARBOLES BINARIOS\n\n";
        cout<<"\t\t*************************\n\n";
        cout<<"\t\t1. INSERCION\n\n"; 
        cout<<"\t\t2. ELIMINACION\n\n";
        cout<<"\t\t3. BUSQUEDA\n\n";
        cout<<"\t\t4. RECORRIDO PREORDEN\n\n";
        cout<<"\t\t5. RECORRIDO INORDEN\n\n";
        cout<<"\t\t6. RECORRIDO POSTORDEN\n\n";
        cout<<"\t\t7. S A L I R\n\n";
        cout<<"\t\t\t\t\tOPCION  ";
        cin>>op;
        system("cls");
        switch(op)
        {
            case 1:
                do
                {
                    system("cls"); 
                    cout<<"\n\nINGRESE EL DATO A INSERTAR: ";
                    cin>>dato; 
                    inserta_abb(raiz,dato); 
                    cout<<"\n\n\t\tMAS DATOS? (S/N) : "; 
                    cin>>opc; 
                } 
                while(opc=='s'||opc=='S'); 
                system("pause");
                break;
            case 2:
                system("cls"); 
                cout<<"\n\nINGRESE EL DATO A ELIMINAR: ";
                cin>>dato; 
                elimina_abb(raiz,dato); 
                system("pause"); 
                break; 
            case 3:
                system("cls"); 
                cout<<"\n\nINGRESE EL DATO A BUSCAR: "; 
                cin>>dato;
                buscar_abb(raiz,dato); 
                system("pause"); 
                break; 
            case 4:
                system("cls");
                cout<<"\n\nRECORRIDO PREORDEN: \n";
                cout<<"\n\t********************\n\n";
                preorden(raiz);
                system("pause");
                break;
            case 5:
                system("cls");
                cout<<"\n\nRECORRIDO INORDEN:";
                cout<<"\n\t********************\n\n";
                inorden(raiz);
                system("pause");
                break;
            case 6:
                system("cls");
                cout<<"\n\tRECORRIDO POSTORDEN: ";
                cout<<"\n\t********************\n\n";
                postorden(raiz);
                system("pause");
                break;
            case 7:
            	break;
        }
    }
    while(op < 7);
    return 1;
}
void inserta_abb(nodo *&raiz,int dato)
{
    nodo *q;
    if(raiz!=NULL)
        if(dato<raiz->inf)
            inserta_abb(raiz->izq,dato);
        else
            if(dato>raiz->inf)
                inserta_abb(raiz->der,dato);
            else
                cout<<"\n\tEL DATO YA SE ENCUENTRA EN EL ARBOL....\n ";
    else
    {
        q=new(nodo); 
        q->izq=NULL; 
        q->der=NULL; 
        q->inf=dato; 
        raiz=q; 
    }
}
void buscar_abb(nodo *raiz,int dato)
{
    if(dato<raiz->inf)
        if (raiz->izq==NULL)
            cout<<"\n\tEL DATO BUSCADO NO EXISTE.....\n\n ";
        else
            buscar_abb(raiz->izq,dato);
    else
        if(dato>raiz->inf)
            if(raiz->der==NULL)
                cout<<"\n\tEL DATO BUSCADO NO EXISTE.....\n\n ";
            else
                buscar_abb(raiz->der,dato);
        else
            cout<<"\n\tEL DATO BUSCADO SI EXISTE.....\n\n";
}
void elimina_abb(nodo *&raiz, int dato)
{
    nodo *q, *aux,*aux1; 
    int cen; 
    if(raiz!=NULL)
    {
        if(dato<raiz->inf)
            elimina_abb(raiz->izq,dato);
        else
            if(dato>raiz->inf) 
                elimina_abb(raiz->der,dato);
        else
        {
            q=raiz; 
            if(q->der==NULL) 
                raiz=q->izq;
            else
                if(q->izq==NULL)
                    raiz=q->der;
                else
                {
                    aux=q->izq;
                    cen=0;
                    while (aux->der!=NULL)
                    {
                        aux1=aux;
                        aux=aux->der;
                        cen=1;
                    };
                    raiz->inf=aux->inf;
                    q=aux;
                    if(cen==1)
                        aux1->der=aux->izq;
                    else
                        raiz->izq=aux->izq;
                }
            delete q;
        }
    }
    else
    {
    	cout<<"\n\tEL DATO A ELIMINAR NO EXISTE.....\n\n ";
	}
}
void preorden(nodo *raiz)
{
    if(raiz != NULL)
    {
        cout<<"\n\n\t - "<<raiz->inf<<"\n\n";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
void inorden(nodo *raiz)
{
    if(raiz != NULL)
    {
        inorden(raiz->izq);
        cout<<"\n\n\t - "<<raiz->inf<<"\n\n";
        inorden(raiz->der);
    }
}
void postorden(nodo *raiz)
{
    if(raiz != NULL)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout<<"\n\n\t - "<<raiz->inf<<"\n\n";
    }
}
