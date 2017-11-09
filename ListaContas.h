
#include <string>
#include "ListaAmigos.h"
#include "ListaPosts.h"
class ListaContas
{
	private:
		struct Contas
		{
			std::string nomeUsuario;
			std::string senha;
			std::string nome;
			std::string apelido;
			std::string pais;
			std::string dataNascimento;

			Contas *next;
		};
		Contas *inicio;
		int totalContas;
	public:
		ListaContas();
		bool listaVazia();
		bool existeConta(std::string nomeUsuario);//Verifica se uma determinada conta existe naquele registo
		bool validarCredencial(std::string nomeUsuario,std::string senha);
		void inserirConta(std::string nome,std::string apelido,std::string nomeUsuario,std::string senha,
							std::string pais,std::string dataNascimento);//insere uma conta no inicio de um registo
		void listarContas();//visualiza todas as contas do registo
		void removerUmaConta(std::string nomeUsuario);//remove conta do Registo
		void visualizarConta(std::string nomeUsuario);//Retorna uma conta apos verificar sua existencia
		int quantidadeDeContas();//retorna quantidade de Contas existentes naquele registo
		int quantidadeDePosts();//retorna a quantidade de posts existentes no feed de uma conta
										/*Adaptadores para amigos*/
		void adpAdicionarAmigo(std::string nomeUsuario);//Adiciona um amigo
		void adpRemoverAmigo(std::string nomeUsuario);
		void adpVisualizarAmigo(std::string nomeUsuario);
		void adpListarAmigos();
		int adpQuantidadeDeAmigos();//retorna a quantidade de amigos existentes numa lista de amigos de uma conta
										/*Adaptadores para Posts*/
		void adpInserirPost(std::string nomeUsuario,std::string post);
		void adpListarPosts();
		void adpListarPostsDeAmigo(std::string nomeUsuario);//Por fazer
		int adpQuantidadeDePosts();







};
