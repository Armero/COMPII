/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/09/23 00:42:51 $
* $Log: aula0301b.c,v $
* Revision 1.1  2016/09/23 00:42:51  felipe.santos
* Initial revision
*
*/

#include "aula0301.h"

llu
CalcularTermoSerieFibonacci (byte termo)
{
  if ( termo <= 1 )
    return ( (llu) termo);
  
  byte contador = 2;
  llu anterior = 0, atual = 1, temporario;

  do
  {
    temporario = atual;
    atual += anterior; 
    anterior = temporario;
    contador++;
  }
  while ( contador <= termo );
  
  return ( atual ); 
}
