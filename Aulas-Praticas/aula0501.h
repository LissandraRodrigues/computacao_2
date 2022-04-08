/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Professor: Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiza Lissandra Rodrigues Rosa
 * Descricao: Prototipo da funcao Gerar Digitos Verificadores,
 *			      Validar RG e definicoes de tipos.
 *
 * $Author: luiza.rosa $
 * $Date: 2022/01/17 00:31:51 $
 * $Log: aula0501.h,v $
 * Revision 1.3  2022/01/17 00:31:51  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.2  2022/01/14 01:43:57  luiza.rosa
 * Programa: Insercao do cabecalho da funcao de validar RG.
 *
 * Revision 1.1  2022/01/13 17:49:06  luiza.rosa
 * Initial revision
 *
*/

#ifndef _AULA0501_
#define _AULA0501_							 "@(#)aula0501.h $Revision: 1.3 $"

typedef unsigned char byte;

typedef enum { sucesso, valido, invalido } tipoErros;

tipoErros
GerarDigitosVerificadoresRg (byte	[] /* entrada/saida */);

tipoErros
ValidarRg (byte [] /* entrada */);

#endif

/* $RCSfile: aula0501.h,v $ */
