all: client server 

client: client.o
    qcc -o client client.o 

server: server.o
    qcc -o server server.o  

debug: clean debug_client debug_server  

debug_client: client_d.o
    qcc -g -o client_debug client_d.o 

debug_server: server_d.o
    qcc -g -o server_debug server_d.o 

%.o: %.c
    qcc -c $< -o $@  

clean:
    rm -f *.o client server client_debug server_debug 
