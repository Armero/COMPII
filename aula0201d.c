/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/09/18 22:52:47 $
* $Log: aula0201d.c,v $
* Revision 1.2  2016/09/18 22:52:47  felipe.santos
* Removida linha desnecessaria no codigo
*
* Revision 1.1  2016/09/16 03:41:16  felipe
* Initial revision
*
* Revision 1.1  2016/09/16 03:30:47  felipe
* Initial revision
*
*/

#include "aula0201.h"

#define VALORES_ZERO	0

ULL
CalcularMaximoDivisorComum (ULL valorX, ULL valorY)
{
  /* devera retornar inf */
  if ( (valorX == 0) && (valorY == 0 ) )
    return (VALORES_ZERO);

  if ( valorX == 0 )
    return (valorY);

  if ( valorY == 0 )
    return (valorX);
  
  if ( valorY > valorX )
  {
    ULL temp = valorX;
    valorX = valorY;
    valorY = temp; 
  }
 
  ULL resto = valorX % valorY;  

  if ( resto == 0 )
    return (valorY);
  
  while ( resto != 0 )
  {
    resto = valorX % valorY;
    valorX = valorY;
    valorY = resto; 
  }

  return(valorX);
}

