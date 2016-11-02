/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/10/25 01:35:22 $
* $Log: aula0701.c,v $
* Revision 1.2  2016/10/25 01:35:22  felipe
* arrumados alguns bugs
*
* Revision 1.1  2016/10/22 15:09:02  felipe
* Initial revision
*
*/

#include "aula0701.h"

tipoErros
MostrarMonitor ( tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas)
{
  unsigned linhas, colunas;
  
  if ( (maximoLinhas > NUMERO_MAXIMO_LINHAS) || (maximoColunas > NUMERO_MAXIMO_COLUNAS) ) 		
    return (EXCEDE_LIMITES);


  system ("clear");
 
  for ( linhas = 0; linhas < maximoLinhas; linhas++)
  {
    for ( colunas = 0; colunas < maximoColunas; colunas++)
      printf ("%c", ( monitor[linhas][colunas] == aceso)? aceso:apagado);

    printf ("\n"); 
  }
  
  sleep (T_SLEEP);
 
  return (OK);
}

tipoErros
LimparMonitor ( tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                unsigned maximoLinhas, unsigned maximoColunas )
{
  unsigned linhas, colunas;

  if ( (maximoLinhas > NUMERO_MAXIMO_LINHAS) || (maximoColunas > NUMERO_MAXIMO_COLUNAS))
    return (EXCEDE_LIMITES);

  for ( linhas = 0; linhas < maximoLinhas; linhas++ )
    for ( colunas = 0; colunas < maximoColunas; colunas++ )
      monitor[linhas][colunas] = apagado;

  MostrarMonitor ( monitor, maximoLinhas, maximoColunas);
  return (OK);
}

tipoErros
DesenharRetangulo (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], 
                  unsigned maximoLinhas, unsigned maximoColunas, unsigned linhaCantoSuperiorEsquerdo,
                  unsigned colunaCantoSuperiorEsquerdo, unsigned linhaCantoInferiorDireito, 
                  unsigned colunaCantoInferiorDireito )
{
  int tamanhoLinhas, tamanhoColunas;
  unsigned linha, coluna;

  tamanhoLinhas = linhaCantoInferiorDireito - linhaCantoSuperiorEsquerdo;
  tamanhoColunas = colunaCantoInferiorDireito - colunaCantoSuperiorEsquerdo;

  /*caso onde o indice colocado eh 0*/
  if ( (!linhaCantoSuperiorEsquerdo) || (!colunaCantoSuperiorEsquerdo) )
    return (EXCEDE_LIMITES);

  if ( (tamanhoLinhas <= 0) || (tamanhoColunas <= 0) )
    return (TAMANHO_NEGATIVO);

  if ( (tamanhoLinhas > NUMERO_MAXIMO_LINHAS) || (tamanhoColunas > NUMERO_MAXIMO_COLUNAS) )
    return (POLIGONO_EXCEDE_LIMITES);

  linha = linhaCantoSuperiorEsquerdo - 1;

  for ( coluna = (colunaCantoSuperiorEsquerdo - 1); coluna < (colunaCantoInferiorDireito - 1); coluna ++ )
    monitor[linha][coluna] = (monitor[linha][coluna] == apagado)? aceso:monitor[linha][coluna];

  for ( ; linha < (linhaCantoInferiorDireito - 1) ; linha ++ )
    monitor[linha][coluna] = (monitor[linha][coluna] == apagado)? aceso:monitor[linha][coluna];

  for ( ; coluna > (colunaCantoSuperiorEsquerdo - 1); coluna-- )
    monitor[linha][coluna] = (monitor[linha][coluna] == apagado)? aceso:monitor[linha][coluna];

  for ( ; linha > (linhaCantoSuperiorEsquerdo - 1); linha-- )
    monitor[linha][coluna] = (monitor[linha][coluna] == apagado)? aceso:monitor[linha][coluna];

  MostrarMonitor ( monitor, maximoLinhas, maximoColunas);

  return (OK);
}

tipoErros
PreencherPoligono ( tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS],
            unsigned maximoLinhas, unsigned maximoColunas, unsigned linha, unsigned coluna)
{
  /*utilizando como se fosse uma variavel booleana*/
  unsigned char modificado = 0;

  if( (linha  > maximoLinhas) || (coluna > maximoColunas) )
    return (PONTO_FORA_DOS_LIMITES);

  if (monitor[linha][coluna] == aceso)
    return (OK);

  if ( (linha < maximoLinhas) && (coluna < maximoColunas) )
  {
    modificado = (monitor[linha][coluna] == apagado)? 1:0;
    monitor[linha][coluna] = (monitor[linha][coluna] == apagado)? aceso:monitor[linha][coluna];
    
    /*So mostra o monitor se o valor for modificad*/
    if (modificado)
      MostrarMonitor ( monitor, maximoLinhas, maximoColunas);
  }

  /*caso onde a linha eh 0*/
  if (linha)
    PreencherPoligono ( monitor, maximoLinhas, maximoColunas, (linha - 1), coluna ); 
  
  /*Chega ate a maximoLinhas - 1*/
  if (linha < (maximoLinhas - 2))
    PreencherPoligono ( monitor, maximoLinhas, maximoColunas, (linha + 1), coluna );

  /*caso onde a coluna eh 0*/
  if (coluna)
    PreencherPoligono ( monitor, maximoLinhas, maximoColunas, linha, (coluna - 1) ); 
  
  /*Chega ate a maximoColunas - 1*/
  if (linha < (maximoLinhas - 2))
    PreencherPoligono ( monitor, maximoLinhas, maximoColunas, linha, (coluna + 1) );

  return (OK);
}


