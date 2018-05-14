all: cuerda.txt u.png u.gif

u.png u.gif: cuerda.txt grafica.py
	
	python grafica.py

cuerda.txt: cuerda.cpp	
	g++ cuerda.cpp -o cuerda.x
	./cuerda.x
