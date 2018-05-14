#include "iostream"
#include "fstream"
#include "math.h"
using namespace std;


float q1_punto(float p1)
{
	return p1;
}



float q2_punto(float p2)
{
	return p2;
}



float p1_punto(float q1, float e)
{
	return -2.0*q1/pow( 4.0*q1*q1 + e*e ,1.5);
}



float p2_punto(float q1, float q2, float e)
{
	float respuesta;
	respuesta = (q1-q2)/pow( pow(q1-q2,2.0) + e*e/4.0, 1.5 );
	respuesta = respuesta - (q1+q2)/pow( pow(q1+q2,2.0) + e*e/4.0 , 1.5 );
	return respuesta;
}

int main(int argc, char const *argv[])
{
	const float dt = 0.006;
	const float tf = 3000;
	const float a = 1.0/pow(2.0,1.5);
	//const float e = 1.0e-3;
	const float e = 0.5;
	const float q10 = a;
	const float p10 = 0.0;
	const float q20 = -a;
	const float p20 = 0.0;

	// Mensajes de inicializacion
	cout << "Ejecutando programa" << argv[0] << endl;
	cout << "---\nParametros" << endl << endl;
	cout << "Paso de tiempo dt \t" << dt << endl;
	cout << "Tiempo final \t" << tf << endl;
	cout << "a \t" << a << endl;
	cout << "epsilon \t" << e << endl;
	cout << "Condiciones inciales (q1,p1)=(a,0) \t" << endl;
	cout << "(q2,p2)=(-a,0) \t" << endl;
	cout << "---" << endl;
	

	// variables generales
	int k;
	int nt = 1.0 + tf/dt;
	// numero de iteraciones

	// Inicializar variables
	// float q1=a, p1=0.0;
	// float q2=0.0, p2=0.0;
	// Nevas condiciones inciales
	float q1=a, p1=0.0;
	float q2=-a, p2=0.0;

	float q1n=0.0, p1n=0.0;
	float q2n=0.0, p2n=0.0;	

	float k1q1=0.0, k2q1=0.0, k3q1=0.0, k4q1=0.0;
	float k1p1=0.0, k2p1=0.0, k3p1=0.0, k4p1=0.0;
	float k1q2=0.0, k2q2=0.0, k3q2=0.0, k4q2=0.0;
	float k1p2=0.0, k2p2=0.0, k3p2=0.0, k4p2=0.0;

	
	// recorrido en el tiempo
	ofstream q2_p2("q2_p2.txt"); // archivo de salida
	ofstream q1_p1_q2_p2("q1_p1_q2_p2.txt"); // archivo de salida

	cout << "Iniciando las " << nt << " iteraciones de RK4\n";

	for ( k = 0; k < nt; ++k)
	{
		q1_p1_q2_p2 << q1 << " " << p1 << " " << q2 << " " << p2 << endl;
		// Calcular coeficientes k
		k1q1 = q1_punto(p1);
		k1p1 = p1_punto(q1,e);
		k1q2 = q2_punto(p2);
		k1p2 = p2_punto(q1, q2, e);

		k2q1 = q1_punto(p1+0.5*dt*k1p1 );
		k2p1 = p1_punto(q1+0.5*dt*k1q1, e );
		k2q2 = q2_punto(p2+0.5*dt*k1p2 );
		k2p2 = p2_punto(q1+0.5*dt*k1q1, q2+0.5*dt*k1q2, e);

		k3q1 = q1_punto(p1+0.5*dt*k2p1 );
		k3p1 = p1_punto(q1+0.5*dt*k2q1, e );
		k3q2 = q2_punto(p2+0.5*dt*k2p2 );
		k3p2 = p2_punto(q1+0.5*dt*k2q1, q2+0.5*dt*k2q2, e);

		k4q1 = q1_punto(p1+dt*k3p1 );
		k4p1 = p1_punto(q1+dt*k3q1, e );
		k4q2 = q2_punto(p2+dt*k3p2 );
		k4p2 = p2_punto(q1+dt*k3q1, q2+dt*k3q2, e);

		// Avanzar en el tiempo
		q1n = q1 + (1.0/6.0)*dt*(k1q1 + 2.0*k2q1 + 2.0*k3q1 + k4q1);
		p1n = p1 + (1.0/6.0)*dt*(k1p1 + 2.0*k2p1 + 2.0*k3p1 + k4p1);
		q2n = q2 + (1.0/6.0)*dt*(k1q2 + 2.0*k2q2 + 2.0*k3q2 + k4q2);
		p2n = p2 + (1.0/6.0)*dt*(k1p2 + 2.0*k2p2 + 2.0*k3p2 + k4p2);

		// cada vez que q1 pase de ser positivo a negativo,
		// el codigo va a imprimir en pantalla los valores
		// de q2 y p2
		if ( (q1>0.0 and q1n<0.0) or (q1<0.0 and q1n>0.0) )
		{
			q2_p2 << q2n << " " << p2n << "\n";
			cout << k << "...";
		}
		
		// Preparar siguiente iteracion
		q1 = q1n;
		p1 = p1n;
		q2 = q2n;
		p2 = p2n;
	}


	cout << "Programa Finalizado\n\n";


	return 0;
}



	
