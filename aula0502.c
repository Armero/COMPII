/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/10/06 23:41:52 $
* $Log: aula0502.c,v $
* Revision 1.1  2016/10/06 23:41:52  felipe
* Initial revision
*
* Revision 1.1  2016/09/23 00:45:39  felipe.santos
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include <stdlib.h>
#include <stdio.h>
#include "aula0501.h"

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
    printf ("Por favor insira um numero inteiro nao negativo\n\n");
    exit (NUMERO_INVALIDO_ARGS);
  }	

  unsigned long int indice = 0;
  /* Verifica se o primeiro argumento eh numerico */
  while ( argv[1][indice] != EOS ) 
  {
    if ( argv[1][indice] < '0' || argv[1][indice] > '9' ) 
    {
      printf ("\n\n%s: <Argumento-invalido>\n", argv[0]); 
      printf ("Por favor insira um numero inteiro nao negativos\n\n");
      exit (ARGUMENTO_INVALIDO);
    }
    indice++; 
  }

  unsigned long int termo = (unsigned long int) atoi (argv[1]); 

  printf("termo: %lu\n", termo);
  for ( indice = 0; indice <= termo; indice++ )
  { 
    printf ( "S (%lu) = %1.15f\n", indice, CalcularSerieHarmonicaAlternada (indice) ) ;
  } 

  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/

  return (OK);
}

