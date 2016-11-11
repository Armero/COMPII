/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/10/31 00:13:10 $
* $Log: aula0804.c,v $
* Revision 1.1  2016/10/31 00:13:10  felipe.santos
* Initial revision
*
*/

#include "aula0804.h"

unsigned pesosPISPASEP[10] = {3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

byte
GerarDigitoVerificadorPisPasep (char *numero)
{
	unsigned indice;
	unsigned long soma = 0;
	byte numeroByte[TAMANHO_PISPASEP];

	for ( indice = 0; indice < (TAMANHO_PISPASEP - 1); indice++ )
	{
		if (numero[indice] == '-')
			return ( (byte) ARGUMENTO_INVALIDO);
		
		if ( (numero[indice] < '0') || (numero[indice] > '9') )
			return ( (byte) ARGUMENTO_INVALIDO);
		numeroByte[indice] = numero[indice] - '0';
	}
	
	for ( indice = 0; indice < (TAMANHO_PISPASEP - 1) ; indice++ )
		soma += (unsigned long ) (numeroByte[indice] * pesosPISPASEP[indice]);
	soma %= 11;

	if ( (soma == 0) || (soma == 1) )
	return (0);

	return (11 - soma);
}


boolean
ValidarPisPasep (char *numero)
{
  char numeroTemporario[TAMANHO_PISPASEP];
  unsigned indice;
  
  for ( indice = 0; indice < (TAMANHO_PISPASEP - 1); indice++ )
	numeroTemporario[indice] = numero[indice];
  
  numeroTemporario[indice] = EOS;
  
  if ( (numero[TAMANHO_PISPASEP - 1] - '0') != GerarDigitoVerificadorPisPasep (numeroTemporario))
	return (falso);
  
  return (verdadeiro);
}

/* $RCSfile: aula0804.c,v $ */
