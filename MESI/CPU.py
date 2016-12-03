import cache
from block import Block

class CPU:
    def __init__(self, cacheL1, cacheL2):
        self.cacheL1 = cacheL1
        self.cacheL2 = cacheL2

    def fetch(self, line):
        #tomamos la instruccion del .trace y la parseamos
        instruction = line.split("    ")
        print(" fetching instruction: " + instruction[0] + " mode: " + instruction[1])
        # creamos un bloque generico de entrada que es usado en cada iteracion
        # con los argumentos address(instruction[0]), mode(instruction[1]), M, E, S, I
        bloqueMem = Block(instruction[0], instruction[1], False, False, False, False)
        if self.cacheL1.search(bloqueMem):
            #encuentra la entrada en el cache L1? es un hit
            self.cacheL1.hits += 1
        else:
            #si no lo encuentra en L1 sume un miss y agreguelo a L1
            self.cacheL1.misses += 1
            self.cacheL1.add_entry(bloqueMem)
            #repita el mismo proceso para el nivel 2 de cache
            if self.cacheL2.search(bloqueMem):
                self.cacheL2.hits += 1
            else:
                self.cacheL2.misses += 1
                self.cacheL2.add_entry(bloqueMem)


    def snoop(self, cacheL1, cacheL2, line):
        #esta funcion actua como monitor del bus revisando si un bloque
        #ya pertenece al cache L1 del otro CPU y marca las banderas MESI
        #como debe ser

        #parsear linea del .trace
        instruction = line.split("    ")
        bloqueMem = Block(instruction[0], instruction[1], False, False, False, False)
        #busquemos este bloque en los otros caches L1 y L2 a ver si esta

        if bloqueMem.mode == 'S\n':
            #busca en otro $ L1 y si esta marca bloque como invalid
            if cacheL1.search(bloqueMem):
                bloqueMem.invalid(True)
                cacheL1.add_entry(bloqueMem)
            #igual para $ L2
            elif cacheL2.search(bloqueMem):
                bloqueMem.invalid(True)
                cacheL2.add_entry(bloqueMem)
            else:
                pass
        else:
            if cacheL1.search(bloqueMem):
                bloqueMem.shared(True)
                cacheL1.add_entry(bloqueMem)
            elif cacheL2.search(bloqueMem):
                bloqueMem.shared(True)
                cacheL2.add_entry(bloqueMem)
            else:
                pass
