/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/09/23 00:45:39 $
* $Log: aula0302.c,v $
* Revision 1.1  2016/09/23 00:45:39  felipe.santos
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include <stdlib.h>
#include <stdio.h>
#include "aula0301.h"
/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define OK			0 
#define NUMERO_INVALIDO_ARGS	1	
#define ARGUMENTO_INVALIDO	2

#define NUMERO_VALIDO_ARGS	2
#define MDC_INVALIDO		0

#define EOS			'\0'
/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{

  /*Caso o usuario digite menos ou mais que dois argumentos */
  if ( argc != NUMERO_VALIDO_ARGS )
  {
    printf ("\n\n%s: <Numero-errado-de-argumentos>\n", argv[0]); 
    printf ("Por favor insira dois numeros inteiros nao negativos\n\n");
    exit (NUMERO_INVALIDO_ARGS);
  }	

  byte indice = 0;
  /* Verifica se o primeiro argumento eh numerico */
  while ( argv[1][indice] != EOS ) 
  {
    if ( argv[1][indice] < '0' || argv[1][indice] > '9' ) 
    {
      printf ("\n\n%s: <Argumento-invalido>\n", argv[0]); 
      printf ("Por favor insira dois numeros inteiros nao negativos\n\n");
      exit (ARGUMENTO_INVALIDO);
    }
    indice++; 
  }

  byte termo = (byte) atoi (argv[1]); 
  indice = 0; 

  for ( indice = 0; indice <= termo; indice ++)
  { 
    printf ( "F (%hu) = %llu\n", indice, CalcularTermoSerieFibonacci(indice) ) ;
  } 

  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/

  return (OK);
}

