#include<iostream>
#include<cstring>
using namespace std; 
struct nodo 
{ 
    char nomb[20]; 
    nodo *sig;
};
nodo *crea_i(nodo *);
nodo *crea_f(nodo *);
nodo *inserta_i(nodo *);
nodo *inserta_f(nodo *);
nodo *inserta_ad(nodo *,char *);
nodo *inserta_dd(nodo *,char *);
nodo *eliminar_p(nodo *);
nodo *eliminar_u(nodo *);
nodo *eliminar_x(nodo *,char *);
nodo *eliminar_ad(nodo*, char *);
nodo *eliminar_dd(nodo*, char *);
void recorre(nodo *);
int main()
{
    char codigo[10];
    nodo *p=NULL;
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
                p=NULL;
                p=crea_i(p);
                break;
            case 2:
                system("cls");
                p=NULL; 
                p=crea_f(p); 
                break; 
            case 3:
                system("cls"); 
                p=inserta_i(p); 
                break; 
            case 4:
                system("cls"); 
                p=inserta_f(p); 
                break;
            case 5:
                system("cls");
                p=inserta_ad(p,codigo);
                break;
            case 6:
                system("cls");
                cout << "\n\nNOMBRE DEL REFERIDO A ELIMINAR: ";
                cin >> codigo;
                p=inserta_dd(p,codigo);
                break;
            case 7:
                system("cls");
                p=eliminar_p(p);
                break;
            case 8:
                system("cls");
                p=eliminar_u(p);
                break;
            case 9:
                system("cls");
                cout << "\n\nNOMBRE DEL NODO A ELIMINAR: ";
                cin >> codigo;
                p = eliminar_x(p, codigo);
                break;
            case 10:
                system("cls");
                cout << "\n\nNOMBRE DEL NODO A ELIMINAR: ";
                cin >> codigo;
                p = eliminar_ad(p, codigo);
                break;
            case 11:
                system("cls");
                cout << "\n\nNOMBRE DEL NODO A ELIMINAR: ";
                cin >> codigo;
                p = eliminar_dd(p, codigo);
                break;
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
nodo *crea_i(nodo *p) 
{
    nodo *q;
    char op;
    do
    { 
        system("cls");
        q=new(nodo);
        cout<<"\n\nNOMBRE :  ";
        cin>>q->nomb;
        q->sig=p;
        p=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)?  ";
        cin>>op;
    }
    while(op=='s'||op=='S'); 
    return(p); 
}
nodo *crea_f(nodo *p) 
{ 
    nodo *q,*r; 
    char op; 
    do
    {
        system("cls"); 
        q=new(nodo); 
        cout<<"\n\nNOMBRE : ";
        cin>>q->nomb;
        q->sig=NULL; 
        if(p==NULL) 
            p=q; 
        else
        {
            r->sig=q;
        }
        r=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)? "; 
        cin>>op;
    } 
    while(op=='s'||op=='S'); 
    return(p);
}
nodo *inserta_i(nodo *p) 
{
    nodo *q; 
    system("cls"); 
    cout<<"\n\nINSERTANDO DATO POR EL INICIO ... "; 
    q=new(nodo);
    cout<<"\n\nNOMBRE : ";
    cin>>q->nomb; 
    q->sig=p; 
    p=q; 
    return(p); 
}
nodo *inserta_f(nodo *p) 
{ 
    nodo *q,*r; 
    system("cls"); 
    cout<<"\n\nINSERTANDO DATO POR EL FINAL ... "; 
    q=new(nodo); 
    cout<<"\n\nNOMBRE : "; 
    cin>>q->nomb; 
    q->sig=NULL;
    r=p;
    if(p==NULL) 
        p=q; 
    else
    { 
        while(r->sig!=NULL) 
            r=r->sig;
        r->sig=q;
    } 
    return(p);
}
nodo *inserta_ad(nodo *p,char *codigo)
{
    nodo *q,*r,*t;
    int cen=0;
    cout<<"\n\nNOMBRE DEL REFERIDO A INSERTAR: ";
    cin>>codigo;
    system("cls");
    if (p!=NULL)
    {
        r=p;
        while (strcmp(r->nomb,codigo)!=0&&(cen==0))
        {
            if (r->sig!=NULL)
            {
                t=r;
                r=r->sig;
            }
            else
            {
                cen=1;
            }
        }
        if (cen==0)
        {
            q=new(nodo);
            cout<<"\n\nNOMBRE DEL NODO A INSERTAR:  ";
            cin>>q->nomb;
            q->sig=r;
            if (p==q)
            {
                p=q;
            }
            else
            {
                t->sig=q;
            }
        }
        else
        {
            cout<<"\n\n\t\t\tEL DATO REFERIDO NO EXISTE...\n";
            system("pause");
        }
    }
    else
    {
        cout<<"\n\n\t\t\tLA LISTA ESTA VACIA...\n"<<endl;
        system("pause");
    }
    return(p);
}
nodo *inserta_dd(nodo *p,char *codigo)
{
    nodo *q,*r;
    int cen=0;
    system("cls");
    if (p!=NULL)
    {
        r=p;
        while (strcmp(r->nomb,codigo)!=0&&(cen==0))
        {
            if (r->sig!=NULL)
            {
                r=r->sig;
            }
            else
            {
                cen=1;
            }
        }
        if (cen==0)
        {
            q=new(nodo);
            cout<<"\n\nNOMBRE DEL NODO A INSERTAR:  ";
            cin>>q->nomb;
            q->sig=r->sig;
            r->sig=q;
        }
        else
        {
            cout<<"\n\n\t\t\tEL DATO REFERIDO NO EXISTE...\n";
            system("pause");
        }
        
    }
    else
    {
        cout<<"LA LISTA ESTA VACIA...\n";
        system("pause");
    }
    return(p);
}
nodo *eliminar_p(nodo *p)
{
    nodo *q;
    system("cls");
    if (p != NULL)
    {
        q = p;
        p = p->sig;
        q->sig = NULL;
        delete q;
    }
    else
    {
        cout << "\n\n\t\t\tLA LISTA ESTA VACIA...";
        system("pause");
    }
    return(p);
}
nodo *eliminar_u(nodo *p)
{
    nodo *q,*r;
    system("cls");
    if (p != NULL)
    {
        q = p;
        if (p->sig==NULL)
        {
            p=NULL;
        }
        else
        {
            while (q->sig!=NULL)
            {
                r=q;
                q=q->sig;
            }
            r->sig=NULL;
        }
        delete q;
    }
    else
    {
        cout << "\n\n\t\t\tLA LISTA ESTA VACIA...";
        system("pause");
    }
    return(p);
}
nodo *eliminar_x(nodo *p, char *codigo) 
{
    nodo *q, *r = NULL;
    int cen = 0;
    if (p != NULL) {
        q = p;
        while (strcmp(q->nomb, codigo) != 0 && (cen == 0)) 
        {
            if (q->sig != NULL) 
            {
                r = q;
                q = q->sig;
            } 
            else 
            {
                cen = 1;
            }
        }
        if (cen == 0) 
        {
            if (p == q) 
            {
                p = p->sig;
            } 
            else 
            {
                r->sig = q->sig;
            }
            delete q;
        } 
        else 
        {
            cout << "\n\n\t\t\tEL NODO NO EXISTE...\n";
            system("pause");
        }
    } 
    else 
    {
        cout << "\n\n\t\t\tEL ARREGLO ESTA VACIO...\n";
        system("pause");
    }
    return (p);
}
nodo *eliminar_ad(nodo *p, char *codigo) {
    nodo *q, *t, *r;
    int cen = 0;
    system("cls");

    if (p != NULL) {
        if (strcmp(p->nomb, codigo) == 0) 
        {
            cout << "\n\n\t\t\tNO HAY NODO ANTERIOR AL REFERIDO...\n";
            system("pause");
        } 
        else 
        {
            q = p;
            t = p;
            while (strcmp(q->nomb, codigo) != 0 && cen == 0) 
            {
                if (q->sig != NULL) 
                {
                    r = t;
                    t = q;
                    q = q->sig;
                } 
                else 
                {
                    cen = 1;
                }
            }
            if (cen == 0)
            {
                if (p->sig == q)
                {
                    p = q;
                } 
                else
                {
                    r->sig = q;
                }
                delete t;
            }
            else 
            {
                cout << "\n\n\t\t\tEL NODO REFERIDO NO EXISTE...\n";
                system("pause");
            }
        }
    }
    else
    {
        cout << "\n\n\t\t\tLA LISTA ESTA VACIA...\n";
        system("pause");
    }

    return p;
}
nodo *eliminar_dd(nodo *p, char *codigo) 
{
    nodo *q, *r;
    int cen = 0;
    system("cls");
    if (p != NULL)
    {
        q = p;
        while (strcmp(q->nomb, codigo) != 0 && cen == 0)
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
            if (q->sig == NULL)
            {
                cout << "\n\n\t\t\tNO HAY NODO POSTERIOR AL REFERIDO...\n";
                system("pause");
            }
            else
            {
                r = q->sig;
                q->sig = r->sig;
                delete r;
            }
        }
        else
        {
            cout << "\n\n\t\t\tEL NODO REFERIDO NO EXISTE...\n";
            system("pause");
        }
    }
    else
    {
        cout << "\n\n\t\t\tLA LISTA ESTA VACIA...\n";
        system("pause");
    }
    return (p);
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