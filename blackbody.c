#include <stdio.h>
#include <math.h>
#include <alloca.h>

/* Wavelength in meters */
double PlanckLaw(double Wavelength, double T)
{
    double c = 299792458; /* Speed of light */
    double h = 6.626070040 * pow(10,-34); /* Planck constant */
    double k = 1.38064852 * pow(10, -23); /* Boltzman constant */
    
    double E = (2*h*pow(c,2)) / pow(Wavelength,5)
             * 1 / (exp((h*c)/(Wavelength*k*T))-1);

    return E;
}

/* generate blackbody spectrum. StartWavelength and WavelengthIncrement is in nm
 * returns to double array Output. */
void BlackbodySpectrum( double Kelvin,
                        double * Output,
                        int OutputLength,
                        double StartWavelength,
                        double WavelengthIncrement )
{
    for (int w = 0; w < OutputLength; ++w)
    {
        double lambda = (StartWavelength + WavelengthIncrement*w) * pow(10,-9);
        Output[w] = PlanckLaw(lambda, Kelvin);
    }
}

int main()
{
    double start = 100, increment = 2.34;
    int count = 1000;
    double * distribution = alloca(count*sizeof(double));

    /* Generate blackbody from 100nm to 4100nm in one thousand 4nm increments */
    BlackbodySpectrum(6000, distribution, 1000, 100, 4);

    FILE * file = fopen("3000k.txt", "w");
    BlackbodySpectrum(3000, distribution, count, start, increment);
    for (int i = 0; i < count; ++i)
        fprintf(file, "%f, %f\n", start+increment*i, distribution[i]);
    fclose(file);

    file = fopen("4000k.txt", "w");
    BlackbodySpectrum(4000, distribution, count, start, increment);
    for (int i = 0; i < count; ++i)
        fprintf(file, "%f, %f\n", start+increment*i, distribution[i]);
    fclose(file);

    file = fopen("4500k.txt", "w");
    BlackbodySpectrum(4500, distribution, count, start, increment);
    for (int i = 0; i < count; ++i)
        fprintf(file, "%f, %f\n", start+increment*i, distribution[i]);
    fclose(file);

    file = fopen("5000k.txt", "w");
    BlackbodySpectrum(5000, distribution, count, start, increment);
    for (int i = 0; i < count; ++i)
        fprintf(file, "%f, %f\n", start+increment*i, distribution[i]);
    fclose(file);

    file = fopen("5500k.txt", "w");
    BlackbodySpectrum(5500, distribution, count, start, increment);
    for (int i = 0; i < count; ++i)
        fprintf(file, "%f, %f\n", start+increment*i, distribution[i]);
    fclose(file);

    file = fopen("6000k.txt", "w");
    BlackbodySpectrum(6000, distribution, count, start, increment);
    for (int i = 0; i < count; ++i)
        fprintf(file, "%f, %f\n", start+increment*i, distribution[i]);
    fclose(file);

    return 0;
}

// gcc blackbody.c -lm; ./a.out; gnuplot gnuplot