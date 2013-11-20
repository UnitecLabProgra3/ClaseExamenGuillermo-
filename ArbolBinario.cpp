#include "ArbolBinario.h"

ArbolBinario::ArbolBinario()
{
    NodoArbol* n1 = new NodoArbol(5);
    NodoArbol* n2 = new NodoArbol(-3);
    NodoArbol* n3 = new NodoArbol(6);
    NodoArbol* n4 = new NodoArbol(9);
    NodoArbol* n5 = new NodoArbol(1);

    n1->hijo_izq=n2;
    n1->hijo_der=n3;

    n2->hijo_izq=n4;
    n2->hijo_der=n5;

    padre=n1;
}

void ArbolBinario::imprimir(NodoArbol* padre)
{
    if(padre==NULL)
        return;

    std::cout<<padre->numero<<std::endl;

    imprimir(padre->hijo_der);
    imprimir(padre->hijo_izq);
}

bool ArbolBinario::exists(NodoArbol*padre,int numero)
{
    bool verdad=false;
    if (padre==NULL)
        return verdad;

        if (padre->numero==numero){
           verdad=true;
            return verdad;
        }



        exists(padre->hijo_der,numero);
        exists(padre->hijo_izq,numero);


    //ToDo
    return verdad;
}

int ArbolBinario::getSize(NodoArbol*padre)
{
int acumulador=0;
if(padre==NULL)
    return acumulador;

    acumulador=getSize(padre->hijo_der)+1;
    acumulador=getSize(padre->hijo_izq)+1;

    return acumulador;

}

ArbolBinario::~ArbolBinario()
{
    //dtor
}
