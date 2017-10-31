#include <iostream>
#include "ListaPosts.h"

using namespace std;

ListaPosts::ListaPosts()
{
	inicio=NULL;
	totalPosts=0;
}
bool ListaPosts::listaVazia()
{
	if(inicio==NULL)
		return true;
	return false;
}


void ListaPosts::inserirPost(string nomeUsuario,string post,Tags *tags)
{
	Posts *percorre=inicio;//apontador que percorre a lista apartir do inicio 
	Posts *novoPost=new Posts;//apontador para a nova conta
	novoPost->nomeUsuario=nomeUsuario;
	novoPost->post=post;
	novoPost->tags=tags;
	novoPost->next=NULL;
	
	if(listaVazia())
	{
		inicio=novoPost;
		cout<<"novo Post: "<<novoPost->nomeUsuario<<" Adicionada com sucesso"<<endl;
		totalPosts++;
	}
	else
	{

			while(percorre->next!=NULL){percorre=percorre->next;}//Assignment responsavel por percorrer a lista
			percorre->next=novoPost;//Adiciona o elemento ao fim da lista
			cout<<"Posted"<<endl;
			totalPosts++;			
	}
}

void ListaPosts::listarPosts()
{
	Posts *percorre=inicio;
	if(listaVazia()){cout<<"Ainda nao tem Posts"<<endl;}
	else
	{
		while(percorre!=NULL)
		{
			cout<<"Post:\t"<<percorre->nomeUsuario<<endl;
			percorre=percorre->next;
		}
	}
}


int ListaPosts::quantidadeDePosts()
{
	return totalPosts;
}

