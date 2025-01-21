#include<iostream>
#include<string.h>
using namespace std;
struct nodo
{ 
    char nomb[20];
    nodo *ant,*sig;
};
void cread_i(nodo *&,nodo *&);
void cread_f(nodo *&,nodo *&);
void recorre(nodo *);
void insertad_i(nodo *&,nodo *&);
void insertad_f(nodo *&,nodo *&);
void insertad_ad(nodo *&,char *);
void insertad_dd(nodo *&,char *);
void eliminard_p(nodo *&,nodo *&);
void eliminard_u(nodo *&,nodo *&);
void eliminard_x(nodo *&,nodo *&,char *);
void eliminard_ad(nodo *&,char *);
void eliminard_dd(nodo *&,char *);
int main()
{
    char codigo[10];
    nodo *p=NULL,*f=NULL;
    int op;
    do
    {
        system("cls");
        cout<<"\nLISTAS ENLAZADAS" ;
        cout<<"\n===================";
        cout<<"\n\nl. CREAR POR EL INICIO";
        cout<<"\n\n2. CREAR POR EL FINAL";
        cout<<"\n\n3. INSERTAR AL INICIO";
        cout<<"\n\n4. INSERTAR AL FINAL";
        cout<<"\n\n5. INSERTAR ANTES DE";
        cout<<"\n\n6. INSERTAR DESPUES DE";
        cout<<"\n\n7. ELIMINA EL PRIMER NODO";
        cout<<"\n\n8. ELIMINAR EL ULTIMO NODO";
        cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO";
        cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A ";
        cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A ";
        cout<<"\n\n12. M O S T R A R ";
        cout<<"\n\n13. S A L I R ";
        cout<<"\n\n\t\t\t OPCION:  ";
        cin>>op;
        switch(op)
        {
            case 1:
                system("cls");
                cread_i(p,f);
                break;
            case 2:
                system("cls");
                cread_f(p,f); 
                break; 
            case 3:
                system("cls"); 
                insertad_i(p,f); 
                break; 
            case 4:
                system("cls"); 
                insertad_f(p,f); 
                break;
            case 5:
                system("cls");
                cout<<"\n\nINGRESE EL REFERENCIAL:   ";
                cin>>codigo;
                insertad_ad(p,codigo);
                break;
            case 6:
                system("cls");
                cout<<"\n\nINGRESE EL REFERENCIAL:   ";
                cin>>codigo;
                insertad_dd(f,codigo);
                break;
            case 7:
                system("cls"); 
                eliminard_p(p,f); 
                break;
            case 8:
                system("cls"); 
                eliminard_u(p,f); 
                break;
            case 9:
                system("cls");
                cout<<"\n\nINGRESE EL REFERENCIAL:   ";
                cin>>codigo;
                eliminard_x(p,f,codigo);
                break;
            /*case 10:
                system("cls");
                cout<<"\n\nINGRESE EL REFERENCIAL:   ";
                cin>>codigo;
                eliminard_ad(p,codigo);
                break;
            case 11:
                system("cls");
                cout<<"\n\nINGRESE EL REFERENCIAL:   ";
                cin>>codigo;
                eliminard_dd(f,codigo);
                break;*/
            case 12:
                system("cls"); 
                recorre(p); 
                system("pause"); 
                break; 
            case 13: 
                break; 
        } 
    }
    while(op>0&&op<13);
    return 0;
}

void cread_i(nodo *&p,nodo *&f) 
{
    nodo *q;
    char op;
    p=NULL;
    q=NULL;
    do
    { 
        system("cls");
        cout<<"\n\nCREANDO LISTA POR EL INICIO...";
        q=new(nodo);
        cout<<"\n\nNOMBRE :  ";
        cin>>q->nomb;
        q->ant=NULL;
        q->sig=p;
        if(p==NULL)
            f=q;
        else
            p->ant=q;
        p=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)?  ";
        cin>>op;
    }
    while(op=='s'||op=='S');
}
void cread_f(nodo *&p,nodo *&f)
{ 
    nodo *q,*r;
    char op;
    p=NULL;
    f=NULL;
    do
    {
        system("cls");
        cout<<"\n\nCREANDO LISTA POR EL FINAL...";
        q=new(nodo); 
        cout<<"\n\nNOMBRE : ";
        cin>>q->nomb;
        q->sig=NULL;
        q->ant=f;
        if(p==NULL) 
            p=q; 
        else
            f->sig=q;
        f=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)? "; 
        cin>>op;
    } 
    while(op=='s'||op=='S');
}
void insertad_i(nodo *&p,nodo *&f) 
{
    nodo *q; 
    system("cls");
    cout<<"\n\nINSERTANDO DATO POR EL INICIO ... ";
    q=new(nodo);
    cout<<"\n\nNOMBRE : ";
    cin>>q->nomb;
    q->sig=p;
    q->ant=NULL;
    if(p==NULL)
        f=q;
    else
        p->ant=q;    
    p=q;
}
void insertad_f(nodo *&p,nodo *&f) 
{ 
    nodo *q,*r;
    system("cls");
    cout<<"\n\nINSERTANDO DATO POR EL FINAL ... ";
    q=new(nodo);
    cout<<"\n\nNOMBRE : "; 
    cin>>q->nomb;
    q->ant=f;
    q->sig=NULL;
    if(p==NULL) 
        p=q; 
    else
        f->sig=q;
    f=q;
}
void insertad_ad (nodo *&p, char *codigo)
{
    nodo *r,*x,*q;
    int cen;
    if(p!=NULL){
        q=p;
        cen=0;
        while((strcmp(q->nomb,codigo)!=0) && (cen==0))
        {
            if(q->sig != NULL){
                q=q->sig;
            }
            else
            {
                cen=1;
            }
        }
        if(cen==0)
        {
            x=new(nodo);
            cout<<"\n\n\tINGRESE EL NOMBRE : ";
            cin>>x->nomb;
            x->sig=q;
			r=q->ant;
            x->ant=r;
			q->ant=x;
            if(p==q)
            {
                p=x;
            }
            else
            {
                r->sig=x;
            }
        }
		else
		{
            cout<<"\n\n\t\tEL DATO NO EXISTE ... \n";
            system("pause");
        }
    }
	else
	{
        cout<<"\n\n\t\tLA LISTA ESTA VACIA ... \n";
        system("pause");
    }
} 
void insertad_dd(nodo *&f, char *codigo)
{
    nodo *r, *x, *q;
    int cen = 0;

    if (f != NULL)
    {
        q = f;
        while ((strcmp(q->nomb, codigo) != 0) && (cen == 0))
        {
            if (q->ant != NULL)
            {
                q = q->ant;
            }
            else
            {
                cen = 1;
            }
        }

        if (cen == 0)
        {
            x = new nodo;
            cout << "\n\n\tINGRESE EL NOMBRE: ";
            cin >> x->nomb;

            x->ant = q;
            x->sig = q->sig;

            if (q->sig != NULL)
            {
                q->sig->ant = x;
            }

            q->sig = x;

            // Si el nodo referencial es el último nodo, actualizamos el puntero final
            if (q == f)
            {
                f = x;
            }
        }
        else
        {
            cout << "\n\n\t\tEL DATO NO EXISTE ... \n";
            system("pause");
        }
    }
    else
    {
        cout << "\n\n\t\tLA LISTA ESTA VACIA ... \n";
        system("pause");
    }
}
void eliminard_p(nodo *&p,nodo *&f)
{
    nodo *q;
    system("cls");
    if (p != NULL)
    {
        q = p;
        p = p -> sig;
        if (q == f)
            f = NULL;
        else
            p -> ant = NULL;
        delete q;
    }
    else
    {
        cout << "\n\n\t\t\tLA LISTA ESTA VACIA...";
        system("pause");
    }
}
void eliminard_u(nodo *&p, nodo *&f)
{
    nodo *q;
    system("cls");
    if (p != NULL)
    {
        q = f;
        if (p == f) // Solo hay un nodo en la lista
        {
            p = NULL;
            f = NULL;
        }
        else // Hay más de un nodo en la lista
        {
            f = f->ant;
            f->sig = NULL;
        }
        delete q;
    }
    else
    {
        cout << "\n\n\t\t\tLA LISTA ESTA VACIA...";
        system("pause");
    }
}
void eliminard_x(nodo *&p, nodo *&f, char *codigo)
{
    nodo *q;
    int cen = 0;

    if (p != NULL)
    {
        q = p; // Iniciamos la búsqueda desde el primer nodo
        while ((strcmp(q->nomb, codigo) != 0) && (cen == 0))
        {
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = 1;
            }
        }

        if (cen == 0)
        {
            if (p == f) // Solo un nodo en la lista
            {
                p = NULL;
                f = NULL;
            }
            else if (p == q) // Nodo a eliminar es el primero
            {
                p = p->sig;
                p->ant = NULL;
            }
            else if (q == f) // Nodo a eliminar es el último
            {
                f = f->ant;
                f->sig = NULL;
            }
            else // Nodo a eliminar es un nodo intermedio
            {
                q->ant->sig = q->sig;
                q->sig->ant = q->ant;
            }
            delete q;
        }
        else
        {
            cout << "\n\n\t\tEL DATO NO EXISTE ... \n";
            system("pause");
        }
    }
    else
    {
        cout << "\n\n\t\tLA LISTA ESTA VACIA ... \n";
        system("pause");
    }
}
void eliminard_ad(nodo *&p,char *codigo)
{

}
void recorre(nodo *p) 
{ 
    nodo *q; 
    system("cls");
    q=p;
    cout<<"\n\n\tLISTA DE DATOS: \n"; 
    cout<<"\t==============";
    while(q!=NULL) 
    { 
        cout<<"\n\n\t\t"<<q->nomb; 
        q=q->sig;
    } 
    cout<<"\n\n\t\t\t";
}

