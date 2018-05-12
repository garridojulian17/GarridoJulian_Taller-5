#include "iostream"
#include "fstream"
#include "math.h"
#include "cstdio"
using namespace std;



int main(int argc, char const *argv[])
{
	const float L = 0.05;
	const float l = 0.02;
	const float d = 0.01;
	const float h = 5.0/512*0.01;
	const float V0 = 100.0;
	const int N = 2*(L/h)*(L/h);
	const int n = L/h; // numero de elementos en la matriz

	// Mensajes de inicializacion
	cout << "Ejecutando programa" << argv[0] << endl;
	cout << "---\nParametros" << endl << endl;
	cout << "Distancia L [m]\t" << L << endl;
	cout << "Distancia l [m]\t" << l << endl;
	cout << "Separacion d [m]\t" << d << endl;
	cout << "Separacion entre puntos h[m]\t" << h << endl;
	cout << "Voltaje inicial V0 [V]\t" << V0<< endl;
	cout << "Numero de iteraciones N\t" << N << "\n---\n";

	// variables generales
	int i, j;

	// Construir matrices
	float V[n][n];
	float Vn[n][n];
	float Ex[n][n];
	float Ey[n][n];
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			V[i][j] = 0.0;
			Vn[i][j] = 0.0;
			Ex[i][j] = 0.0;
			Ey[i][j] = 0.0;
		}
	}

	// Ubicar potencial de las placas
	// Conocer indices para ubicar las placas
	int nd = n*d/L;
	int nl = n*l/L;
	int nd0 = n/2 - nd/2;
	int nd1 = n/2 + nd/2;
	int nl0 = n-nl/2;
	for (i = n/2-nl/2; i < n/2+nl/2; ++i)
	{
		V[nd0][i] = -V0/2;
		V[nd1][i] = V0/2;
	}


	// Iteración con metodo de relajacion
	int k;
	int ifrontera;
	for (k = 0; k < N/10; ++k)
	{
		// Iteracion k
		for (i = 1; i < n-1; ++i)
		{

			for (j = 1; j < n-1; ++j)
			{
				Vn[i][j] = (V[i-1][j] + V[i+1][j] + V[i][j+1] + V[i][j-1])/4.0;
			}
		}

		//Se reasignan condiciones de frontera
		for (ifrontera = n/2-nl/2; ifrontera < n/2+nl/2; ++ifrontera)
		{
			V[nd0][ifrontera] = -V0/2;
			V[nd1][ifrontera] = V0/2;
		}

		
		for (i = 1; i < n-1; ++i)
		{
			for (j = 1; j < n-1; ++j)
			{

				V[i][j] = Vn[i][j];
			}
		}


	}


	// Se calcula el campo electrico
	for (i = 1; i < n-1; ++i)
	{
		for (j = 1; j < n-1; ++j)
		{
			Ex[i][j] = -(V[i][j+1]-V[i][j])/h;
			Ey[i][j] = -(V[i+1][j]-V[i][j])/h;
		}
	}

	//Se obtiene el potencial
	cout << "\n\n Imprimir Datos\n\n";
	ofstream potencial("potencial.txt");
	ofstream campox("campox.txt");
	ofstream campoy("campoy.txt");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			potencial << V[i][j] << " ";
			campox << Ex[i][j] << " ";
			campoy << Ey[i][j] << " ";
		}
		potencial << "\n";	
		campox << "\n";
		campoy << "\n";
	}

	return 0;
}



	
