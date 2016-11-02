/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/10/14 00:37:07 $
* $log$
*/

/*Espaco reservado para os includes*/

#include <stdlib.h>
#include <stdio.h>
#include "aula0601.h"

/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define OK			0 
#define NUMERO_INVALIDO_ARGS	1	
#define ARGUMENTO_INVALIDO	2

#define NUMERO_VALIDO_ARGS	(LINHAS_MATRIZA * COLUNAS_MATRIZA + LINHAS_MATRIZB * COLUNAS_MATRIZB  + 1)				
#define EOS			'\0'

/*Fim do espaco reservado para definir as macros*/

	int
main ( int argc, char *argv[] )
{

  byte indice;
  byte tempLinha,tempColuna; 
  float matrizA [LINHAS_MATRIZA][COLUNAS_MATRIZA];
  float matrizB [LINHAS_MATRIZB][COLUNAS_MATRIZB];
  float matrizResultado [LINHAS_MATRIZA][COLUNAS_MATRIZB];
  float convertido;
  char *verificacao = NULL;


  /*Caso o usuario digite menos ou mais que dois argumentos */
  if ( argc != NUMERO_VALIDO_ARGS )
  {
    printf ("\n\nUso: %s <Numero-errado-de-argumentos>\n", argv[0]); 
    printf ("Por favor insira inteiros no formato: <a11> <a12> <a13> <a21> ... <b31> <b32> <b33> <b34> \n\n");
    exit (NUMERO_INVALIDO_ARGS);
  }	

  for ( indice = 0; indice < (argc - 1); indice++ )
  {
    convertido = strtof (argv[indice + 1], &verificacao); 
    if ( *verificacao != EOS ) 
    {
      printf("Argumento %d invalido. Valor: %s\n", indice + 1, argv[indice + 1]);
      printf ("Por favor insira inteiros no formato: <a11> <a12> <a13> <a21> ... <b31> <b32> <b33> <b34> \n\n");
      exit (ARGUMENTO_INVALIDO);
    }

    if ( indice < (LINHAS_MATRIZA * COLUNAS_MATRIZA) )
    {
      tempLinha = (byte) ((indice)/(COLUNAS_MATRIZA));
      tempColuna = (byte) ( (indice) % (COLUNAS_MATRIZA) );
      matrizA[tempLinha][tempColuna] = convertido;
    }

    else
    {
      tempLinha = (byte) ( (indice - (LINHAS_MATRIZA * COLUNAS_MATRIZA) ) / COLUNAS_MATRIZB );
      tempColuna = (byte) ( (indice - (LINHAS_MATRIZA * COLUNAS_MATRIZA) ) % COLUNAS_MATRIZB );
      matrizB[tempLinha][tempColuna] = convertido;
    }
  }  

  printf ("Matriz A:\n");
  MostrarMatriz ( LINHAS_MATRIZA, COLUNAS_MATRIZA, matrizA );

  printf ("Matriz B:\n");
 
  MostrarMatriz ( LINHAS_MATRIZB, COLUNAS_MATRIZB, matrizB );
  
  MultiplicarMatrizes ( matrizA, matrizB, matrizResultado );

  printf ("Matriz Resultado:\n");
  MostrarMatriz ( LINHAS_MATRIZA, COLUNAS_MATRIZB, matrizResultado );

  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/
  return (OK);
}

