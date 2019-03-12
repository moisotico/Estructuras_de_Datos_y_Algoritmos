

build: 
	g++ -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system src/circulo.cpp src/main.cpp src/triangulo.cpp src/rectangulo.cpp -o bin/main	

run:	
	./bin/main data/data.txt data/resultado.txt

clean:	
	rm -f bin/main

doc:
	doxygen ../doc/Doxyfile

