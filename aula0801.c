/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/10/31 00:13:10 $
* $Log: aula0801.c,v $
* Revision 1.1  2016/10/31 00:13:10  felipe.santos
* Initial revision
*
*/

#include "aula0801.h"

unsigned pesosPISPASEP[10] = {3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

byte
GerarDigitoVerificadorPisPasep (byte numero[])
{
	unsigned indice;
	unsigned long soma = 0;

	for ( indice = 0; indice < (TAMANHO_PISPASEP - 1) ; indice++ )
		soma += (unsigned long ) (numero[indice] * pesosPISPASEP[indice]);
	soma %= 11;

	if ( (soma == 0) || (soma == 1) )
	return (0);

	return (11 - soma);
}


boolean
ValidarPisPasep (byte numero[])
{
  byte numeroTemporario[TAMANHO_PISPASEP - 1];
  unsigned indice;
  
  for ( indice = 0; indice < (TAMANHO_PISPASEP - 1); indice++ )
	numeroTemporario[indice] = numero[indice];
  
  if ( numero[TAMANHO_PISPASEP - 1] != GerarDigitoVerificadorPisPasep (numeroTemporario))
	return (falso);
  
  return (verdadeiro);
}

/* $RCSfile: aula0801.c,v $ */
