
#include <stdio.h>
#include <time.h>
#include <example.hxx>

static Foo *foo = NULL;

void set_foo(Foo *infoo)
{
    foo = infoo;
}

int call_foo_callback()
{
    return foo->callback();
}

int Foo::callback()
{
    fprintf(stdout, "hello from the c++ callback function\n");
    return -1;
}

