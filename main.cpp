#include<iostream>
#include<complex>
#include<Windows.h>

std::complex<double> init(0, 0);
double bailout = 4000;
int MAXITER = 1000;
double xmin = -2 * 0.75, xmax = +2 * 0.75, ymax = +1 * 0.75, ymin = -3 * 0.75;
int nSample = 100;

std::complex<double> mandEval(std::complex<double> p, int maxIter) {
	std::complex<double> z = init;
	for (int i = 0; i < maxIter; i++) {
		z = z * z + p;
		//z = cos(z)+std::complex<double>(1,0)/p;
		if (abs(z) > bailout)
			break;
	}
	return z;
}

void mandPlot() {
	std::complex<double> pixel(0, 0);
	for (int i = 0; i < nSample; i++) {
		for (int j = 0; j < nSample*2; j++) {
			pixel = std::complex<double>((ymin * 2 + (ymax - ymin) / nSample * j) / 2.25, xmin + (xmax - xmin) / nSample * i);
			if (abs(mandEval(pixel,MAXITER)) < bailout) {
				//std::cout << (char)219;
				std::cout << '*';
			}
			else
			{
				std::cout << ' ';//
			}
		}
		std::cout << std::endl;
	}
};

int main(void) {
	system("pause");
	mandPlot();
	system("pause");
	return 0;
}