
#include "iostream"
#include "fstream"
#include "math.h"
using namespace std;



int main(int argc, char const *argv[])
{
	const float T = 40;
	const float rho = 10;
	const float L = 100;
	const float t0 = 0.0;
	const float tf = 200;
	const float c = pow(T/rho,0.5);

	// Mensajes de inicializacion
	cout << "Ejecutando programa" << argv[0] << endl;
	cout << "---\nParametros" << endl << endl;
	cout << "Tension T \t" << T << endl;
	cout << "densidad rho \t" << rho << endl;
	cout << "Longitud L \t" << L << endl;
	cout << "Tiempo inicial y final \t" << t0 << "---" << tf << endl;
	

	// variables generales
	int i, j;
	int n = 100; // puntos en la recta
	float dx = L/(n-1); // Distancia entre nodos
	float x;

	// Construir arreglos
	float U0[n];
	float U1[n];
	float U2[n];

	// Inicializar arreglos
	for (i = 0; i < n; ++i)
	{
		x = i*dx;
		if (x<0.8*L) // condiciones iniciales
		{	
			U0[i] = 1.25*x/L;	
			U1[i] = 1.25*x/L;	
		}
		else
		{	
			U0[i] = 5.0-5.0*x/L;
			U1[i] = 5.0-5.0*x/L;
		}

		U2[i] = 0.0;
	}


	// Iterar en el tiempo
	float dt = 0.5*dx/c;
	int nt = 1.0 + (tf-t0)/dt;
	int k;
	float a=pow(c*dt/dx,2);


	cout << "\n\n Resolviendo sistema\n\n";

	cout << " Pasos de tiempo " << nt << endl;
	ofstream cuerda("cuerda.txt");

	for (k = 0; k < nt; ++k)
	{
		cuerda << U2[0] << " "; // Escribir primer nodo
		for (i = 1; i < n-1; ++i) // Calcular nodos interiores
		{
			U2[i
] = 2*U1[i] - U0[i] + a*( U1[i-1] -2*U1[i] + U1[i+1] );
			cuerda << U2[i] << " "; //Imprimir datos
		}
		cuerda << U2[n-1] << "\n"; // nueva linea
		


		// Preparar siguiente iteracion
		for (i = 1; i < n-1; ++i) 
		{// Calcular nodos interiores
			U1[i] = U2[i];
			U0[i] = U1[i];
		}
	}


	return 0;
}



	
