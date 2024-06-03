import threading
import time

#lock = threading.Lock()
semaforo = threading.Semaphore(1)

class StampaNome(threading.Thread):
    def __init__(self, nome):
        super().__init__()
        self.nome = nome

    def run(self):
        for _ in range(5):
            semaforo.acquire()
            print("ciao", end=" ")
            time.sleep(1)
            print(self.nome)
            semaforo.release()


def main():
    nomi = ["mario", "luca", "alice", "bob"]
    listaThread = [StampaNome(nome) for nome in nomi]
    for thread in listaThread:
        thread.start()
    for thread in listaThread:
        thread.join()


if __name__=="__main__":
    main()


#fare un server tcp in cui ha una password (3 lettere minuscole con alfzbeto uk) e il client deve indirvinarla