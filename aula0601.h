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


#ifndef _aula0601_
#define _aula0601_ "@(#)aula0601.h$revisions$"

  #define LINHAS_MATRIZA		5
  #define COLUNAS_MATRIZA		3

  #define LINHAS_MATRIZB		3
  #define COLUNAS_MATRIZB		4
  
  typedef	unsigned char		byte;
  
  void
  MultiplicarMatrizes ( float matrizA [LINHAS_MATRIZA][COLUNAS_MATRIZA],
                        float matrizB [LINHAS_MATRIZB][COLUNAS_MATRIZB],
                        float matrizResultado[LINHAS_MATRIZA][COLUNAS_MATRIZB]);

  void MostrarMatriz  (byte linhas, byte colunas, float matriz[linhas][colunas]);
 
#endif
