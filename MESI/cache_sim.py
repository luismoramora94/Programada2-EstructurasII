#UNIVERSIDAD DE COSTA RICA
#ESCUELA DE INGENERIA ELECTRICA
#---------------------------------------------------
#CURSO: Estructuras de computadores digitales 2
#Tarea 2: simulacion de un cache multinivel
#Alumnos:
#Mario A. Castresana
#Luis F. Mora
#Luis Alvarado


#imports
import CPU
import cache
import block

#inicializamos los caches de cada CPU y el cache compartido L2
cacheL1_cpu0 = cache.cache()    #cache de nivel 1 CPU0
cacheL1_cpu1 = cache.cache()    #cache de nivel 1 CPU1
cacheL2 = cache.cache()         #cache compartido L2

# inicializar CPUs
CPU0 = CPU.CPU(cacheL1_cpu0, cacheL2)
CPU1 = CPU.CPU(cacheL1_cpu1, cacheL2)

# segmento de codigo para parsear el archivo .trace
trace = open('prueba.trace', 'r')

#iteramos sobre todo el archivo, usando la i para cambiar entre instrucciones
#pares e impares
i=1

for line in trace.readlines():
    if i%2 == 0:
        print"CPU1 ejecutando: ", line
        CPU1.fetch(line)
    else:
        print"CPU0 ejecutando: ", line
        CPU0.fetch(line)
    i+=1

#liberar la memoria
trace.close()
