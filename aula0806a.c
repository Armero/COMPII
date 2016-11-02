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
	char numero[TAMANHO_PISPASEP + 1];
	char numeroAUX [TAMANHO_PISPASEP];
	byte digitoVerificador;
	

	if ( argc != ( NUMERO_ARGUMENTOS_SEPARADOS_VALIDOS + 1) )
	{
		printf ("Uso: %s <numero-de-argumentos-invalidos>\n", argv[0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1> <d2> ... <d10>\n");
		exit (NUMERO_INVALIDO_ARGUMENTOS);
	}
	
	for ( indice = 1; indice < (TAMANHO_PISPASEP + 1); indice++ )
	{
		if (indice < TAMANHO_PISPASEP)
			numeroAUX[indice - 1] = argv[indice][0];
		
		numero[indice - 1] = argv[indice][0];
	}
	numeroAUX[indice - 2] = EOS;
	numero [indice - 1] = EOS;
	
	printf("numero: %s\n\n\n",numero);
	/* Reaproveitando as validacoes feitas em GerarDigitoVerificado */
	digitoVerificador = GerarDigitoVerificadorPisPasep (numeroAUX);
	if (digitoVerificador == ARGUMENTO_INVALIDO)
	{
		printf ("Uso: %s <argumento-invalido>\n", argv[0]);
		printf ("Por favor insira os 10 digitos do PIS/PASEP no formato: <d1> <d2> ... <d10>\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	printf ( "O digito verificador eh: %s\n", ValidarPisPasep(numero)?"verdadeiro":"falso" );
	/* Caso o programa o input do usuario tenha sido feito de maneira correta*/
	return (OK);
} 

/* $RCSfile$ */