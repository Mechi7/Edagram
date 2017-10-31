#include <string>
class ListaAmigos
{
	private:
		struct Amigos
		{
			std::string nomeUsuario;
			Amigos *next;
		};
		Amigos *inicio;
		int totalAmigos;
	public:
		ListaAmigos();
		bool listaVazia();
		bool existeAmigo(std::string nomeUsuario);
		void inserirAmigo(std::string nomeUsuario);//inserir um amigo no fim da Lista
		void listarAmigos();
		void removerUmAmigo(std::string nomeUsuario);
		void retornarAmigo(std::string nomeUsuario);
		int quantidadeDeAmigos();
	
};
