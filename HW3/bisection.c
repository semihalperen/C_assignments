#include <stdio.h>

float absolute(float a){
	return a > 0 ? a : a * -1;
}

float equation(int a, int b, int c, float x){
	return a*x*x + b*x + c;
}


float bisection(int a, int b, int c, float l, float u){
	float mid = (l+u)/2;
	
	if(absolute(equation(a,b,c,mid))< 0.001)
		return mid;
	else if(absolute(equation(a,b,c,u))< 0.001)
		return u;
	else if(absolute(equation(a,b,c,l))< 0.001)
		return l;
	else if(equation(a,b,c,l)*equation(a,b,c,mid)<0)
		bisection(a,b,c,l,mid);
	else
		bisection(a,b,c,mid,u);
}

void findRoots(int a, int b, int c, float l, float u){
	if(a == 0 && equation(a,b,c,l)*(equation(a,b,c,u))>0)
		printf("No roots found\n");
	else if(a != 0 && equation(a,b,c,l)*(equation(a,b,c,u))>0){
		if(equation(a,b,c,l)*equation(a,b,c,(l+u)/2)<0 || equation(a,b,c,l)*equation(a,b,c,(l+u)/2)<0)
			printf("Roots: x = %f, x = %f \n", bisection(a,b,c,l,(l+u)/2), bisection(a,b,c,(l+u)/2,u));
		else
			printf("No roots found\n");
	}
	else{
		printf("Root: x = %f\n", bisection(a,b,c,l,u));
	}
}		


int main()
{
	int a, b ,c, Lb, Ub;
	scanf("%d%d%d%d%d", &a, &b, &c, &Lb, &Ub);

	printf("Entered equation: %dx^2 + %dx + %d\n", a,b,c);
	printf("Domain: %d %d\n", Lb, Ub);

	findRoots(a,b,c, Lb, Ub);
	return 0;
}