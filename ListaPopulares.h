#ifndef _H_LISTAPOPULARES
#define _H_LISTAPOPULARES
#include <string>
class ListaPopulares
{
	private:
		struct Populares
		{
			std::string nomeUsuario;
			int totalTags;
			Populares *next;
		};
		Populares *inicio;
		int totalPopulares;
	public:
		ListaPopulares();
		bool listaVazia();
		bool existePopular(std::string nomeUsuario);
		void inserirPopular(std::string nomeUsuario,int totalTags);//Melhorar este metodo
		void listarPopulares();

};
#endif // _H_LISTAPOPULARES
