structures:
	gcc -o goTests.o stack.c queue.c tests.c -std=c11

.PHONY: clean
clean:
	rm goTests.o
