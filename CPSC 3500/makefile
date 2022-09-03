p1: wcat.o wgrep.o wzip.o wunzip.o
    g++ -o wcat wcat.o
    g++ -o wgrep wgrep.o
	g++ -o wzip wzip.o
	g++ -o wunzip wunzip.o
wcat.o: wcat.cpp
    g++ -c wcat.cpp
wgrep.o: wgrep.cpp
    g++ -c wgrep.cpp
wzip.o: wzip.cpp
    g++ -c wzip.cpp
wunzip.o: wunzip.cpp
	g++ -c wunzip.cpp
clean:
    rm -f *o p1
