/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/09/30 00:25:32 $
* $Log: aula0401a.c,v $
* Revision 1.1  2016/09/30 00:25:32  felipe
* Initial revision
*
*/

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{
  if (expoente == 0)
    return (1.0);

  if ( (base == 0.0) && (expoente < 0) )
    return (INFINITO);

  if ( (expoente < 0) && (base != 0.0) )
    return ( (long double)( (1.0/base) * (CalcularExponencial (base, (expoente + 1)))) );
  
  return ( (long double)( (base) * (CalcularExponencial (base, (expoente - 1)))) );

}
