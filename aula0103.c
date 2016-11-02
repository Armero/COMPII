/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos
* $Author: felipe $
* $Date: 2016/09/13 00:10:11 $
* $Log: aula0103.c,v $
* Revision 1.2  2016/09/13 00:10:11  felipe
* O final do arquivo foi modificado
* Tambem foi colocado void como argumento
* da funcao main
*
* Revision 1.1  2016/09/11 03:09:33  felipe
* Initial revision
*
*/

#include<stdio.h>
#define OK 0

int main ( void )
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




  printf ("\n\nTipos basicos e modificadores de sinal\n");

  printf ("unsigned int:\n");
  printf ("\t\t%d\n", sizeof (unsigned int) );

  printf ("int unsigned:\n");
  printf ("\t\t%d\n", sizeof (int unsigned) );

  printf ("signed int:\n");
  printf ("\t\t%d\n", sizeof (signed int) );

  printf ("int signed:\n");
  printf ("\t\t%d\n", sizeof (int signed) );

  printf ("unsigned char:\n");
  printf ("\t\t%d\n", sizeof (unsigned char) );

  printf ("char unsigned:\n");
  printf ("\t\t%d\n", sizeof (char unsigned) );

  printf ("signed char:\n");
  printf ("\t\t%d\n", sizeof (signed char) );

  printf ("char signed:\n");
  printf ("\t\t%d\n", sizeof (char signed) );

/* Nao encontrei mais outros tipos possiveis - Esperava encontrar 10 tipos*/



  printf ("\n\nTipos Basicos e modificadores de largura\n");

  printf ("long int:\n");
  printf ("\t\t%d\n", sizeof (long int) );

  printf ("int long:\n");
  printf ("\t\t%d\n", sizeof (int long) );

  printf ("long long int:\n");
  printf ("\t\t%d\n", sizeof (long long int) );

  printf ("long int long:\n");
  printf ("\t\t%d\n", sizeof (long int long) );

  printf ("int long long:\n");
  printf ("\t\t%d\n", sizeof (int long long)  );

  printf ("short int:\n");
  printf ("\t\t%d\n", sizeof (short int) );

  printf ("int short:\n");
  printf ("\t\t%d\n", sizeof (int short) );

  printf ("long double:\n");
  printf ("\t\t%d\n", sizeof (long double) );

  printf ("double long:\n");
  printf ("\t\t%d\n", sizeof (double long) );

/* Nao encontrei mais outros tipos possiveis - Esperava encontrar 15 tipos*/



  printf ("\n\nModificadores de Sinal e modificadores de largura\n");

  printf ("long unsigned int:\n");
  printf ("\t\t%d\n", sizeof (long unsigned int) );

  printf ("long long unsigned int:\n");
  printf ("\t\t%d\n", sizeof (long long unsigned int) );

  printf ("long signed int:\n");
  printf ("\t\t%d\n", sizeof (long signed int) );

  printf ("long long signed int:\n");
  printf ("\t\t%d\n", sizeof (long long signed int) );

  printf ("short unsigned int:\n");
  printf ("\t\t%d\n", sizeof (short unsigned int) );

  printf ("short signed int:\n");
  printf ("\t\t%d\n", sizeof (short signed int) );


  printf ("\n\nCombinacoes Invalidas\n");

  printf ("long char\n");
  printf ("char long\n");
  printf ("long long char\n");
  printf ("char long long\n");
  printf ("long long  double\n");
  printf ("long double long\n");
  printf ("double long long\n");
  printf ("long float\n");
  printf ("long long  float\n");
  printf ("long float long\n");
  printf ("long long signed char\n");
  printf ("float long long\n");
  printf ("long void\n");
  printf ("long long void\n");
  printf ("\nvariacoes desses casos acima utilizando\
 signed e unsigned\n");
  printf ("\nCombinacoes sem sentido\n");
  printf  ("ex: long short");
  
  printf ("Mistura de tipos\n");
  printf ("ex: int double\n");  

  printf("\n\n\nResumo:\n");
  printf("\nchar, void e float nao podem ser combinados com\
 modificadores de largura\n");
  printf("\nSomente int pode ter modificadores de largura\
 combinados com modificadores de sinal\n");
  printf("\nvoid nao pode ser combinado com nada\n");
  printf("\nfloat e Double nao podem ser combinados\
 com modificadores de sinal\n");
  printf("\nchar e int podem ter seus sinais modificados\
 por um modificador de sinal\n"); 

  return (OK);
}
