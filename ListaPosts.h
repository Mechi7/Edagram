#ifndef LISTAPOSTS_H_
#define LISTAPOSTS_H_
#include <string>
#include "Validacoes.h"
#include "ListaTags.h"//Como inserir uma lista de Tags ha um Post
class ListaPosts
{
	private:
		struct Posts
		{
			std::string nomeUsuario;
			std::string post;

			Posts *next;
		};
		Posts *inicio;
		int totalPosts;

	public:
		ListaPosts();
		bool listaVazia();
		void inserirPost(std::string nomeUsuario,std::string post);//insercao de um Post no inicio da Lista
		void listarPosts();
		void listarPostsDeAmigo(std::string nomeUsuario);
		int quantidadeDePosts();
		void adpInserirTag();


};
#endif
