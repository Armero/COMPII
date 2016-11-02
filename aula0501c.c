/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/10/06 23:41:52 $
* $Log: aula0501c.c,v $
* Revision 1.1  2016/10/06 23:41:52  felipe
* Initial revision
*
* Revision 1.1  2016/09/30 00:25:32  felipe
* Initial revision
*
*/

#include "aula0501.h"
#include "aula0401.h"
#include <stdio.h>

float
CalcularSerieHarmonicaAlternada (unsigned long int termo)
{
  if ( termo == 0 )
    return ((float)0.0);
 
  double resultado, temp;

  resultado = 0;
  
  unsigned long int contador;
 
  for ( contador = termo; contador > 0; contador--)
  {
    temp = (float) ( (1.0) / (CalcularExponencial ((double) contador, (int) contador )) ); 

    if ( (contador % 2) == 0 )
     temp *= (-1.0); 

    resultado += temp;
  }
 
  return ( resultado );
}
