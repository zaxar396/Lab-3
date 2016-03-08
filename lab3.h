# include <iostream>
# include <math.h>
#include <cstring>
#include <cstdio>
using namespace std;

class massive
{
private:
	    float **a;
		float **b;
		int n;

public:
       massive()
	   {
		   a = nullptr;
		   b = nullptr;
		   n = 0;
	   }

	   massive(float **c, float **d, int _n)
	   {
		   n = _n;
		   a = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   a[i] = new float[n];
		   }
		   memcpy(a, c, n*n*sizeof(float));
		   b = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   b[i] = new float[n];
		   }
		   memcpy(b, d, n*n*sizeof(float));
	   }
       
	   void copy(float **c, float **d, int _n)
	   {
		   n = _n;
		   if (a)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] a[i];
		   }
		   a = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   a[i] = new float[n];
		   }
		   memcpy(a, c, n*n*sizeof(float));
		   if (b)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] b[i];
		   }
		   b = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   b[i] = new float[n];
		   }
		   memcpy(b, d, n*n*sizeof(float));
	   }

	   void sum(float **mas)
	   {
		   if (mas)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] mas[i];
		   }
		   mas = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   mas[i] = new float[n];
		   }
		   for (int i = 0; i < n; i++)
		   {
			   for (int j = 0; j < n; j++)
			   {
				   mas[i][j] = a[i][j] + b[i][j];
			   }
		   }
	   }

	   void minus(float **mas)
	   {
		   if (mas)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] mas[i];
		   }
		   mas = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   mas[i] = new float[n];
		   }
		   for (int i = 0; i < n; i++)
		   {
			   for (int j = 0; j < n; j++)
			   {
				   mas[i][j] = a[i][j] - b[i][j];
			   }
		   }
	   }

	   void increase(float **mas)
	   {
		   if(mas)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] mas[i];
		   }
		   mas = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   mas[i] = new float[n];
		   }
		   for (int i = 0; i < n; i++)
		   {
			   for (int j = 0; j < n; j++)
			   {
				   float p = 0;
				   for (int p = 0; p < n; p++)
				   {
					   p = p + a[i][p] * b[p][j];
				   }
				   mas[i][j] = p;
			   }   
		   }
	   }

	   void constant(float **mas, float b)
	   {
		   if (mas)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] mas[i];
		   }
		   mas = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   mas[i] = new float[n];
		   }
		   for (int i = 0; i < n; i++)
		   {
			   for (int j = 0; j < n; j++)
			   {
				   mas[i][j] = a[i][j] * b;
			   }
		   }
	   }

	   void transp(float **mas)
	   {   
		   if (mas)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] mas[i];
		   }
		   mas = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   mas[i] = new float[n];
		   }
		   memcpy(mas, a, n*n*sizeof(float));
		   float l;
		   for (int i = 0; i<n; i++)
		   {
			   for (int j = i; j<n; j++)
			   {
				   l = mas[i][j];
				   mas[i][j] = mas[j][i];
				   mas[j][i] = l;
			   }
		   }
	   }

	   void deter(float **mas)
	   {
		   if (mas)
		   {
			   for (int i = 0; i < n; i++)
				   delete[] mas[i];
		   }
		   mas = new float*[n];
		   for (int i = 0; i < n; i++)
		   {
			   mas[i] = new float[n];
		   }
		   memcpy(mas, a, n*n*sizeof(float));
		   int p = 0;
		   int t;
		   float det;
		   for (int i = 0; i < n - 1; i++)
		   {
			   t = 1;
			   while (mas[i][i] == 0)
			   {
				   for (int j = 0; j < n; j++)
				   {
					   mas[i][j] = det;
					   mas[i][j] = a[i + t][j];
					   mas[i + t][j] = det;
				   }
				   p++;
				   t++;
			   }

			   for (int k = i + 1; k < n; k++)
			   {
				   det = mas[k][i] / mas[i][i];
				   for (int  j = 0; j < n; j++)
					   mas[k][j] -= mas[i][j] * det;
			   }
		   }

		   det = pow(-1, p);
		   for (int i = 0; i < n; i++)
			   det *= mas[i][i];

	   }
};


