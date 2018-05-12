all : potencial.txt V.png


V.png: potencial.txt grafica.py
	python grafica.py


potencial.txt: placas.cpp	
	g++ placas.cpp -o placas.x
	./placas.x
