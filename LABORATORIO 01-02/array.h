#include <iostream>
using namespace std;

void insertar_d(int *x, int &n, int max, int dato){
    if(n<max-1){
        n++;
        x[n]=dato;
    }
    else{
        cout<<"\n\n\t\tARREGLO LLENO. NO SE PUDO INSERTAR EL DATO.\n\n";
        system("pause");
    }
}
void elimina_d(int *x,int &n,int dato){
    int i,j,cen;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=n && cen==0){
            if(x[i]==dato){
                cen=1;
                n--;
                for(j=i;j<=n;j++){
                    x[j]=x[j+1];
                }
            }
            else{
                i++;
            }
        }
        if(cen==0){
            cout<<"\n\n\t\t"<<dato<<"NO ESTA EN EL ARREGLO.\n";
        }
    }
    else{
        cout<<"\nEL ARREGLO ESTA VACIO.\n";
        system("pause");
    }
}
void modifica_d(int *x,int &n,int dato){
    int i,j,cen,ndato;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=n && cen==0){
            if(x[i]==dato){
                cen=1;
                cout<<dato<<" ha sido encontrado.";
                cout<<"\n\tINGRESE EL NUEVO DATO: ";cin>>ndato;
                x[i]==ndato;
            }
            else{
                i++;
            }
        }
        if(cen==0){
            cout<<"\n\n\t\t"<<dato<<"NO ESTA EN EL ARREGLO.\n";
        }
    }
    else{
        cout<<"\nEL ARREGLO ESTA VACIO.\n";
        system("pause");
    }
}
void mostrar(int *x, int n){
    for(int i=0;i<=n;i++){
        cout<<"\nx["<<i<<"] = " << x[i];
    }
    cout<<"\n\n";
}
void insertar_o(int *x, int &n, int max, int dato)
{
	
}
void elimina_o(int *x, int &n, int dato)
{
	
}
void modifica_o(int *x, int n, int dato)
{
	
}
int busca(int *x, int n, int dato)
{
	int i, pos;
	i=0;
	while((i<=n) && (x[i]<dato))
	{
		i++;
	}
	if((i>n) && (x[i]>dato))
	{
		pos=-i;
	}
	else
	{
		pos=i;
	}
	return pos;
}