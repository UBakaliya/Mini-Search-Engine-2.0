run:
	rm -f application.exe
	g++ -std=c++11 -Wall -lcurl main.cpp  -o application.exe
	./application.exe
