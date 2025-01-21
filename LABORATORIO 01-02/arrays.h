#include <iostream>
using namespace std;

void inserta_d(int *x,int &n,int max,int dato){
    if(n<max-1){
        n++;
        x[n]=dato;
    }else{
        cout<<"\n\n\t\t\tARREGLO LLENO, NO SE PUEDE INSERTAR...\n\n\n";
        system("pause");
    }
}

void elimina_d(int *x, int &n, int dato){
    int i,j,cen;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=0 && cen==0){
            if(x[i]==dato){
                cen=1;
                n--;
                for(j=i;j<=n;j++)
                    x[j]=x[j+1];
            }else
                i++;
        }
        if(cen==0){
            cout<<"\n\n\t\t"<<dato<<" NO ESTA EN EL ARREGLO\n\n";
            system("pause");

        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO... \n\n\n";
        system("pause");
    }
}

void modifica_d(int *x, int n, int dato){
    int i,cen;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=n && cen==0){
            if(x[i]==dato){
                cen = 1;
                cout<<"\n\n\t DATO QUE MODIFICA : ";
                cin>>x[i];
            }else{
                i++;
            }
        }
        if(cen == 0){
            cout<<"\n\n\n\t\t"<<dato<<" NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO... \n\n\n";
        system("pause");
    }
}

void mostrar(int *x, int n){
    int i;
    if(n>-1){
        for(i=0;i<=n;i++){
            cout<<"\nx["<<i<<"] = "<<x[i];
        }
        cout<<"\n\n";

    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO... \n\n\n";
        system("pause");
    }
    
}

int buscar(int *x, int n, int dato){
    int i=0,pos;
    while(i<=n && x[i]<dato){
        i++;
    }
    if(i>n || x[i]>dato)
        pos = -i;
    else{
        pos = i;
    }
    cout<<endl<<pos<<endl;
    return pos;
} 

void inserta_o(int *x, int &n,int max, int dato){
    system("cls");
    int pos;
    if(n<max){
        pos=buscar(x,n,dato);
        if(pos<=0){
            n++;
            pos=-pos;
            for(int i=n;i>=pos;i--){
                x[i]=x[i-1];
            }
            x[pos]=dato;
        }else{
            cout<<"\n\tEL dato ya se encuentra en el arreglo...";
        }
    }else{
        cout<<"\n\tEl arrelgo ya se encuentra lleno";
    }
}

void elimina_o(int *x, int &n, int dato){
    if(n>0){
        int pos=buscar(x,n,dato);
        if((pos<0)||(pos==0 && dato < x[pos]))
		{
            cout<<"\nEl elemento a eliminar no existe..."<<endl<<endl;
        }
		else{
            n--;
            for(int i=pos;i<=n;i++){
                x[i]=x[i+1];
            }
        }
    }
	else{
        cout<<"\nEl arreglo esta vacio...";
        system("pause");
    }
}

void modifica_o(int *x,int &n,int dato,int max,int dato2){
    bool NoCaseFirst;
    if(n>0){
        int pos=buscar(x,n,dato);
        if(pos<=0){
            if(pos==0 && dato < x[pos]){
                cout<<"\nEl elemento a eliminar no existe..."<<endl<<endl;
            }else{
                NoCaseFirst=true;
            }
        }else{
            elimina_o(x,n,dato);
            inserta_o(x,n,max,dato2);
        }
    }else{
        cout<<"\nEl arreglo esta vacio...";
        system("pause");
    }
}