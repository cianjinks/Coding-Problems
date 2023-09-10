# Gonna use the socket library to intercept packets and print out their bytes as a string
# If I point firefox proxy at the program it will print out HTTP packets

import socket

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(("127.0.0.1", 8081))
    sock.listen(1)
    while True:
        print("Waiting for connection!")
        conn, addr = sock.accept()
        print(f"Connection received from {addr}")
        print("----------- Data ------------")
        data = conn.recv(4096)
        print(data.decode("utf-8"))
        print("-----------------------------")

if __name__ == "__main__":
    main()