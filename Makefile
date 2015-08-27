all: create_net_namespace

create_net_namespace: create_namespace.o
	gcc -o create_net_namespace create_namespace.o

create_net_namespace.o: create_namespace.c
	gcc -c create_namespace.c

clean:
	rm create_namespace.o create_net_namespace
