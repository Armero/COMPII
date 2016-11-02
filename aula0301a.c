/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/09/23 00:42:01 $
* $Log: aula0301a.c,v $
* Revision 1.1  2016/09/23 00:42:01  felipe.santos
* Initial revision
*
*/

#include "aula0301.h"

llu
CalcularTermoSerieFibonacci (byte termo)
{
  if ( termo <= 1 )
    return ( (llu) termo);

  return( CalcularTermoSerieFibonacci (termo-1) +
          CalcularTermoSerieFibonacci (termo-2) );
}
