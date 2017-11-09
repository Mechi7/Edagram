#include <iostream>
#include "ListaTags.h"
using namespace std;
ListaPopulares lpop;//Sempre que quisermos usar uma outra classe devemos instancial aqui
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
	Tags *novoTag=new Tags;//apontador para a novo tag
	novoTag->nomeUsuario=nomeUsuario;

	if(listaVazia()){novoTag->next=NULL;}
	else{novoTag->next=inicio;}

	inicio=novoTag;//Adiciona o elemento ao fim da lista
	cout<<novoTag->nomeUsuario<<"\t Tagged"<<endl;
	totalTags++;
	adpInserirPopular(nomeUsuario);

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

void ListaTags::adpInserirPopular(string nomeUsuario){
	if(totalTags>=5)
		lpop.inserirPopular("DonoDaConta",totalTags);	//Temos q capturar o nome do dono da conta
}

int ListaTags::quantidadeDeTags()
{
	return totalTags;
}

