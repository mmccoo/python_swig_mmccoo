
#include <stdio.h>
#include <time.h>
#include <example.hxx>

double My_variable = 3.0;
 
int fact(int n) {
    if (n <= 1) return 1;
    else return n*fact(n-1);
}
 
int my_mod(int x, int y) {
    return (x%y);
}
 	
char *get_time()
{
    time_t ltime;
    time(&ltime);
    return ctime(&ltime);
}

int get_var() {
    return My_variable;
}

int call_director(Foo* foo)
{
    int a = foo->one();
    int b = foo->two("director message");
    return a+b;
}

int Foo::one()
{
    fprintf(stdout, "hello from one\n");
    return -1;
}

int Foo::two(const char *str)
{
    fprintf(stdout, "hello from two %s\n", str);
    return -2;
}

