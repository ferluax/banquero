#include <iostream>
//#include <stdbool.h>

using namespace std;

int main()
{
    int en_Uso[5][5]; //recursos que procesos tienen en uso 
    int max_Recursos[5][5]; //demanda maxima de recursos 
    int r_disponibles[5]; //recursos iniciales - recursos asignados
    int r_asignados[5] = {0, 0, 0, 0, 0}; //recursos que se le asigna a el proceso que esta en uso
    int r_iniciales[5]; //recursos que los procesos pueden usar
    int banquero[5];//seran los recursos que se estaran "prestando" para estar completando los procesos

    int nProceso, nRecurso, i, j, k;
    int contador = 0; //el contador es para saber cuantos procesos va a ingresar
    bool estado_seguro = false;

    //pedimos que se ingresen los datos necesarios

    cout<< "Ingresa el numero de recursos: ";
    cin>>nRecurso;

    cout<< "\nIngresa el numero de procesos: ";
    cin>>nProceso;
    for (i = 0; i < nProceso; i++)
    {
        banquero[i] = 1;
        contador ++;
    }
    
    cout<< "\nIngresa el vector de recursos iniciales: ";
    for(i= 0; i< nRecurso; i++)
        cin>>r_iniciales[i];
    
    cout<< "\nIngresa la demanda maxima de recursos: ";
    for (i = 0; i < nProceso; i++)
    {
        for(j= 0; j< nRecurso; j++)
            cin>>max_Recursos[i][j];
    }
    
    cout<< "\nIngresa los recursos que procesos tienen en uso: ";
    for (i = 0; i < nProceso; i++)
    {
        for(j= 0; j< nRecurso; j++)
            cin>>en_Uso[i][j];
    }

    //Se mostraran los datos proporcionados, ya se podra ver como es que quedaron las matrices y los recursos con los que se dispone

    cout<< "\n\n------------------Datos Ingresados------------------\n";

    cout<< "\nRecursos Iniciales: ";
    for(i= 0; i< nRecurso; i++)
        cout<<r_iniciales[i]<<" ";
    
    cout<< "\nMatriz de Demanda Maxima de Recursos"<<endl;
    for (i = 0; i < nProceso; i++)
    {
        for(j= 0; j< nRecurso; j++)
            cout<<"\t"<<max_Recursos[i][j];
            cout<<endl;
    }
    
    cout<< "\nMatriz de Recursos que Procesos Tienen en Uso"<<endl;
    for (i = 0; i < nProceso; i++)
    {
        for(j= 0; j< nRecurso; j++)
            cout<<"\t"<<en_Uso[i][j];
            cout<<endl;
    }

    for(i= 0; i< nProceso; i++)
        for(j= 0; j< nRecurso; j++)
            r_asignados[j] += en_Uso[i][j]; //esto es para sumar los recursos que se esta utilizando la matriz de recursos en uso
    cout<< "\nRecursos que se estan utilizando: ";
    for(i= 0; i< nRecurso; i++)
        cout<<r_asignados[i]<<" ";

    
    for(i= 0; i< nRecurso; i++)
        r_disponibles[i] = r_iniciales[i] - r_asignados[i]; //aqui realizamos la resta de los recursos iniciales con los de en uso para conocer con cuantos recursos contamos
    cout<< "\nRecursos Disponibles: ";
    for(i= 0; i< nRecurso; i++)
        cout<<r_disponibles[i]<<" ";
    cout<<endl;

    cout<< "\n\n------------------Resultado------------------\n";

    //aqui comenzamos a realizar los presatamos de los recursos a los procesos
    while (contador != 0)
    {
        estado_seguro = false;
        for (i = 0; i < nProceso; i++)
        {
            if (banquero[i])
            {
                k = 1;
                for (j = 0; j < nRecurso; j++)
                {
                    if (max_Recursos[i][j] - en_Uso[i][j] > r_disponibles[j])
                    {
                        k = 0;
                        break;
                    }
                    
                }

                if (k)
                {
                    cout<< "\nProceso no."<<i + 1<<" se esta ejecutando";
                    banquero[i] = 0;
                    contador--;
                    estado_seguro = true;
                    for(j= 0; j< nRecurso; j++)
                        r_disponibles[j] += en_Uso[i][j];
                    break;
                }
                
                
            }
            
        }
        if (!estado_seguro)
        {
            cout<< "\nEl proceso no esta en estado seguro...";
            break;
        }

        if (estado_seguro)
            cout<< "\nEl proceso esta en estado seguro...\n";

        cout<< "\nRecursos Disponibles: ";
        for(i= 0; i< nRecurso; i++)
            cout<<r_disponibles[i]<<" ";
        cout<<endl;
        
        
    }

    return 0;
    
}