/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/09/30 00:25:32 $
* $Log: aula0401c.c,v $
* Revision 1.1  2016/09/30 00:25:32  felipe
* Initial revision
*
*/

#include "aula0401.h"
#include <stdio.h>

long double
CalcularExponencial (double base, int expoente)
{
  if (expoente == 0)
    return (1.0);

  if ( (base == 0.0) && (expoente < 0) )
    return (INFINITO);

  if (base == 0.0)
    return (0.0);

  int expAux = expoente;
  long double baseAux = (1.0/base);  
  long double resultado = baseAux;
 
  if ( expoente < 0 )
  { 
    for ( ; expAux < -1 ; expAux++ )
    {
      resultado *= baseAux;
      printf ("ExpAux1: %d Resultado: %Lf\n", expAux , (long double) ( resultado));
    } 

    return( (long double) (resultado) );
  }
  
  baseAux = base; 
  resultado = base;
  for ( ; expAux > 1; expAux-- ) 
  {
    resultado *= baseAux;
  } 

  return( (long double) (resultado) );
}
