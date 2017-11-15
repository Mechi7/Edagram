#include <iostream>
#include "TabelaContas.h"

using namespace std;
Menu m;
ListaContas lc;
TabelaContas::TabelaContas(){}

int TabelaContas::funcaoDispersao(string nomeUsuario)
{
	int u=nomeUsuario[0];

	return u%27;
}

void TabelaContas::criarConta(string nome,string apelido,string senha,
							string pais,string dataNascimento)//remove uma conta contida em algum registo da tabela
{
	string nomeUsuario=nome+apelido;
	int pos=funcaoDispersao(nomeUsuario);
	tabelaDispersao[pos].inserirConta(nome,apelido,nomeUsuario,senha,pais,dataNascimento);

}

void TabelaContas::removerConta(string nomeUsuario)
{
	int pos=funcaoDispersao(nomeUsuario);
	tabelaDispersao[pos].removerUmaConta(nomeUsuario);
}
void TabelaContas::pesquisarConta(string nomeUsuario)
{
	int pos=funcaoDispersao(nomeUsuario);
	tabelaDispersao[pos].visualizarConta(nomeUsuario);
}

bool TabelaContas::confirmarCredencial(string nomeUsuario, string senha)
{
	bool logado=false;
	int pos=funcaoDispersao(nomeUsuario);
	logado=tabelaDispersao[pos].validarCredencial(nomeUsuario,senha);
	return logado;
}
bool TabelaContas::confirmarUsuario(string nomeUsuario)
{
	bool find=false;
	int pos=funcaoDispersao(nomeUsuario);
	find=tabelaDispersao[pos].existeConta(nomeUsuario);
	return find;
}

void TabelaContas::listarTabela()
{
    if(totalContasTabela()>0)
     {
        for(int i=0;i<27;i++)
        {
            if(tabelaDispersao[i].quantidadeDeContas()>0)
                tabelaDispersao[i].listarContas();
        }
     }
     else
        cout<<"Nao existem Contas"<<endl;
}

int TabelaContas::totalContasTabela()
{
	int totalContas=0;
	for (int i=0;i<27;i++)
	{
		totalContas+=tabelaDispersao[i].quantidadeDeContas();
	}

	return totalContas;
}


/*Funcoes para  Gerir Amizades*/


void TabelaContas::adicionarAmigo(string nomeAmigo)
{//Para nao adicionarmos usuarios que nao existam no sistema tivemos que recorrer
	//ao metodo confirmarUsuario da  classe Tabela Contas
	//outras solucoes criavam conflitos de redefinicao de classe
	int pos=funcaoDispersao(nomeAmigo);
	if(tabelaDispersao[pos].existeConta(nomeAmigo))
		lc.adpAdicionarAmigo(nomeAmigo);
		//int pos=funcaoDispersao(nomeAmigo);
		//tabelaDispersao[pos].adpAdicionarAmigo("Us");
}

void TabelaContas::removerAmigo(string nomeAmigo)
{
    int pos=funcaoDispersao(nomeAmigo);
    if(tabelaDispersao[pos].existeConta(nomeAmigo))
        lc.adpRemoverAmigo(nomeAmigo);
}

void TabelaContas::visualizarAmigos()
{
    lc.adpListarAmigos();
}


///////Posts
void TabelaContas::adicionarPost(string nomeUsuario,string post)
{
    int pos=funcaoDispersao(nomeUsuario);
    lc.adpInserirPost(nomeUsuario, post);
}

void TabelaContas::visualizarMural()
{
    lc.adpListarPosts();
}

