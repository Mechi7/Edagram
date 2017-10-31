#include <iostream>
#include "ListaTags.h"
#include "ListaContas.h"


using namespace std;

ListaTags::ListaTags()
{
	inicio=NULL;
	totalTags=0;
}
bool ListaTags::listaVazia()
{
	if(inicio==NULL)
		return true;
	return false;
}

void ListaTags::inserirTag(string nomeUsuario)
{
	Tags *percorre=inicio;//apontador que percorre a lista apartir do inicio 
	Tags *novoTag=new Tags;//apontador para a novo tag
	novoTag->nomeUsuario;
	novoTag->next=NULL;
	
	
//	if(!existeConta(nomeUsuario))//Verifica se o username a fazer existe
//	{teremos que acessar o metodo existe conta da classe ListaContas

			while(percorre->next!=NULL){percorre=percorre->next;}//Assignment responsavel por percorrer a lista
			percorre->next=novoTag;//Adiciona o elemento ao fim da lista
			cout<<novoTag->nomeUsuario<<"\t Tagged"<<endl;
			totalTags++;			
//	}
//	else
//		cout<<"Esta usuario nao existe"<<endl;
}
void ListaTags::listarTags()
{
	Tags *percorre=inicio;
	if(listaVazia()){cout<<"Ainda nao tem Tags"<<endl;}
	else
	{
		while(percorre!=NULL)
		{
			cout<<"Tagged por:\t"<<percorre->nomeUsuario<<endl;
			percorre=percorre->next;
		}
	}
}

int ListaTags::quantidadeDeTags()
{
	return totalTags;
}

bool ListaTags::popular()
{
	if (quantidadeDeTags()>=5)
		return true;
	return false;
}
