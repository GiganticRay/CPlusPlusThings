CC	=	g++

main:	main.cpp apple.a
	${CC} main.cpp apple.a -o main -g

apple.a:	apple.cpp
	${CC} -c apple.cpp -o apple.a

clean:
	rm *.a main
