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

    string post,nomeAmigo;

    string nomeUsuario;

    bool loggedAdmin=false,loggedUsuario=false;
    int opcao,opcaoAdmin,opcaoUsuario,opcaoAmigos,opcaoPosts;
	do
	{
	    opcao=m2.menuLogin();
		switch(opcao)
		{
			case 1:
			    loggedAdmin=loginAdministrador();
			    if(loggedAdmin)
                {
                    opcaoAdmin=m2.menuAdministradores();
                    switch(opcaoAdmin)
                    {
                        case 1://criar
                            criarUsuario();
                        break;
                        case 2://pesquisar/visualizar conta
                            nomeUsuario=v3.validarString(1,20,"Introduza o nome de usuario");
                            tc.pesquisarConta(nomeUsuario);
                        break;//visualizar
                        case 3://remover
                            nomeUsuario=v3.validarString(1,20,"Introduza o nome de usuario");
                            tc.removerConta(nomeUsuario);
                        break;
                        case 4://listar
                            tc.listarTabela();
                        break;
                        case 5:break;//Estatisticas por fazer
                        case 0:m2.menuLogin();break;
                    }
                }
                else
                    cout<<"User de admin incorrecto"<<endl;
			    break;
			case 2:
			    loggedUsuario=loginUtilizador();
			    if(loggedUsuario)
                {
                    opcaoUsuario=m2.menuUtilizadores();
                    switch(opcaoUsuario)
                    {
                        case 1://Funcionalidades do meu post
                            opcaoPosts=m2.menuPosts();
                            switch(opcaoPosts)
                            {
                                case 1:
                                    post=v3.validarString(1,140,"Insira o Post");
                                    tc.adicionarPost("US",post);
                                    m2.menuPosts();
                                break;
                                case 2:tc.visualizarMural();break;
                                case 0:m2.menuUtilizadores();break;
                            }
                            break;
                        case 2://Funcionalidades do menu amigos
                            opcaoAmigos=m2.menuAmigos();
                            switch(opcaoAmigos)
                            {
                                case 1:
                                    nomeAmigo=v3.validarString(1,140,"Insira nome de usuario que deseja adicionar");
                                    tc.adicionarAmigo(nomeAmigo);
                                    m2.menuAmigos();
                                break;
                                case 2:
                                    nomeAmigo=v3.validarString(1,140,"Insira nome de amigo que deseja remover");
                                    tc.removerAmigo(nomeAmigo);
                                    m2.menuAmigos();
                                break;
                                 case 3:
                                    tc.visualizarAmigos();
                                    m2.menuAmigos();
                                break;
                                case 0:m2.menuUtilizadores();break;
                            }
                            break;
                        case 0:m2.menuUtilizadores();
                    }
                }
                else
                    cout<<"User normal incorrecto"<<endl;

			break;
			case 3:
			    criarUsuario();
			    loginGeral();
            break;
			case 0:break;

		}
	}
	while(opcao!=0);
}


bool Login::loginAdministrador()
{
	string nomeUsuario=v3.validarString(1,20,"Introduza o nome de usuario");
	string senha=v3.validarString(1,6,"introduza a senha");

	if(nomeUsuario=="edagram" &&senha=="eda1")
		return true;
	else
		return false;
}

bool Login::loginUtilizador()
{
	string nomeUsuario=v3.validarString(1,20,"Introduza o nome de usuario");
	string senha=v3.validarString(1,6,"introduza a senha");
	return tc.confirmarCredencial(nomeUsuario,senha);
}

void Login::criarUsuario()
{
    string nome=v3.validarString(1,10,"Introduza o seu primeiro nome![Max 10 caracteres]");
    string apelido=v3.validarString(1,10,"Introduza o seu Apelido ![Max 10 caracteres]");
    string senha=v3.validarString(1,6,"Introduza A sua senha![Max 6 caracteres]");
    string pais=v3.validarString(1,10,"Introduza o seu Pais![Max 20 caracteres]");
    string dataNascimento=v3.validarString(1,8,"Introduza a sua data de nascimento ![Max 8 caracteres sem espacos]");
    tc.criarConta(nome,apelido,senha,pais,dataNascimento);

}

int main()
{
	Login l;
	l.loginGeral();
	return 0;
}
