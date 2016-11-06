/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/11/05 23:29:54 $
* $Log: aula0901.h,v $
* Revision 1.1  2016/11/05 23:29:54  felipe.santos
* Initial revision
*
*/


#ifndef _aula0801_
#define _aula0801_ "@(#)aula0901.h$Revisions$"

#include <string.h>

#define		NUMERO_ARGUMENTOS_VALIDOS			2
#define		CONJUNTO_BASE_64							"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define		TAMANHO_CONTEUDO							3
#define		TAMANHO_TOTAL									76
#define 	EOS 													'\0'

typedef		unsigned char		byte;

typedef enum
{
  OK,
  NUMERO_ARGUMENTOS_INVALIDOS,
  CARACTERE_INVALIDO,
}tipoErros;

tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida);

tipoErros
DecodificarBase64 (char *entrada, byte *saida, unsigned *numeroBytes);

/* funcao auxiliar que acha a posicao do caracere na string CONJUNTO_BASE_64 */
byte
DescobrirIndice (byte elemento);

#endif

/* $RCSfile: aula0901.h,v $ */