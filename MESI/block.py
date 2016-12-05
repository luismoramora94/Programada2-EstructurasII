class Block:
    def __init__(self, address='00000000', mode='L', M=False, E=False, S=False, I=True):
        #inicializamos el bloque con valores no validos
        self.address = address
        self.mode = mode
        #banderas del protocolo MESI
        self.M = M
        self.E = E
        self.S = S
        self.I = I

    def modified(self, arg):
        #poner la bandera de invalid en True o False
        self.M = arg

    def exclusive(self, arg):
        #poner la bandera de invalid en True o False
        self.E = arg

    def shared(self, arg):
        #poner la bandera de invalid en True o False
        self.S = arg

    def invalid(self, arg):
        #poner la bandera de invalid en True o False
        self.I = arg
