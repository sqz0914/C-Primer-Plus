#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG 180/(4*atan(1))

typedef struct polar {
	double magnitude;
	double angles;
} POLAR;

typedef struct rect {
	double x;
	double y;
} RECT;

RECT POL_TO_REC(POLAR);

int main(void)
{
	POLAR input;
	RECT result;
	puts("Please enter the magnitude and angle(in degrees) (q to qiut):");
	while(scanf("%lf %lf", &input.magnitude, &input.angles) == 2)
	{
		printf("magnitude = %g, angle = %g\n", input.magnitude, 
		       input.angles);
		input.angles /= RAD_TO_DEG;
		result = POL_TO_REC(input);
		printf("x = %g, y = %g\n", result.x, result.y);
		puts("Next input (q to qiut):");
	}
	puts("Bye!");
	
	return 0;
}

RECT POL_TO_REC(POLAR pb)
{
	RECT ps;
	ps.x = pb.magnitude * cos(pb.angles);
	ps.y = pb.magnitude * sin(pb.angles);
	
	return ps;
}
