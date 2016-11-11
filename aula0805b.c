/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/10/31 00:13:57 $
* $Log: aula0805b.c,v $
* Revision 1.1  2016/10/31 00:13:57  felipe.santos
* Initial revision
*
*
*/

/*Espaco reservado para os includes*/
#include "aula0804.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*Fim dos includes*/


/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{
	unsigned indice;
	char numero[TAMANHO_PISPASEP];
	byte digitoVerificador;

	if (  (argc != NUMERO_ARGUMENTOS_JUNTOS_VALIDOS) || ( strlen(argv[1]) != (TAMANHO_PISPASEP - 1) )  )
	{
		printf ("Uso: %s <numero-de-argumentos-invalidos>\n", argv[0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1d2...d10>\n");
		exit (NUMERO_INVALIDO_ARGUMENTOS);
	}
	
	for ( indice = 0; indice < (TAMANHO_PISPASEP - 1) ; indice++ )
		numero [indice] = argv[1][indice];
	
	numero [indice] = EOS;
	
	digitoVerificador = GerarDigitoVerificadorPisPasep (numero);	
	if (digitoVerificador == ARGUMENTO_INVALIDO)
	{
		printf ("Uso: %s <argumento-invalido>\n", argv[0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1d2...d10>\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	printf ( "O digito verificador eh: %u\n",  digitoVerificador);
	/* Caso o programa o input do usuario tenha sido feito de maneira correta*/
	return (OK);
} 

/* $RCSfile: aula0805b.c,v $ */