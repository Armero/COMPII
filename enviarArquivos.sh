#!/bin/bash

arquivos=*

#modificar este diretorio caso mude a pasta onde estou programando
diretorioLocal=/home/felipe/materias/6_periodoX/Computacao_II/private/EEL270/2016-2/Aulas-Praticas/$arquivos

diretorioRemoto=felipe.santos@loghost02.del.ufrj.br:/users/felipe.santos/private/EEL270/2016-2/Aulas-Praticas

scp -r $diretorioLocal $diretorioRemoto 
