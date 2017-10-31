#include <iostream>
#include "ListaContas.h"


using namespace std;

ListaContas::ListaContas()
{
	inicio=NULL;
	totalContas=0;
}
bool ListaContas::listaVazia()
{
	if(inicio==NULL)
		return true;
	return false;
}

bool ListaContas::existeConta(string nomeUsuario)
{
	Contas *percorre=inicio;
	bool find=false;
	if(listaVazia()){cout<<"Nao existem Contas"<<endl;}
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

void ListaContas::inserirConta(string nome,string apelido,string senha,string pais,string dataNascimento)
{
	Contas *percorre=inicio;//apontador que percorre a lista apartir do inicio 
	Contas *novaConta=new Contas;//apontador para a nova conta
	novaConta->nomeUsuario=nome+apelido;
	novaConta->nome=nome;
	novaConta->apelido=apelido;
	novaConta->senha=senha;
	novaConta->pais=pais;
	novaConta->dataNascimento=dataNascimento;
	novaConta->amigos=NULL;
	novaConta->posts=NULL;
	novaConta->next=NULL;
	
	if(listaVazia())
	{
		inicio=novaConta;
		cout<<"nova Conta: "<<novaConta->nomeUsuario<<" Adicionada com sucesso"<<endl;
		totalContas++;
	}
	else if(!existeConta(novaConta->nomeUsuario))//Verifica se o username ja foi utilizado
	{

			while(percorre->next!=NULL){percorre=percorre->next;}//Assignment responsavel por percorrer a lista
			percorre->next=novaConta;//Adiciona o elemento ao fim da lista
			cout<<"nova Conta: "<<novaConta->nomeUsuario<<" Adicionada com sucesso"<<endl;
			totalContas++;			
	}
	else
		cout<<"Esta Conta ja existe"<<endl;
}
void ListaContas::listarContas()
{
	Contas *percorre=inicio;
	if(listaVazia()){cout<<"Nao existem contas no Sistema"<<endl;}
	else
	{
		while(percorre!=NULL)
		{
			cout<<"usuario: "<<percorre->nomeUsuario<<"\tpais: "<<percorre->pais<<"\tdata de nascimento: "<<percorre->dataNascimento<<endl;
			percorre=percorre->next;
		}
	}
}
void ListaContas::removerUmaConta(string nomeUsuario)
{
	Contas *apagar=inicio,*anterior=NULL;//variavel anterior armazena a posicao da Conta anterior a que for removida
	bool stop=false;
	if(listaVazia()){cout<<"Nao existem Contas no Sistema"<<endl;}
	else if(existeConta(nomeUsuario))
	{
		while(apagar!=NULL && stop==false)
		{
			if(anterior==NULL && apagar->nomeUsuario==nomeUsuario)//se a conta a remover for  a unica no registo
			{
				inicio=inicio->next;//substituir o inicio pela conta seguinte
				stop=true;
			}
		
			else if(apagar->nomeUsuario==nomeUsuario)
			{
				anterior->next=apagar->next;//Substitui a Conta removida pela Conta seguinte juntando o Conta seguinte  a Conta anterior
				stop=true;
			}
			anterior=apagar;//armazenar a posicao anterior a cada iteracao
			apagar=apagar->next;//Avancar uma posicao a cada iteracao
		}
		cout<<"Conta:\t"<<nomeUsuario<<"\t removida com sucesso"<<endl;
		totalContas--;
	}
	else
		cout<<"Usuario inexistente"<<endl;
}
int ListaContas::quantidadeDeContas()
{
	return totalContas;
}

int main()
{
	ListaContas lc;
	lc.inserirConta("nome1","apelido1","senha1","pais1","dataNascimento1");
	lc.inserirConta("nome2","apelido2","senha2","pais2","dataNascimento2");
	lc.inserirConta("nome3","apelido3","senha3","pais3","dataNascimento3");
	lc.listarContas();
	lc.removerUmaConta("nome1apelido1");
	lc.listarContas();
	return 0;
}
