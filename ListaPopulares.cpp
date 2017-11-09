#include <iostream>
#include "ListaPopulares.h"

using namespace std;
ListaPopulares::ListaPopulares()
{
	inicio=NULL;
	totalPopulares=0;
}
bool ListaPopulares::listaVazia()
{
	if(inicio==NULL)
		return true;
	return false;
}
bool ListaPopulares::existePopular(string nomeUsuario)
{
	Populares *percorre=inicio;
	bool find=false;
	if(listaVazia()){cout<<"Nao existem Populares"<<endl;}
	else
	{
		while(percorre!=NULL &&find==false)
		{
			if(percorre->nomeUsuario==nomeUsuario)
				find=true;
			percorre=percorre->next;
		}
	}
	return find;
}

void ListaPopulares::inserirPopular(string nomeUsuario,int totalTags)
{
	Populares *novoPopular=new Populares;//apontador para a novo tag
	novoPopular->nomeUsuario=nomeUsuario;
	novoPopular->totalTags=totalTags;
	if(listaVazia()){novoPopular->next=NULL;}
	else{novoPopular->next=inicio;}

	inicio=novoPopular;//Adiciona o elemento ao fim da lista
	cout<<"Popular:\t"<<novoPopular->nomeUsuario<<endl;
	totalPopulares++;

}
void ListaPopulares::listarPopulares()
{
	Populares *percorre=inicio;
	if(listaVazia()){cout<<"Ainda nao tem Populares"<<endl;}
	else
	{
		while(percorre!=NULL)
		{
			cout<<"Usuario:\t"<<percorre->nomeUsuario<<"Populares: \t"<<percorre->totalTags<<endl;
			percorre=percorre->next;
		}
	}
}

