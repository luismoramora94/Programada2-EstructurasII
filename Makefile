test:
	g++ main.cpp ./source/*.cpp -I ./include -o prueba
	./prueba
clean:
		rm prueba
		rm ./*.o
