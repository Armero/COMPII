/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/09/23 00:43:39 $
* $Log: aula0301c.c,v $
* Revision 1.1  2016/09/23 00:43:39  felipe.santos
* Initial revision
*
*/

#include "aula0301.h"

llu
CalcularTermoSerieFibonacci (byte termo)
{
  if ( termo <= 1 )
    return ( (llu) termo);
  
  byte contador;
  llu anterior = 0, atual = 1, temporario;

  for ( contador = 2; contador <= termo; contador++ )
  {
    temporario = atual;
    atual += anterior; 
    anterior = temporario;
  }
  
  return ( atual ); 
}
