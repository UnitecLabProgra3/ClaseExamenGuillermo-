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
    if(inicio == NULL)
        return;
    Nodo*temp = inicio;
    cout<<temp->nombre<<"\t"<<temp->score<<endl;
    while(temp->siguiente != NULL)
    {
        cout<<temp->siguiente->nombre<<"\t"<<temp->siguiente->score<<endl;
        temp = temp->siguiente;
    }
}

void Lista::leerLista()
{
    ifstream in("scores.txt");

    while(!in.eof())
    {
        string nombre;
        int puntaje;
        in>>nombre;
        in>>puntaje;
        if(nombre != "" && puntaje != NULL)
            agregarNodo(new Nodo(nombre, puntaje));
        nombre = "";
        puntaje = NULL;
    }
}

void Lista::escribirLista()
{
    ofstream out("scores.txt");
    out.app;
    if(inicio == NULL)
        return;
    Nodo*temp = inicio;
    out<<temp->nombre<<" "<<temp->score<<endl;
    while(temp->siguiente != NULL)
    {
        out<<temp->siguiente->nombre<<" "<<temp->siguiente->score<<endl;
        temp = temp->siguiente;
    }
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
