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
	@./sureshbabu_p1 p1_machine1.txt aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabababababababababababababaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbaaaaaaabababababababababbabababbababababababa
	@./sureshbabu_p1 p1_machine1.txt bbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabababababababababababababaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbaaaaaaabababababababababbabababbababababababa
	@./sureshbabu_p1 p1_machine1.txt bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaabababababababababbbbabbababababaaabababababababababababababababaaaaaaaaaaaaabbbbbbbbbbaababababababababababab
	@./sureshbabu_p1 p1_machine1.txt bbbbbbbbbbbaaaaaaaababababababababababababababababababababababababababababababaaaaaaaaabbabaaababbbabababababababab
	@./sureshbabu_p1 p1_machine1.txt bababababababababababababbabababababababababababababababababababababababababababababababababababababababababbababababababababababababababababababababababababababababaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaabbabbbbbbbababababab
	@./sureshbabu_p1 p1_machine1.txt bababababababababababababbabababababababababababababababababababababababababababababababababababababababababbababababababababababababababababababababababababababababaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaabbabbbbbbbabababababaaaaaa
	@./sureshbabu_p1 p1_machine1.txt abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbbabababababbbbbbbbbbbbabbaba
	@./sureshbabu_p1 p1_machine1.txt abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbab
	@./sureshbabu_p1 p1_machine1.txt abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab
	@./sureshbabu_p1 p1_machine1.txt bababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbababababababababababababababababaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaba
	@./sureshbabu_p1 p1_machine1.txt aaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbababababababababababababababababababababababababababababababababababababababababababababbababa
	@./sureshbabu_p1 p1_machine1.txt aaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbababababababababababababababababababababababababababababababababababababababababababababbababa
	@./sureshbabu_p1 p1_machine2.txt 01010101010101010101010
	@./sureshbabu_p1 p1_machine2.txt 010101010101010101010101
	@./sureshbabu_p1 p1_machine2.txt 0100000001011010101110001010100000111101010101011010111110000101010101010101000001010101010101010110101010101011010101111000101010101
	@./sureshbabu_p1 p1_machine2.txt 10101101000101010101101010111010101000101010101010100010101101010101010101
	@./sureshbabu_p1 p1_machine2.txt 110100100010101011101010101010101010100000000011010101011111110101010101000011111010101000101010101011001
	@./sureshbabu_p1 p1_machine2.txt 01010100101101010101010101010101
	@./sureshbabu_p1 p1_machine2.txt 000000000000000000000000000000000000000000000000000000000000000000000000000000000
	@./sureshbabu_p1 p1_machine2.txt 111111111111111111111111111111111111111111111111111111111111100000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	@./sureshbabu_p1 p1_machine2.txt 0101010101010101010101010111
	@./sureshbabu_p1 p1_machine2.txt 01010101010101010101110111111111111
	@./sureshbabu_p1 p1_machine2.txt 01010101010101010101000000000000
	@./sureshbabu_p1 p1_machine2.txt 010101010101010101010000000000002