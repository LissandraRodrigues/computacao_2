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
 * $Date: 2022/01/17 00:46:06 $
 * $Log: aula0504.h,v $
 * Revision 1.2  2022/01/17 00:46:06  luiza.rosa
 * Programa: Atualizacao da descricao.
 *
 * Revision 1.1  2022/01/15 01:32:30  luiza.rosa
 * Initial revision
 *
*/

#ifndef _AULA0504_
#define _AULA0504_							 "@(#)aula0504.h $Revision: 1.2 $"

typedef enum { sucesso, valido, invalido } tipoErros;

tipoErros
GerarDigitosVerificadoresRg (char * /* entrada */, char * /* saida */);

tipoErros
ValidarRg (char * /* entrada */);

#endif

/* $RCSfile: aula0504.h,v $ */
