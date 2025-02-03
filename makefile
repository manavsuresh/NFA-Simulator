FLAGS = -Wall -g
CC = g++
EXEC = sureshbabu_p1

all: $(EXEC)

$(EXEC): sureshbabu_p1.o
	$(CC) $(CFLAGS) sureshbabu_p1.o -o $(EXEC)
	rm -rf *.o	

sureshbabu_p1.o: sureshbabu_p1.cpp
	$(CC) $(CFLAGS) -c sureshbabu_p1.cpp -o sureshbabu_p1.o

clean:
	rm -rf $(EXEC) *.o

tests:
	./sureshbabu_p1 sample_1.txt "0"
	@echo "reject 1 2"
	./sureshbabu_p1 sample_1.txt "000"
	@echo "accept 7"
	./sureshbabu_p1 sample_1.txt "10"
	@echo "reject 1 2"
	./sureshbabu_p1 sample_2.txt 0
	@echo "reject 1"
	./sureshbabu_p1 sample_2.txt 0101
	@echo "reject 3"
	./sureshbabu_p1 sample_2.txt "010111"
	@echo "accept 4 5"
	./sureshbabu_p1 sample_2.txt "0101110000"
	@echo "accept 4 5 6"
	