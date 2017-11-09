#include <iostream>
#include <string>
#include "Login.h"
using namespace std;
TabelaContas tc;
Validacoes v3;//Quando o nosso ponto h ja faz parte parte dos includes de uma das bibliotecas q queremos usar podemos omitir o seu include
Menu m2;
Login::Login(){}

void Login::loginGeral()
{
	int opcao=m2.menuLogin();
	do
	{
		switch(opcao)
		{
			case 1:loginAdministrador();break;
			case 2:loginUtilizador();break;
			case 3:criarUsuario();break;
			case 0:break;
		}
	}
	while(opcao!=0);
}

void Login::loginAdministrador()
{
	string nomeUsuario=v3.validarString(1,20,"Introduza o nome de usuario");
	string senha=v3.validarString(1,6,"introduza a senha");

	if(nomeUsuario=="edagram" &&senha=="eda1")
		m2.menuAdministradores();
	else
		cout<<"Dados Incorrectos";
}

void Login::loginUtilizador()
{
	string nomeUsuario=v3.validarString(1,20,"Introduza o nome de usuario");
	string senha=v3.validarString(1,6,"introduza a senha");
	if(tc.confirmarCredencial(nomeUsuario,senha))
        m2.menuUtilizadores();
}

void Login::criarUsuario()
{
    string nome=v3.validarString(1,10,"Introduza o seu primeiro nome![Max 10 caracteres]");
    string apelido=v3.validarString(1,10,"Introduza o seu Apelido ![Max 10 caracteres]");
    string senha=v3.validarString(1,6,"Introduza A sua senha![Max 6 caracteres]");
    string pais=v3.validarString(1,10,"Introduza o seu Pais![Max 20 caracteres]");
    string dataNascimento=v3.validarString(1,8,"Introduza a sua data de nascimento ![Max 8 caracteres sem espacos]");
    tc.criarConta(nome,apelido,senha,pais,dataNascimento);
    loginGeral();
}

int main()
{
	Login l;
	l.loginGeral();
	return 0;
}
