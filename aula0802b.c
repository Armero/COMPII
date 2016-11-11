/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/10/31 00:10:43 $
* $Log: aula0802b.c,v $
* Revision 1.1  2016/10/31 00:10:43  felipe.santos
* Initial revision
*
*
*/

/*Espaco reservado para os includes*/
#include "aula0801.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*Fim dos includes*/


/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{
	unsigned indice;
	byte numero[TAMANHO_PISPASEP - 1];

	if (  (argc != NUMERO_ARGUMENTOS_JUNTOS_VALIDOS) || ( strlen(argv[1]) != (TAMANHO_PISPASEP - 1) )  )
	{
		printf ("Uso: %s <numero-de-argumentos-invalidos>\n", argv[0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1d2...d10>\n");
		exit (NUMERO_INVALIDO_ARGUMENTOS);
	}


	if (argv[1][0] == '-') 
	{
		printf ("Uso: %s <argumento-0-invalido: %c>\n", argv[0], argv[1][0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1d2...d10>\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	for ( indice = 0; indice < (TAMANHO_PISPASEP - 1) ; indice++ )
	{
		if (argv[1][indice] == '-') 
		{
			printf ("Uso: %s <argumento-%d-invalido: %c>\n", argv[0], indice, argv[1][indice]);
			printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1d2...d10>\n");
			exit (ARGUMENTO_INVALIDO);
		}
		
		
		if ( (argv[1][indice] < '0') || (argv[1][indice] > '9') )
		{
			printf ("Uso: %s <argumento-%d-invalido: %c>\n", argv[0], indice, argv[1][indice]);
			printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1d2...d10>\n");
			exit (ARGUMENTO_INVALIDO);
		}
		
		numero [indice] = argv[1][indice] - '0';

	}

	printf ( "O digito verificador eh: %u\n", GerarDigitoVerificadorPisPasep (numero) );
	/* Caso o programa o input do usuario tenha sido feito de maneira correta*/
	return (OK);
} 

/* $RCSfile: aula0802b.c,v $ */