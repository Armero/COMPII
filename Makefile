#Universidade Federal do Rio de Janeiro
#Escola Politecnica
#Departamento de Eletronica e de Computacao
#EEL270 - Computacao II - Turma 2016/2
#Prof. Marcelo Luiz Drumond Lanza
#Autor: Felipe Claudio da Silva Santos
#
#$Author: felipe $
#$Date: 2016/10/22 15:10:30 $ 
#$Log: Makefile,v $
#Revision 1.13  2016/10/22 15:10:30  felipe
#Aula07 adicionada e funcionando
#
#Revision 1.12  2016/10/14 00:37:07  felipe.santos
#Makefile com a aula 6 e erro no nome da macro consertado
#
#Revision 1.11  2016/10/06 23:41:52  felipe
#Makefile gerando as bibliotecas e executaveis de maneira correta
#
#Revision 1.10  2016/09/30 00:27:56  felipe
#Aula04 implementada e funcionando
#,
#
#Revision 1.9  2016/09/23 00:40:48  felipe.santos
#Makefile com todos os arquivos da aula 3 funcionando
#
#Revision 1.8  2016/09/16 03:40:52  felipe
#Makefile com o executavel aula0202d
#
#Revision 1.7  2016/09/16 03:32:35  felipe
#Adicionado o executavel de aula0202c
#
#Revision 1.6  2016/09/16 03:17:47  felipe
#Adicionado o executavel com
#o do while
#
#Revision 1.5  2016/09/16 02:35:17  felipe
#Adicionados os objetivos
#aula02 e aula0202a
#
#Revision 1.4  2016/09/13 00:11:02  felipe
#Check de rotina
#
#Revision 1.3  2016/09/10 22:54:47  felipe
#Aula01 consertado,
#tudo ok
#
#Revision 1.2  2016/09/10 21:59:35  felipe
#Divisao entre aula01 e aula0101 como pedido no relatorio
#
#Revision 1.1  2016/09/10 21:54:35  felipe
#Initial revision
#


#CC = O compilador utilizado
#LD = O linkeditor utilizado
#AR = compila a biblioteca
CC = gcc
LD = gcc
AR = ar

#CFLAGS = as flags utilizadas pelo compilador
#LFLAGS = as flags utilazadas pelo linkeditor
#AFLAGS = as flags utilazadas pelo compilador de bibliotecas
CFLAGS = -Wall
LFLAGS = -Wall
AFLAGS = -l

ALL = $(EXECS)\
      $(LIBS)

#Nome dos executaveis
EXECS = $(EXECSAULA01)\
        $(EXECSAULA02)\
        $(EXECSAULA03)\
        $(EXECSAULA04)\
        $(EXECSAULA05)\
        $(EXECSAULA06)\
        $(EXECSAULA07)\
		$(EXECSAULA07)\
		$(EXECSAULA08)

OBJS = $(AULA01OBJS)\
       $(AULA02OBJS)\
       $(AULA03OBJS)\
       $(AULA04OBJS)\
       $(AULA05OBJS)\
       $(AULA06OBJS)\
       $(AULA07OBJS)\
       $(AULA08OBJS)

LIBS = libmatematica.a

EXECSAULA01 = aula0101\
              aula0102\
              aula0103

EXECSAULA02 = aula0202a\
              aula0202b\
              aula0202c\
              aula0202d

EXECSAULA03 = aula0302a\
              aula0302b\
              aula0302c\
              aula0302d

EXECSAULA04 = aula0402a\
              aula0402b\
              aula0402c\
              aula0402d

EXECSAULA05 = aula0502a\
              aula0502b\
              aula0502c\
              aula0502d\
              aula0502e

EXECSAULA06 = aula0602

EXECSAULA07 = aula0702

EXECSAULA08 = aula0802a\
			  aula0802b\
			  aula0803a\
			  aula0803b\
			  aula0805a\
			  aula0805b\
			  aula0806a\
			  aula0806b

#nome dos .objs
AULA01OBJS = $(AULA01010BJS)\
			 $(AULA01020BJS)\
			 $(AULA01030BJS)

AULA02OBJS = $(AULA0202AOBJS)\
			 $(AULA0202BOBJS)\
			 $(AULA0202COBJS)\
			 $(AULA0202DOBJS)


AULA03OBJS = $(AULA0302AOBJS)\
			 $(AULA0302BOBJS)\
			 $(AULA0302COBJS)\
			 $(AULA0302DOBJS)


AULA04OBJS = $(AULA0402AOBJS)\
			 $(AULA0402BOBJS)\
			 $(AULA0402COBJS)\
			 $(AULA0402DOBJS)

AULA05OBJS = $(AULA0502AOBJS)\
             $(AULA0502BOBJS)\
             $(AULA0502COBJS)\
             $(AULA0502DOBJS)\
             $(AULA0502EOBJS)


AULA06 = $(AULA0602AOBJS)

AULA07 = $(AULA0702AOBJS)

AULA08 = $(AULA0802AOBJS)\
		 $(AULA0802BOBJS)\
		 $(AULA0803AOBJS)\
		 $(AULA0803BOBJS)\
		 $(AULA0805AOBJS)\
		 $(AULA0805BOBJS)\
		 $(AULA0806AOBJS)\
		 $(AULA0806BOBJS)

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o

AULA0202AOBJS = aula0201a.o aula0202.o 
AULA0202BOBJS = aula0201b.o aula0202.o 
AULA0202COBJS = aula0201c.o aula0202.o 
AULA0202DOBJS = aula0201d.o aula0202.o 

AULA0302AOBJS = aula0301a.o aula0302.o 
AULA0302BOBJS = aula0301b.o aula0302.o 
AULA0302COBJS = aula0301c.o aula0302.o 
AULA0302DOBJS = aula0301d.o aula0302.o 

AULA0402AOBJS = aula0401a.o aula0402.o 
AULA0402BOBJS = aula0401b.o aula0402.o 
AULA0402COBJS = aula0401c.o aula0402.o 
AULA0402DOBJS = aula0401d.o aula0402.o 

AULA0502AOBJS = aula0501a.o aula0502.o 
AULA0502BOBJS = aula0501b.o aula0502.o 
AULA0502COBJS = aula0501c.o aula0502.o 
AULA0502DOBJS = aula0501d.o aula0502.o 
AULA0502EOBJS = aula0501e.o aula0502.o 

AULA0602OBJS = aula0601.o aula0602.o 

AULA0702OBJS = aula0701.o aula0702.o

AULA0802AOBJS = aula0801.o aula0802a.o  
AULA0802BOBJS = aula0801.o aula0802b.o
AULA0803AOBJS = aula0801.o aula0803a.o  
AULA0803BOBJS = aula0801.o aula0803b.o
AULA0805AOBJS = aula0804.o aula0805a.o  
AULA0805BOBJS = aula0804.o aula0805b.o
AULA0806AOBJS = aula0804.o aula0806a.o  
AULA0806BOBJS = aula0804.o aula0806b.o

LIBS = $(LIBMATEMATICA)\
       $(LIBMATHC)

LIBMATEMATICA = libmatematica.a
LIBMATHC = m.a


LIBSOBJS = $(LIBMATEMATICAOBJS)\
           $(LIBMATHOBJS)

LIBMATEMATICAOBJS = aula0401a.o 
LIBMATHOBJS = m.o 


#Regra implicita
.c.o:
	$(CC)	$(CFLAGS)	-c	$<

#Regra geral
#O $@ chama todos os .o necessarios paraera o executavel correspondentes
all:	$(ALL)

#Regra para gerar todos os executaveis da aula 1
aula01:	$(EXECSAULA01)

#Regras para gerar somente um executavel
aula0101:	$(AULA0101OBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0101OBJS)

aula0102:	$(AULA0102OBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0102OBJS)

aula0103:	$(AULA0103OBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0103OBJS)



#Regra para gerar todos os executaveis da aula 2
aula02:	$(EXECSAULA02)

#Regras para gerar somente um executavel
aula0202a:	$(AULA0202AOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0202AOBJS)

aula0202b:	$(AULA0202BOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0202BOBJS)

aula0202c:	$(AULA0202COBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0202COBJS)

aula0202d:	$(AULA0202DOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0202DOBJS)


#Regra para gerar todos os executaveis da aula 3
aula03:	$(EXECSAULA03)

#Regras para gerar somente um executavel
aula0302a:	$(AULA0302AOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0302AOBJS)

aula0302b:	$(AULA0302BOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0302BOBJS)

aula0302c:	$(AULA0302COBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0302COBJS)

aula0302d:	$(AULA0302DOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0302DOBJS)

#Regra para gerar todos os executaveis da aula 4
aula04:	$(EXECSAULA04)

#Regras para gerar somente um executavel
aula0402a:	$(AULA0402AOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0402AOBJS)

aula0402b:	$(AULA0402BOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0402BOBJS)

aula0402c:	$(AULA0402COBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0402COBJS)

aula0402d:	$(AULA0402DOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0402DOBJS)


#Regra para gerar todos os executaveis da aula 5
aula05:	$(EXECSAULA05)

#Regras para gerar somente um executavel
aula0502a:	$(AULA0502AOBJS)	$(LIBMATEMATICA)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0502AOBJS)	$(LIBMATEMATICAOBJS)	-L. -lmatematica	

aula0502b:	$(AULA0502BOBJS)	$(LIBMATEMATICA)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0502BOBJS)	$(LIBMATEMATICAOBJS)	-L. -lmatematica	

aula0502c:	$(AULA0502COBJS)	$(LIBMATEMATICA)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0502COBJS)	$(LIBMATEMATICAOBJS)	-L. -lmatematica	

aula0502d:	$(AULA0502DOBJS)	$(LIBMATEMATICA)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0502DOBJS)	$(LIBMATEMATICAOBJS)	-L. -lmatematica	

aula0502e:	$(AULA0502EOBJS)	$(LIBMATHC)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0502EOBJS)	$(LIBMATHCOBJS)	-lm	


#Regra para gerar todos os executaveis da aula 5
aula06:	$(EXECSAULA06)

#Regras para gerar somente um executavel
aula0602:	$(AULA0602OBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0602OBJS)

#Regra para gerar todos os executaveis da aula 5
aula07:	$(EXECSAULA07)

#Regras para gerar somente um executavel
aula0702:	$(AULA0702OBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0702OBJS)

#Regra para gerar todos os executaveis da aula 5
aula08:	$(EXECSAULA08)

#Regras para gerar somente um executavel
aula0802a:	$(AULA0802AOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0802AOBJS)
	
aula0802b:	$(AULA0802BOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0802BOBJS)	

aula0803a:	$(AULA0803AOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0803AOBJS)	
	
aula0803b:	$(AULA0803BOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0803BOBJS)	

aula0805a:	$(AULA0805AOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0805AOBJS)	
	
aula0805b:	$(AULA0805BOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0805BOBJS)	

aula0806a:	$(AULA0806AOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0806AOBJS)	
	
aula0806b:	$(AULA0806BOBJS)	
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0806BOBJS)	
		
#Objetivos das libs
$(LIBMATEMATICA):	$(LIBMATEMATICAOBJS)
	$(AR)	-r	$@	$(LIBMATEMATICAOBJS)

$(LIBMATHC):	$(LIBMATEMATHC)
	$(AR)	-r	$@	$(LIBMATEMATHC)

#Limpa a pasta
clean:
	rm -f *.o $(EXECS) $(OBJS) $(LIBS) $(LIBSOBJS)

# $RCSfile: Makefile,v $
