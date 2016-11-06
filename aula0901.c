/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/11/05 23:33:38 $
* $Log: aula0901.c,v $
* Revision 1.2  2016/11/05 23:33:38  felipe.santos
* Correcao do comentario
* Esta eh a implementacao das funcoes que codificam e decodificam em base 64
*
* Revision 1.1  2016/11/05 23:29:54  felipe.santos
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include "aula0901.h"
#include <stdio.h>

/*como a entrada pode ser qualquer combinacao de bits, nao ha o que tratar e 
o unico codigo de erro retornavel eh OK*/
tipoErros
CodificarBase64 (byte *entrada, unsigned numeroBytes, char *saida)
{
  /*mascaras utilizadas nas operacoes com os elementos do vetor*/
  byte mascara1, mascara2;

  mascara1 = 0X3F;
  saida[0] = CONJUNTO_BASE_64[ ((entrada[0] >> 2) & mascara1) ];
  
  mascara1 = 0X30;
  if ( numeroBytes > 1)
  	mascara2 = 0X0F;
  else
  	mascara2 = 0X00;

	saida[1] = CONJUNTO_BASE_64[ ((entrada[0] << 4) & mascara1) | ((entrada[1] >> 4) & mascara2) ];

  if ( numeroBytes > 2 )
  	mascara2 = 0X03;
  else
  	mascara2 = 0X00;

  mascara1 = 0X3C;
  saida[2] = CONJUNTO_BASE_64[ ((entrada[1] << 2) & mascara1) | ((entrada[2] >> 6) & mascara2) ];

  if ( numeroBytes == 3 )
  	mascara1 = 0x3F;
  else
  	mascara1 = 0x00;

  saida[3] = CONJUNTO_BASE_64[ (entrada[2] & mascara1) ];
  saida[4] = EOS;

  if ( numeroBytes < 3 )
  	saida[3] = '=';

  if ( numeroBytes < 2)
  	saida[2] = '=';

  return (OK);
}

/*como a entrada pode ser qualquer combinacao de bits, nao ha o que tratar e 
o unico codigo de erro retornavel eh OK*/
tipoErros
DecodificarBase64 (char *entrada, byte *saida, unsigned *numeroBytes)
{
	byte mascara1, mascara2, byte0, byte1, byte2, byte3;

	byte0 = DescobrirIndice  (entrada[0]);
	byte1 = DescobrirIndice  (entrada[1]);
	byte2 = DescobrirIndice  (entrada[2]);
	byte3 = DescobrirIndice  (entrada[3]);

	mascara1 = 0xFC;
	mascara2 = 0X03;
	saida[0] = ( (byte0 << 2) & (mascara1) ) | ( (byte1 >> 4) & mascara2 );

	if (*numeroBytes > 2)
	{
		mascara1 = 0XF0;
		mascara2 = 0X0F;
	}
	else
	{
		mascara1 = 0X00;
		mascara2 = 0X00;
	}

	saida[1] = ( ((byte1 << 4) & mascara1)  | ( (byte2 >> 2) & mascara2) );

	if (*numeroBytes > 3)
	{
		mascara1 = 0xC0;
		mascara2 = 0x3F;
	}
	else
	{
		mascara1 = 0;
		mascara2 = 0; 
	}

	saida[2] = ( ( (byte2 << 6) & mascara1) | (byte3 & mascara2) );

	/*finaliza a string*/
	saida[*numeroBytes] = EOS;
	return (OK);
}


byte
DescobrirIndice (byte elemento)
{
	if (elemento == '=')
		return (EOS);

	if (elemento == '\r')
		return (EOS);

	if (elemento == '\n')
		return (EOS);

	byte iterador = 0;
	while (elemento != CONJUNTO_BASE_64[iterador])
		iterador++;

	return (iterador);
}

/* $RCSfile: aula0901.c,v $ */
