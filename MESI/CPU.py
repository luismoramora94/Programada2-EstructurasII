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
        entrada = Block(instruction[0], instruction[1], False, False, False, False)

    def snoop(self, cacheL1, cacheL2, block, Write=True):
        #esta funcion actua como monitor del bus revisando si un bloque
        #ya pertenece a otro cache y marca las banderas MESI como debe ser
        if Write:
            #busca en otro $ L1 y si esta marca bloque como invalid
            if cacheL1.search(block):
                block.invalid(True)
                cacheL1.write(block)
            #igual para $ L2
            elif cacheL2.search(block):
                block.invalid(True)
                cacheL2.write(block)
            else:
                pass
        else:
            if cacheL1.search(block):
                block.shared(True)
                cacheL1.write(block)
            elif cacheL2.search(block):
                block.shared(True)
                cacheL2.write(block)
            else:
                pass
