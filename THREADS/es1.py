import random
from threading import Thread

class PasswordThread(Thread):
    def __init__(self, password, length):
        super().__init__()
        self.password = password
        self.length = length

    def run(self):
        while True:
            password = ''.join(random.choice("abcdefghijklmnopqrstuvwxyz") for _ in range(self.length))
            if password == self.password:
                print(f"Password trovata: {password}")
                break

def main():
    password = "ciao"
    password_lung = len(password)
    num_threads = 4

    threads = []
    for _ in range(num_threads):
        thread = PasswordThread(password, password_lung)
        thread.start()
        threads.append(thread)

    for thread in threads:
        thread.join()

if __name__ == "__main__":
    main()
