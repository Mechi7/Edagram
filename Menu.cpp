#include <iostream>
#include "Menu.h"
using namespace std;
Validacoes v2;
Menu::Menu()
{
}

int Menu::menuLogin()
{
	int opcao;
	cout<<"|-----------------------|"<<endl;
	cout<<"|          LOGIN        |"<<endl;
	cout<<"|-----------------------|"<<endl;
	cout<<"| [1]   Administrador   |"<<endl;
	cout<<"| [2]    Utilizador     |"<<endl;
	cout<<"| [3]    Criar Conta    |"<<endl;
	cout<<"| [0]       Sair        |"<<endl;
	cout<<"|-----------------------|"<<endl;
	opcao=v2.validarOpcao(0,3,"Escolha uma das opcoes");
	return opcao;

}
int Menu::menuUtilizadores()
{
	int opcao;
	cout<<"|=============================|"<<endl;
	cout<<"|     MENU DOS UTILIZADORES   |"<<endl;
	cout<<"|=============================|"<<endl;
	cout<<"| [1]        Mural			 |"<<endl;
	cout<<"| [2]        Amigos	 		 |"<<endl;
	cout<<"| [0]        Sair          	 |"<<endl;
	cout<<"|=============================|"<<endl;
	opcao=v2.validarOpcao(0,3,"Escolha uma das opcoes");
	return opcao;
}

int Menu::menuPosts()
{
	int opcao;
	cout<<"|=============================|"<<endl;
	cout<<"|   		 MENU DOS POSTS      |"<<endl;
	cout<<"|=============================|"<<endl;
	cout<<"| [1]       Criar Post  		 |"<<endl;
	cout<<"| [2]      Visualizar Posts	 |"<<endl;
	cout<<"| [0]          Voltar         |"<<endl;
	cout<<"|=============================|"<<endl;
	opcao=v2.validarOpcao(0,3,"Escolha uma das opcoes");
	return opcao;
}
int Menu::menuAmigos()
{
	int opcao;
	cout<<"|=============================|"<<endl;
	cout<<"|    	 MENU AMIZADES		 |"<<endl;
	cout<<"|=============================|"<<endl;
	cout<<"| [1]     Adicionar Amigo	 |"<<endl;
	cout<<"| [2]      Remover Amigo	     |"<<endl;
	cout<<"| [3]     Visualizar Amigos   |"<<endl;
	cout<<"| [0]          Voltar         |"<<endl;
	cout<<"|=============================|"<<endl;
	opcao=v2.validarOpcao(0,3,"Escolha uma das opcoes");
	return opcao;
}

int Menu::menuAdministradores()
{
	int opcao;
    cout<<"|======================================|"<<endl;
    cout<<"|      MENU DOS ADMINISTRADORES[2]     |"<<endl;
	cout<<"|======================================|"<<endl;
	cout<<"| [1]         Cria Conta   			  |"<<endl;
	cout<<"| [2]       Visualizar Conta  	      |"<<endl;
	cout<<"| [3]        Remover Conta        	  |"<<endl;
	cout<<"| [4]       Listar Contas          	  |"<<endl;
	cout<<"| [5]       Estatisticas          	  |"<<endl;
	cout<<"| [0]            Sair                  |"<<endl;
	cout<<"|======================================|"<<endl;
	opcao=v2.validarOpcao(0,6,"Escolha uma das opcoes:\n");
	return opcao;
}

