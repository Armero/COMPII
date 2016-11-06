/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/11/05 23:29:54 $
* $Log: aula0902.c,v $
* Revision 1.1  2016/11/05 23:29:54  felipe.santos
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include "aula0901.h"
#include <stdlib.h>
#include <stdio.h>


/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define EOS			'\0'


/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{
  /*Vetor com o conteudo introduzido por linha de comando*/
  byte entrada[TAMANHO_CONTEUDO];
  char saida[TAMANHO_TOTAL + 3]; /* Espaco para \r\n\0 */ 
  char textoTemporario [TAMANHO_CONTEUDO + 2]; /*um byte a mais + EOS*/
  byte contadorAuxiliar;
  unsigned numeroBytes;
  int numIteracoes, indice, temporario;
  tipoErros status;
  saida[0] = EOS; /*inicializando saida com EOS na primeira posicao para evitar caracteres nao esperados*/
  
  /*Caso tenha mais ou menos argumentos que NUMERO_ARGUMENTOS_INVALIDOS*/
  if ( argc != NUMERO_ARGUMENTOS_VALIDOS)
  {
    printf ("Uso %s: <numero-de-argumentos-invalidos>\n", argv[0]);
    printf ("Por favor insira: <texto-a-ser-codificado>\n");
    exit(NUMERO_ARGUMENTOS_INVALIDOS);
  }

  numIteracoes = (byte) strlen(argv[1]);
  
  printf ("Resultado:\n");
  indice = 0;
  contadorAuxiliar = 3; /* Comeca com 3, pois de qualquer forma a entrada sera representada como 3 caracteres */
  while (indice < numIteracoes)
  {

    /* Caso onde eh possivel completar um grupo de 3 bytes */
    if ( (numIteracoes - indice) > 3)
    {
      numeroBytes = 3;
      entrada[0] = argv[1][indice];
      entrada[1] = argv[1][indice + 1];
      entrada[2] = argv[1][indice + 2];

      status = CodificarBase64 (entrada, numeroBytes, textoTemporario);
      contadorAuxiliar += 1; /*quarto bit*/
      strcat (saida, textoTemporario); /*concatena o resultado obtido*/

      /* + 1 devido ao EOS que e concatenado tambem */
      if ( ( (contadorAuxiliar + 1) == TAMANHO_TOTAL) || ( (contadorAuxiliar + 1) > TAMANHO_TOTAL) )
      {
        strcat (saida, "\r\n");
        if (status == OK)
          printf ("%s",saida);

        /*zera o contador para que so seja colocado \r\n depois de mais 76 caracteres*/
        contadorAuxiliar = 0;
        saida[0] = EOS;
      }
    }

    /* Caso onde nao eh completado um grupo de 3 bytes */
    else if ( (indice - numIteracoes)  < TAMANHO_TOTAL )
    {
      for (temporario = (numIteracoes - indice); temporario >= 0; temporario-- )
        entrada[temporario] = argv[1][indice + temporario];

      numeroBytes = (byte)(numIteracoes - indice);
      status = CodificarBase64 (entrada, numeroBytes, textoTemporario);
      strcat (saida, textoTemporario);
      strcat(saida, "\r\n");
      
      if (status == OK)
        printf ("%s",saida);
    }
    indice += 3;
    contadorAuxiliar += 3;
  }

  
  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/
  return (OK);
} 
/* $RCSfile: aula0902.c,v $ */
