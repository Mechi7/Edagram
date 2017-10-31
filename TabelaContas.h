#include "ListaContas.h"
class TabelaContas
{
	private:
		ListaContas tabelaDispersao[27];//So funcionou apos incluir o header file Lista Contas
	public:
		TabelaContas();
		void criarConta(char nomeUsuario);
		void removerConta(char nomeUsuario);
		void pesquisarConta(char nomeUsuario);
		int funcaoDispersao(char nomeUsuario);
		void listarTabela();
		int totalContasTabela();
};
