build:
	g++ -std=c++11 src/main.cpp  src/LenEnc.cpp  -o bin/rle
	g++ -std=c++11 src/Comp.cpp src/Compressor.cpp src/Dictionary.cpp -o bin/comp
	g++ -std=c++11 src/Descomp.cpp src/Decompressor.cpp -o bin/decomp
run:
	./bin/rle 
	./bin/comp h > h.lz77
	./bin/decomp h.lz77 > h.lz77_descomprimido

clean:
	rm -f bin/main

doc:
	doxygen ../doc/Doxyfile
