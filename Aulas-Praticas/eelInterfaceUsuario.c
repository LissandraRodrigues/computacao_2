/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Definicao de variaveis globais
 *						e	implementacao das funcoes de obter
 *  					mensagens de interface usuario Cli e Web.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/11 16:15:02 $
 * $Log: eelInterfaceUsuario.c,v $
 * Revision 1.1  2022/03/11 16:15:02  luiza.rosa
 * Initial revision
 *
*/

#include "eelConst.h"
#include "eelTipos.h"
#include "eelErros.h"
#include "eelInterfaceUsuario.h"

char *
eelMensagensInterfaceUsuarioCli [eelQuantidadeIdiomas] [eelQuantidadeErros] =
{
	
	{"Usuario"},
	{"Username"}
	
};

char *
eelMensagensInterfaceUsuarioWeb [eelQuantidadeIdiomas] [eelQuantidadeErros] =
{

	{"Usu&accute;rio"},
	{"Username"}

};

char *
EelObterMensagemInterfaceUsuarioCli (eelTipoIdiomas idioma, eelTipoNumerosMensagemInterfaceUsuario numero)
{
	return eelMensagensInterfaceUsuarioCli [idioma] [numero];
}

char *
EelObterMensagemInterfaceUsuarioWeb (eelTipoIdiomas idioma, eelTipoNumerosMensagemInterfaceUsuario numero)
{
	return eelMensagensInterfaceUsuarioWeb [idioma] [numero];
}

/* $RCSfile: eelInterfaceUsuario.c,v $ */

