/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author$
* $Date
* $Log$
*/


#ifndef _aula0801_
#define _aula0801_ "@(#)aula0801.h$Revisions$"

#include <stdlib.h>

#define 	NUMERO_ARGUMENTOS_SEPARADOS_VALIDOS	11
#define 	NUMERO_ARGUMENTOS_JUNTOS_VALIDOS	2
#define		TAMANHO_PISPASEP					11

#define		EOS									'\0'

typedef		unsigned char						byte;

typedef enum
{
   falso 						= 0,
   verdadeiro 					= 1,
} boolean;

byte
GerarDigitoVerificadorPisPasep (char *numero);

boolean
ValidarPisPasep (char *numero); 

typedef	enum
{
  OK 							= 0,
  NUMERO_INVALIDO_ARGUMENTOS 	= 20,
  ARGUMENTO_INVALIDO			= 21,
} tipoErros;

#endif
