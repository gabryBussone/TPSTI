class Node():
    def __init__(self, valore):
        self.valore = valore
        self.sinistro = None
        self.destro = None

    def inserisci(self, valore):
        if self.valore is not None:
            if self.valore > valore:
                if self.sinistro is None:
                    self.sinistro = Node(valore)
                else:
                    self.sinistro.inserisci(valore)
            elif self.valore < valore:
                if self.destro is None:
                    self.destro = Node(valore)
                else:
                    self.destro.inserisci(valore)
        else:
            self.valore = valore
    
    def print_tree(self):
        print(self.valore)
        if self.sinistro is not None:
            self.sinistro.print_tree()
        if self.destro is not None:
            self.destro.print_tree()

    def cercaValore(self, valore):
        if self.valore is not None:
            if valore == self.valore:
                return True
            elif valore < self.valore and self.sinistro is not None:
                return self.sinistro.cercaValore(valore)
            elif valore > self.valore and self.destro is not None:
                return self.destro.cercaValore(valore)
            else:
                return False   
        else: 
            return False
    
    def isBilanciato(self):
        def altezza(nodo):
            if nodo is None:
                return 0
            return 1 + max(altezza(nodo.sinistro), altezza(nodo.destro))

        def bilanciato_helper(nodo):
            if nodo is None:
                return True
            altezza_sinistro = altezza(nodo.sinistro)
            altezza_destro = altezza(nodo.destro)
            if abs(altezza_sinistro - altezza_destro) <= 1 and bilanciato_helper(nodo.sinistro) and bilanciato_helper(nodo.destro):
                return True
            return False

        return bilanciato_helper(self)

def alberoBilanciato(lista, n):
    centro = len(lista) // 2
    n.inserisci(lista[centro])
    if centro != 0:
        listaSx = lista[0:centro]
        listaDx = lista[centro + 1:]
        if len(listaSx) > 0:
            alberoBilanciato(listaSx, n)
        if len(listaDx) > 0:
            alberoBilanciato(listaDx, n)
    else:
        return None

def main():
    n1 = Node(None)
    lista = [5, 6, 2, 20, 28, 16]
    lista.sort()
    alberoBilanciato(lista, n1)
    n1.print_tree()
    if n1.isBilanciato():
        print("L'albero è bilanciato.")
    else:
        print("L'albero non è bilanciato.")

if __name__ == '__main__':
    main()
