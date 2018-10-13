compiler=g++
flags=-Wall

tests:
	$(compiler) $(flags) tests.cpp -o tests

clean:
	rm -rf main tests