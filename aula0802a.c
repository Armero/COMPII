/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author$
* $Date$
* $Log$
*
*/

/*Espaco reservado para os includes*/

#include "aula0801.h"
#include <stdlib.h>
#include <stdio.h>


/*Fim dos includes*/


/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{
	unsigned indice;
	byte numero[TAMANHO_PISPASEP - 1];
	char *verificacao;

	if ( argc != NUMERO_ARGUMENTOS_SEPARADOS_VALIDOS)
	{
		printf ("Uso: %s <numero-de-argumentos-invalidos>\n", argv[0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1> <d2> ... <d10>\n");
		exit (NUMERO_INVALIDO_ARGUMENTOS);
	}


	for ( indice = 1; indice < TAMANHO_PISPASEP; indice++ )
	{
		if (argv[indice][0] == '-')
		{
			printf ("Uso: %s <argumento-%d-invalido: %s>\n", argv[0], indice, argv[indice]);
			printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1> <d2> ... <d10>\n");
			exit (ARGUMENTO_INVALIDO);
		}
		
		numero [indice - 1] = (byte)strtoul(argv[indice], &verificacao, 10);
		if ( *verificacao != EOS )
		{
			printf ("Uso: %s <argumento-%d-invalido: %s>\n", argv[0], indice, argv[indice]);
			printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1> <d2> ... <d10>\n");
			exit (ARGUMENTO_INVALIDO);
		}
	}

	printf ( "O digito verificador eh: %u\n", GerarDigitoVerificadorPisPasep (numero) );
	/* Caso o programa o input do usuario tenha sido feito de maneira correta*/
	return (OK);
} 

/* $RCSfile$ */