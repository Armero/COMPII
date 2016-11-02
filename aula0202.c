/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/09/16 02:37:30 $
* $Log: aula0202.c,v $
* Revision 1.1  2016/09/16 02:37:30  felipe
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include <stdlib.h>
#include <stdio.h>
#include "aula0201.h"

#define OK			0 
#define NUMERO_INVALIDO_ARGS	1	
#define ARGUMENTO_INVALIDO	2
#define NUMERO_VALIDO_ARGS	3
#define MDC_INVALIDO		0

#define EOS			'\0'	
/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define OK	0

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

  ULL indice = 0;
  /* Verifica se o primeiro argumento eh numerico */
  while ( argv[1][indice] != EOS ) 
  {
    if ( argv[1][indice] < '0' || argv[1][indice] > '9' ) 
    {
      printf ("\n\n%s: <Primeiro-argumento-invalido>\n", argv[0]); 
      printf ("Por favor insira dois numeros inteiros nao negativos\n\n");
      exit (ARGUMENTO_INVALIDO);
    }
    indice++; 
  }
  

  indice = 0;
  /* Verifica se o segundo argumento eh numerico */
  while ( argv[2][indice] != EOS ) 
  {
    if ( argv[2][indice] < '0' || argv[2][indice] > '9' ) 
    {
      printf ("\n\n%s: <Segundo-argumento-invalido>\n", argv[0]); 
      printf ("Por favor insira dois numeros inteiros nao negativos\n\n");
      exit (ARGUMENTO_INVALIDO);
    }
    indice++;
  }
  
  ULL valorX = (ULL) atoi( argv[1] );
  ULL valorY = (ULL) atoi( argv[2] );
  ULL mdc = CalcularMaximoDivisorComum (valorX, valorY) ;
  
  if ( mdc == 0 )
  {
    printf ("\n\n%s: <Argumentos-iguais-a-zero>\n", argv[0]); 
    printf("Por favor insira pelo menos um argumento diferente de zero\n\n");
    return (MDC_INVALIDO);
  }

  printf ( "\n\nO MDC entre %llu e %llu eh igual a:\n%llu\n\n",
         valorX, valorY, mdc );

  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/

  return (OK);
}

