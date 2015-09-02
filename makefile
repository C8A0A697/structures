structures:
	gcc -o goTests.o src/stack.c src/queue.c tests/tests.c -std=c11 -I./inc/

.PHONY: clean
clean:
	rm goTests.o
