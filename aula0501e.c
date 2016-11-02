/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/10/06 23:41:52 $
* $Log: aula0501e.c,v $
* Revision 1.1  2016/10/06 23:41:52  felipe
* Initial revision
*
* Revision 1.1  2016/09/30 00:25:32  felipe
* Initial revision
*
*/

#include "aula0501.h"
#include <math.h>

float
CalcularSerieHarmonicaAlternada (unsigned long int termo)
{
  if ( termo == 0 )
    return ((float)0.0);
 
  double resultado;

  resultado = (float) ( (1.0) / (pow ((double) termo, (int) termo )) ); 

  if ( (termo % 2) == 0 )
    return ( ((-1.0) * resultado) + CalcularSerieHarmonicaAlternada (termo - 1) );

  return ( resultado + CalcularSerieHarmonicaAlternada (termo - 1) );
}
