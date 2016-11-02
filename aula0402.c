/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/09/30 00:27:00 $
* $Log: aula0402.c,v $
* Revision 1.1  2016/09/30 00:27:00  felipe
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include <stdlib.h>
#include <stdio.h>
#include "aula0401.h"
/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define OK			0 
#define NUMERO_INVALIDO_ARGS	1	
#define ARGUMENTO_INVALIDO	2

#define NUMERO_VALIDO_ARGS	3
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
    printf ("Por favor insira um numero real como primeiro argumento e um inteiro como segundo argumento\n para calcular y(real) ^ x (inteiro) \n\n");
    exit (NUMERO_INVALIDO_ARGS);
  }	

  byte indice = 0;
  unsigned charPonto = 0;
  
  
  if ( (argv[1][0]) == '-' )
    indice = 1;
  /* Verifica se o primeiro argumento eh numerico */
  while ( argv[1][indice] != EOS ) 
  {
    if( (charPonto <= 1) && ((argv[1][indice]) == '.' ) )
      indice++; 

    if ( ( argv[1][indice] < '0' ) || ( argv[1][indice] > '9' ) ) 
    {
        printf ("Aqui 1\n");
        printf ("\n\n%s: <Argumento-invalido>\n", argv[0]); 
        printf ("Por favor insira um numero real como\
 primeiro argumento e um inteiro como\
 segundo argumento\n para calcular y(real) ^ x (inteiro) \n\n");
        exit (ARGUMENTO_INVALIDO);
    } 
    indice++; 
  }

  indice = 0;
  if ( (argv[2][0]) == '-' )
  {
    indice = 1;
  }
  while ( argv[2][indice] != EOS ) 
  {
    if ( ( argv[2][indice] < '0' )  || ( argv[2][indice] > '9' ) )  
    {
      printf ("Aqui 2\n");
      printf ("\n\n%s: <Argumento-invalido>\n", argv[0]); 
      printf ("Por favor insira um numero real como primeiro argumento e um inteiro como segundo argumento\n para calcular y(real) ^ x (inteiro) \n\n");
      exit (ARGUMENTO_INVALIDO);
    }
    indice++; 
  }

  double base = atof (argv[1]); 
  int expoente = atoi (argv[2]); 

  printf ( "\n%f ^ %d = %.10Lf\n", base, expoente , CalcularExponencial ( base, expoente) ) ;

  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/

  return (OK);
}

