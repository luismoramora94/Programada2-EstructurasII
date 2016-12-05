sec:
	clear
	g++ ./source/cribasec.cpp -I ./include -o pruebasec
	./pruebasec
	rm pruebasec
par:
	clear
	mpic++ ./source/cribapar.cpp -I ./include -o prueba
	mpirun -np 4 prueba
	rm prueba
