class Tags;//Forward Declaration
#include <string>
class ListaPosts
{
	private:
		struct Posts
		{
			std::string nomeUsuario;
			std::string post;
			Tags *tags;
	
			Posts *next;
		};
		Posts *inicio;
		int totalPosts;
		
	public:
		ListaPosts();
		bool listaVazia();
		void inserirPost(std::string nomeUsuario,std::string post,Tags *tags);//insercao de um Post no inicio da Lista
		void listarPosts();
		void listarPostsDeAmigo(std::string nomeUsuario);
		int quantidadeDePosts();
	
};
