#ifndef LISTAGS_H_
#define LISTAGS_H_
#include <string>
#include "ListaPopulares.h"
class ListaTags
{
	private:
		struct Tags
		{
			std::string nomeUsuario;
			Tags *next;
		};
		Tags *inicio;
		int totalTags;

	public:
		ListaTags();
		bool listaVazia();
		void inserirTag(std::string nomeUsuario);
		void listarTags();
		int quantidadeDeTags();
		void adpInserirPopular(std::string nomeUsuario);
};
#endif
