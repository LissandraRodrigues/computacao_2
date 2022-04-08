/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Definicao do tipo eelTipoErros
 *						e prototipo das funcoes de obter
 *  					mensagens de erro Cli e Web.
 * $Author: luiza.rosa $
 * $Date: 2022/03/11 16:09:35 $
 * $Log: eelErros.h,v $
 * Revision 1.1  2022/03/11 16:09:35  luiza.rosa
 * Initial revision
 *
*/

#ifndef _EELERROS_
#define _EELERROS_ "@(#)eelErros.h $Revision: 1.1 $"

#include "eelTipos.h"

typedef enum
{
	
	ok

} eelTipoErros;

char *
EelObterMensagemErroCli (eelTipoIdiomas, eelTipoErros);

char *
EelObterMensagemErroWeb (eelTipoIdiomas, eelTipoErros);

#endif

/* $RCSfile: eelErros.h,v $ */

