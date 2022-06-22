// P1 Assignment
// Author: Jameson Walter
// Date:   8/27/2021
// Class:  CS270
// Email:  sharpp@colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// example of a global array
int exampleGlobalArray[2];
double input[5];
double output[4];

// this function can be used as a guide for the funtions you will implement
void computeCircle(double radius, double *addressOfArea)
{
    // Compute area
    double result = 3.141593 * radius * radius;

    // Dereference pointer to return result
    *addressOfArea = result;
}
void computeCube(double s, double *addressOfVolume) {
	double res = s*s*s;
	*addressOfVolume = res;
}
void computeTetrahydron(double s, double *addressOfVolume) {
	double res = 0.117851*s*s*s;
	*addressOfVolume = res;
}
void computeCylinder(double r, double h, double *addressOfVolume) {
	double res = 3.141593*r*r*h;
	*addressOfVolume = res;
}

int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc != 5) {
        printf("usage: ./P1 <double> <double> <double> <double> <double>\n");
        return EXIT_FAILURE;
    }

    // Parse arguments
	for (int i = 0; i < 5; i = i + 1) {
    		input[i] = atof(argv[i+1]);
	}


    // Call function
    computeCircle(input[0], &output[0]);
	computeCube(input[1], &output[1]);
	computeTetrahydron(input[2], &output[2]);
	computeCylinder(input[3], input[4], &output[3]);

    // Print area
    printf("SPHERE, radius = %.5f, volume = %.5f.\n", input[0], output[0]);
	printf("CUBE, side = %.5f, volume = %.5f.\n", input[1], output[1]);
	printf("TETRAHEDRON, side = %.5f, volume = %.5f.\n", input[2], output[2]);
	printf("CYLINDER, radius = %.5f, height = %.5f, volume = %.5f.\n", input[3], input[4], output[3]);

    // Return success
    return EXIT_SUCCESS;
}
