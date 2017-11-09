#include <iostream>
#include "ListaPosts.h"

using namespace std;
ListaTags lt;
Validacoes v;
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


void ListaPosts::inserirPost(string nomeUsuario,string post)
{
	Posts *novoPost=new Posts;//apontador para a nova conta
	novoPost->nomeUsuario=nomeUsuario;
	novoPost->post=post;
	adpInserirTag();
	if(listaVazia())
	{
		novoPost->next=NULL;
		totalPosts++;
	}
	else
	{
		novoPost->next=inicio;
	}
	inicio=novoPost;
	cout<<"Posted"<<endl;
	totalPosts++;
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

void ListaPosts::adpInserirTag()
{
	string resposta=v.validarString2("s","S","n","N","Quer inserir Tags s/n?");
	string resposta2;
	if(resposta!="n"||resposta!="N")
	{
		do
		{
			lt.inserirTag(v.validarString(1,20,"Introduza o nome de Usuario"));
			resposta2=v.validarString2("s","S","n","N","Continuar s/n?");
		}
		while(resposta2!="n"||resposta2!="N");
	}
}
