#include "Vector.h"

int main(int argc, char** argv)
{
	int n;
	TVector v1, v2, s, d;
	double m;
	char* infilename, * outfilename;
	if (argc < 4)
	{
		printf("Incorrect arguments\n");
		return 1;
	}

	n = atoi(argv[1]);
	printf("n = %d\n", n);
	infilename = argv[2];
	printf("Input file name: %s\n", infilename);
	outfilename = argv[3];
	printf("Output file name: %s\n", outfilename);
	read(infilename, &v1, &v2);

	s = sum(&v1, &v2);
	d = diff(&v1, &v2);
	m = mult(&v1, &v2);

	write(outfilename, &s, &d, m);
	free(v1.x);
	free(v2.x);

	if (s.x != NULL)
	{
		free(s.x);
	}
	if (d.x != NULL)
	{
		free(d.x);
	}
	return 0;
}