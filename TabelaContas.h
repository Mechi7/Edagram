#ifndef TABELACONTAS_H_
#define TABELACONTAS_H_
#include "ListaContas.h"
#include "Menu.h"
class TabelaContas
{
	private:
		ListaContas tabelaDispersao[27];//So funcionou apos incluir o header file Lista Contas
		//ListaContas lc;
	public:
		TabelaContas();
		int funcaoDispersao(std::string nomeUsuario);
		void criarConta(std::string nome,std::string apelido,std::string senha,
							std::string pais,std::string dataNascimento);
		void removerConta(std::string nomeUsuario);
		void pesquisarConta(std::string nomeUsuario);
		bool confirmarCredencial(std::string nomeUsuario,std::string senha);
		bool confirmarUsuario(std::string nomeUsuario);
		void listarTabela();
		void totalContasTabela();
		////////////////////////Amigos
		void adicionarAmigo(std::string nomeUsuario,std::string nomeUsuarioAmigo);
		void removerAmigo(std::string nomeUsuario,std::string nomeUsuarioAmigo);



};
#endif
