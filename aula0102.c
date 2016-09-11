/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/09/10 22:54:05 $
* $Log: aula0102.c,v $
* Revision 1.1  2016/09/10 22:54:05  felipe
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

  printf ("\n\nModificadores de Sinal combinados com\
 Modificadores de Largura\n");

  printf ("Unsigned long:\n");
  printf ("\t\t%d\n", sizeof (unsigned long) );

  printf ("Unsigned short:\n");
  printf ("\t\t%d\n", sizeof (unsigned short) );

  printf ("Signed long:\n");
  printf ("\t\t%d\n", sizeof (signed long) );

  printf ("Signed short:\n");
  printf ("\t\t%d\n", sizeof (signed short) );
  
  printf ("Unsigned long long:\n");
  printf ("\t\t%d\n", sizeof (unsigned long long) );

  printf ("Signed long long:\n");
  printf ("\t\t%d\n", sizeof (signed long long) );

  return (OK);
}
