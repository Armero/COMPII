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

#include "aula0601.h"
#include <stdio.h>

void
MultiplicarMatrizes ( float matrizA [LINHAS_MATRIZA][COLUNAS_MATRIZA],
                      float matrizB [LINHAS_MATRIZB][COLUNAS_MATRIZB],
                      float matrizResultado[LINHAS_MATRIZA][COLUNAS_MATRIZB])
{
  byte linha, coluna, indice;
  
  for ( linha = 0; linha <  LINHAS_MATRIZA; linha++)
    for ( coluna = 0; coluna <  COLUNAS_MATRIZB; coluna++)
      matrizResultado[linha][coluna] = 0.0;

  for ( linha = 0; linha <  LINHAS_MATRIZA; linha++)
    for ( coluna = 0; coluna <  COLUNAS_MATRIZB; coluna++)
      for ( indice = 0; indice <  COLUNAS_MATRIZA; indice++)
        matrizResultado[linha][coluna] += matrizA[linha][indice] * matrizB[indice][coluna]; 
}

void 
MostrarMatriz  (byte linhas, byte colunas, float matriz[linhas][colunas])

{
  byte linha, coluna;
  for ( linha = 0; linha < linhas; linha ++ )
  {
    for ( coluna = 0; coluna < colunas; coluna ++ )
      printf("%-1.2f\t", matriz[linha][coluna]);
    
    printf("\n"); 
  }     
  printf("\n\n");
}
