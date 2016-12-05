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

hola:
	#PBS -N hola
	#PBS -q cpu-debug
	#PBS -l nodes=2
	#PBS -l walltime=0:30:00
	#cd $PBS_O_WORKDIR
	mpicc HolaMPI.cpp -o hola # Si no se compiló previamente
	mpirun -n 1 ./hola

clean:
		rm prueba
		rm hola
