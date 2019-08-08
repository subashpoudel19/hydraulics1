#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415
float calc(double, double, double, float);
float g=9.81;

int main()
{
    float hf, q, l, e, nu, k7, k8, i, k9;
    double k1, k2, k3, k4, k5, k6,k;
    printf("Enter the values of following values:");
    printf("\nHead Loss:(m) hf=");
    scanf("%f",&hf);
    printf("Discharge:(m^3/s) Q=");
    scanf("%f",&q);
    printf("Length:(m) L=");
    scanf("%f",&l);
    printf("Absolute Roughness Height:(m) e=");
    scanf("%f",&e);
    printf("Kinematic Viscosity:(m^2/s) nu=");
    scanf("%f", &nu);
    k1 = (4 * q)/PI;
    k2 = (hf * 2 * g)/(l*pow(k1,2));
    k3 = k1/nu;
    k4 = sqrt(k2);
    k5 = 1/(2*e);
    k6 = k3 * k4;
    k8 = 0.0;
    for (i= 0.001; i<2.00; i=i+0.001)
    {
        k7 = calc(k4, k5, k6, i);
        if(k7<0.001)
            break;
        printf("\n %f",k7);
    }
    printf("\n The diameter is %f", i);


    return 0;
}
float calc(double k1, double k2, double k3, float d)
{
    float k;
    k=(1/(k1*pow(d,2.5)))-2*log10(d*k2) + 1.74 - 2*log10(1+18.7*k2 /(k3 * sqrt(d)));
    return k;

}
