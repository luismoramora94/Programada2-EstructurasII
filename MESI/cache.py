import block

class cache:
    def __init__(self):
        #diccionario que contiene los datos del cache
        self.cache = {}
        self.hits = 0
        self.misses = 0

    def write(self, block):
        #marca el bloque como modified
        block.modified(True)
        #esta funcion agrega un elemento nuevo al cache
        self.cache[block.address] = block

    def read(self, block):
        #esta funcion lee un valor del cache y lo marca como exclusive
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
