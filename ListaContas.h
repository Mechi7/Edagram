class Amigos;//Forward declaration so pode ser utilizada para ponteiros
class Posts;//Forward Declaration
#include <string>			
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
			Amigos *amigos;
			Posts *posts;			
	
			Contas *next;
		};
		Contas *inicio;
		int totalContas;
	public:
		ListaContas();
		bool listaVazia();
		bool existeConta(std::string nomeUsuario);//Verifica se uma determinada conta existe no Sistema
		void inserirConta(std::string nome,std::string apelido,std::string senha,
							std::string pais,std::string dataNascimento);//insere uma conta no fim da lista
		void listarContas();//visualiza todas as contas do sistema
		void removerUmaConta(std::string nomeUsuario);//remove conta do Sistema
		//void retornarConta(std::string nomeUsuario);//Retorna uma conta apos verificar sua existencia
		int quantidadeDeContas();//retorna quantidade de Contas existentes naquele registo
		int quantidadeDeAmigos();//retorna a quantidade de amigos existentes numa lista de amigos de uma conta
		int quantidadeDePosts();//retorna a quantidade de posts existentes no feed de uma conta
		
	//	std::string toString();
		
		
		
		
		
		
};
