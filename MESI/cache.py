import block

class cache:
    def __init__(self):
        #diccionario que contiene los datos del cache
        self.cache = {}
        self.hits = 0
        self.misses = 0

    def print_cache(self, CPU_number):
        log = open('logfile', 'a')
        log.write('\n--- Log de instrucciones para ' + CPU_number + '---\n')
        for (address, block) in self.cache.items():
            with open('logfile', 'a') as log:
                banderas = ' M= '+ str(block.M) + ' E= '+ str(block.E) +' S= '+ str(block.S) + ' I= '+ str(block.I)
                entry = CPU_number + ' executing:  ' + address + ' > ' + banderas + '\n'
                log.write(entry)
        #liberar memoria
        log.close()

    def write(self, block):
        #marca el bloque como modified
        block.modified(True)
        #esta funcion agrega un elemento nuevo al cache
        self.cache[block.address] = block

    def read(self, block):
        #esta funcion lee un valor del cache y lo marca como exclusive si
        # el bloque no fue marcado como shared antes
        if block.S:
            self.cache[block.address] = block
        else:
            block.exclusive(True)
            self.cache[block.address] = block

    def search(self, block):
        #funcion que retorna True is se encuentra un bloque en el cache
        #o False si el bloque tiene Invalid o no esta en el cache
        if block.address in self.cache:
            return True
        elif block.I:
            return False
        else:
            return False

    def add_entry(self, block):
        #esta funcion agrega una entrada al cache dependiendo de su modo  de
        #lectura o escritura
        if block.mode == 'L\n':
            self.read(block)
        else:
            self.write(block)
