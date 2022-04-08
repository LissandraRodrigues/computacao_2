/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Implementacao das funcoes de obter mensagens de erro
 *            e definicao de variaveis globais.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/11 16:08:02 $
 * $Log: eelErros.c,v $
 * Revision 1.1  2022/03/11 16:08:02  luiza.rosa
 * Initial revision
 *
*/

#include "eelConst.h"
#include "eelTipos.h"
#include "eelErros.h"

#define SUCESSO									"OK"

char *
eelMensagensErroCli [eelQuantidadeIdiomas] [eelQuantidadeErros] = 
{

	{
		"Sucesso",
		"Erro relacionado com arquivo",
		"Erro alocando memoria",
		"Senha incorreta"	
	},
	{
		"Ok",
		"File error",
		"Memory alocation error",
		"Invalid password"
	}

};

char *
eelMensagensErroWeb [eelQuantidadeIdiomas] [eelQuantidadeErros] = 
{

	{
		"Sucesso",
		"Erro relacionado com arquivo",
		"Erro alocando memoria",
		"Senha incorreta"	
	},
	{
		"Ok",
		"File error",
		"Memory alocation error",
		"Invalid password"
	}

};

char *
EelObterMensagemErroCli (eelTipoIdiomas idioma, eelTipoErros erros)
{

	return SUCESSO;

};

char *
EelObterMensagemErroWeb (eelTipoIdiomas idioma, eelTipoErros erros)
{
	
	return SUCESSO;
	
};

/* $RCSfile: eelErros.c,v $ */
