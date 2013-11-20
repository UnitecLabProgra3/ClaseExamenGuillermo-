#include "Lista.h"

Lista::Lista()
{
    inicio=NULL;
}

void Lista::agregarNodo(Nodo*nodo)
{
    if(inicio==NULL)
    {
        inicio=nodo;
    }else
    {
        Nodo*temp=inicio;
        while(temp->siguiente!=NULL)
        {
            temp=temp->siguiente;
        }
        temp->siguiente=nodo;
    }
}

void Lista::agregarNodo(Nodo*nodo,int pos)
{
    if(nodo->nombre=="")
        return;
    if(inicio==NULL || pos==0)
    {
        nodo->siguiente=inicio;
        inicio=nodo;
    }else
    {
        Nodo*temp=inicio;
        int i=0;
        while(temp->siguiente!=NULL
              && i<pos-1)
        {
            temp=temp->siguiente;
            i++;
        }

        nodo->siguiente=temp->siguiente;
        temp->siguiente=nodo;
    }
}

void Lista::imprimirLista()
{
    //ToDo
}

void Lista::leerLista()
{
    //ToDo
}

void Lista::escribirLista()
{
    //ToDo
}

Lista::~Lista()
{
    for(Nodo*temp=inicio;
        temp!=NULL;
        )
    {
        Nodo*temp2=temp;
        temp=temp->siguiente;
        delete temp2;
    }
    return;
}
