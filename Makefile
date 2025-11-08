################################
#		Pontificia Universidad Javeriana
#Autor: David Tobar Artunduaga
#Materia : Sistemas Operativos
#Fichero: Automatización de Compilación
##############################################

GCC =gcc
FLAGS = -lm -fopenmp

PROGRAMAS = labomp01 labomp02 labomp03 labomp04 labomp05 labomp06

all: $(PROGRAMAS)

labomp01:
	$(GCC) $@.c -o $@ $(FLAGS)
labomp02:
	$(GCC) $@.c -o $@ $(FLAGS)
labomp03:
	$(GCC) $@.c -o $@ $(FLAGS)
labomp04:
	$(GCC) $@.c -o $@ $(FLAGS)
labomp05:
	$(GCC) $@.c -o $@ $(FLAGS)
labomp06:
	$(GCC) $@.c -o $@ $(FLAGS)
clean:
	$(RM) $(PROGRAMAS)
