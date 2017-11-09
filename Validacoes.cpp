#include <iostream>
#include "Validacoes.h"
using namespace std;

Validacoes::Validacoes(){}

string Validacoes::validarString(int a,int b,string mensagem)
{
	string dado="",aux="";//aux variavel q armazena o a string durante a transformacao para lower case
	locale loc;
	cout<<mensagem<<endl;
	do
	{
		cin>>aux;

		if(aux.size()<a|| aux.size()>b)
			cout<<"Valor introduzido e invalida, introduza correctamente!"<<endl;
	}
	while(aux.size()<a|| aux.size()>b);

	for(int i=0;i<aux.length();i++)
	{
		dado+=tolower(aux[i],loc);//Transformar para Lower case
	}
	return dado;
}
string Validacoes::validarString2(string a,string b,string c,string d,string mensagem)
{
	string dado="";
	cout<<mensagem<<endl;
	do
	{
		cin>>dado;

		if(dado!=a&&dado!=b&&dado!=c&&dado!=d)
		cout<<"Valor introduzido e invalido, introduza correctamente!"<<endl;
	}
	while(dado!=a&&dado!=b&&dado!=c&&dado!=d);
	return dado;
}

int Validacoes::validarOpcao(int a,int b,string mensagem)
{
	int dado=-1;
	cout<<mensagem<<endl;
	do
	{
		cin>>dado;
		if(dado<a || dado>b)
		cout<<"Valor introduzido e invalida, introduza correctamente!"<<endl;
	}
	while(dado<a || dado>b);
	return dado;
}


