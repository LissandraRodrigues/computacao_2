/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Definicao do tipo enumerado
 * 				    eelTipoNumerosMensagemInterfaceUsuario
 *						e prototipo das funcoes de obter
 *  					mensagens de interface usuario Cli e Web.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/03/11 16:14:21 $
 * $Log: eelInterfaceUsuario.h,v $
 * Revision 1.1  2022/03/11 16:14:21  luiza.rosa
 * Initial revision
 *
*/

#ifndef _EELINTERFACEUSUARIO_
#define _EELINTERFACEUSUARIO_ "@(#)eelInterfaceUsuario.h $Revision: 1.1 $"

#ifdef __linux__
#define _BSD_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif

#include "eelTipos.h"

typedef enum
{
	
	mensagem,
	usuario,
	senha,
	botao	

} eelTipoNumerosMensagemInterfaceUsuario;

char *
EelObterMensagemInterfaceUsuarioCli (eelTipoIdiomas, eelTipoNumerosMensagemInterfaceUsuario);

char *
EelObterMensagemInterfaceUsuarioWeb (eelTipoIdiomas, eelTipoNumerosMensagemInterfaceUsuario);

#endif

/* $RCSfile: eelInterfaceUsuario.h,v $ */

