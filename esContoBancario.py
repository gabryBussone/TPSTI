import threading
import time

class ContoBancario:
    def __init__(self, saldo, numero_conto):
        self.saldo = saldo
        self.numero_conto = numero_conto
        self.lock = threading.Lock()  # Lock per sincronizzazione

    def deposito(self, importo):
        with self.lock:
            self.saldo += importo
            print(f"Deposito di {importo} effettuato. Saldo attuale: {self.saldo}")

    def prelievo(self, importo):
        with self.lock:
            if self.saldo >= importo:
                self.saldo -= importo
                print(f"Prelievo di {importo} effettuato. Saldo attuale: {self.saldo}")
            else:
                print("Saldo insufficiente per il prelievo.")

class ContoCorrente(ContoBancario):
    pass

class ContoRisparmio(ContoBancario):
    pass

def simulazione_cliente(conto):
    for _ in range(5):
        conto.deposito(100)
        time.sleep(0.5)
        conto.prelievo(50)
        time.sleep(0.5)

if __name__ == "__main__":
    conto_corrente = ContoCorrente(1000, "CC123456")
    conto_risparmio = ContoRisparmio(500, "CR789012")

    # Simulazione di utilizzo concorrente dei conti
    thread1 = threading.Thread(target=simulazione_cliente, args=(conto_corrente,))
    thread2 = threading.Thread(target=simulazione_cliente, args=(conto_risparmio,))

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

    print("Operazioni completate.")
