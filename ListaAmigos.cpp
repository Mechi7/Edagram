#include <iostream>
#include "ListaAmigos.h"

using namespace std;

ListaAmigos::ListaAmigos()
{
	inicio=NULL;
	totalAmigos=0;
}
bool ListaAmigos::listaVazia()
{
	if(inicio==NULL)
		return true;
	return false;
}

bool ListaAmigos::existeAmigo(string nomeUsuario)
{
	Amigos *percorre=inicio;
	bool find=false;
	if(listaVazia()){cout<<"Nao existem Amigos"<<endl;}
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

void ListaAmigos::inserirAmigo(string nomeUsuario)
{
	Amigos *percorre=inicio;//apontador que percorre a lista apartir do inicio 
	Amigos *novoAmigo=new Amigos;//apontador para a nova conta
	novoAmigo->nomeUsuario=nomeUsuario;
	novoAmigo->next=NULL;
	
	if(listaVazia())
	{
		inicio=novoAmigo;
		cout<<"novo Amigo: "<<novoAmigo->nomeUsuario<<" Adicionada com sucesso"<<endl;
		totalAmigos++;
	}
	else if(!existeAmigo(novoAmigo->nomeUsuario))//Verifica se o Amigo ja existe
	{

			while(percorre->next!=NULL){percorre=percorre->next;}//Assignment responsavel por percorrer a lista
			percorre->next=novoAmigo;//Adiciona o elemento ao fim da lista
			cout<<"novo Amigo: "<<novoAmigo->nomeUsuario<<" Adicionada com sucesso"<<endl;
			totalAmigos++;			
	}
	else
		cout<<"Este usuario ja e nosso Amigo"<<endl;
}

void ListaAmigos::listarAmigos()
{
	Amigos *percorre=inicio;
	if(listaVazia()){cout<<"Ainda nao tem Amigos"<<endl;}
	else
	{
		while(percorre!=NULL)
		{
			cout<<"Amigo:\t"<<percorre->nomeUsuario<<endl;
			percorre=percorre->next;
		}
	}
}

void ListaAmigos::removerUmAmigo(string nomeUsuario)
{
	Amigos *apagar=inicio,*anterior=NULL;//variavel anterior armazena a posicao do amigo anterior a que for removido
	bool stop=false;
	if(listaVazia()){cout<<"Ainda nao tem amigos"<<endl;}
	else if(existeAmigo(nomeUsuario))
	{
		while(apagar!=NULL && stop==false)
		{
			if(anterior==NULL && apagar->nomeUsuario==nomeUsuario)//se o amigo a remover for  o unico no registo
			{
				inicio=inicio->next;//substituir o inicio pela conta seguinte
				stop=true;
			}
		
			else if(apagar->nomeUsuario==nomeUsuario)
			{
				anterior->next=apagar->next;//Substitui a Conta removido pelo Amigo seguinte juntando o Amigo seguinte  ao amigo anterior
				stop=true;
			}
			anterior=apagar;//armazenar a posicao anterior a cada iteracao
			apagar=apagar->next;//Avancar uma posicao a cada iteracao
		}
		cout<<"Amigo:\t"<<nomeUsuario<<"\t removido com sucesso"<<endl;
		totalAmigos--;
	}
	else
		cout<<"Amigo inexistente"<<endl;
}

int ListaAmigos::quantidadeDeAmigos()
{
	return totalAmigos;
}
int main()
{
	ListaAmigos la;
	la.inserirAmigo("Amigo1");
	la.inserirAmigo("Amigo1");
	la.inserirAmigo("Amigo2");
	la.inserirAmigo("Amigo3");
	la.listarAmigos();
	la.removerUmAmigo("amigo2");
	la.listarAmigos();
	return 0;
}
