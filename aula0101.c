/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/09/10 22:52:19 $
* $Log: aula0101.c,v $
* Revision 1.1  2016/09/10 22:52:19  felipe
* Initial revision
*
*/

#include<stdio.h>
#define OK 0

int main ()
{
  printf ("int:\n");
  printf ("\t\t%d\n", sizeof (int) );

  printf ("char:\n");
  printf ("\t\t%d\n", sizeof (char) );

  printf ("float:\n");
  printf ("\t\t%d\n", sizeof (float) );

  printf ("double:\n");
  printf ("\t\t%d\n", sizeof (double) );

  printf ("void:\n");
  printf ("\t\t%d\n", sizeof (void) );

  return (OK);
}
