all : quiz
quiz : QuizResult.o main.o
	gcc -W -Wall -o quiz QuizResult.o main.o
QuizResult.o : QuizResult.cpp
	gcc -W -Wall -c -o QuizResult.o QuizResult.cpp -Imylib -L/usr/local/lib
main.o : main.cpp
	gcc -W -Wall -c -o main.o main.cpp -Imylib -L/usr/local/lib
clean :
	rm -rf *.o quiz
