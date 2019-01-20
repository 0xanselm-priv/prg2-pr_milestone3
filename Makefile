CC=g++
CFLAGS=-std=gnu++11

default: main.o NeuralNet.o Edge.o Node.o Layer.o
	$(CC) $(CFLAGS) -o out.x main.o NeuralNet.o Edge.o Node.o Layer.o

main.o: main.cpp NeuralNet.cpp NeuralNet.h
	$(CC) $(CFLAGS) -c main.cpp NeuralNet.cpp

Node.o: Node.cpp Node.h Edge.cpp Edge.h
	$(CC) $(CFLAGS) -c Node.cpp Edge.cpp

Edge.o: Edge.cpp Edge.h Node.cpp Node.h
	$(CC) $(CFLAGS) -c Edge.cpp Node.cpp

Layer.o: Layer.cpp Layer.h Node.cpp Node.h
	$(CC) $(CFLAGS) -c Layer.cpp Node.cpp

NeuralNet.o: NeuralNet.cpp NeuralNet.h Node.cpp Node.h Edge.cpp Edge.h Layer.cpp Layer.h
	$(CC) $(CFLAGS) -c NeuralNet.cpp Node.cpp Edge.cpp Layer.cpp

clean:
	$(RM) count *.o *~


