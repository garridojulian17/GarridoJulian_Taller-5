
all: q1_p1.png  p2_p2.png  q1_p1_q2_p2.txt  q2_p2.txt caos.pdf

q1_p1.png p2_p2.png caos.pdf: caos.py q1_p1_q2_p2.txt q2_p2.txt
	
	python caos.py

q1_p1_q2_p2.txt  q2_p2.txt: caos.cpp	
	g++ caos.cpp -o caos.x
	./caos.x
