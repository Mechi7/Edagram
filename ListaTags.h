#include <string>
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
		void inserirTag(std::string nomeUsuario);//insercao de um Post no inicio da Lista
		void listarTags();
		int quantidadeDeTags();
		bool popular();
	
};
