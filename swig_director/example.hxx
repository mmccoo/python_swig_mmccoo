
#ifndef EXAMPLE_HPP_HH
#define EXAMPLE_HPP_HH
extern double My_variable;
extern int fact(int n);
extern int my_mod(int x, int y);
extern char *get_time();
extern int get_var();

class Foo {
public:
    virtual ~Foo() {}
    virtual int one();
    virtual int two(const char *str);
};

int call_director(Foo* foo);

#endif
