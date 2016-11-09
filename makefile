test: signal.c
	gcc signal.c -o test
clean:
	rm *~
run: test
	./test
