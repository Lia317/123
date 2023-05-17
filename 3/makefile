all: client server

client: client.o
	gcc -o client client.o

server: server.o
	gcc -o server server.o

debug: clean debug_client debug_server

debug_client: client_d.o
	gcc -g -o client_debug client_d.o

debug_server: server_d.o
	gcc -g -o server_debug server_d.o

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f *.o client server client_debug server_debug
