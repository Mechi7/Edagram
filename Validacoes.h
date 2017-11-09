#ifndef VALIDACOES_H_
#define VALIDACOES_H_
#include <string>

class Validacoes
{
	private:
	public:
		Validacoes();
		std::string validarString(int a,int b,std::string mensagem);
		std::string validarString2(std::string a,std::string b,std::string c,std::string d,std::string mensagem);
		int validarOpcao(int a,int b,std::string mensagem);

};
#endif
