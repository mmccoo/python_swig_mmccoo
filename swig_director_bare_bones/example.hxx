
#ifndef EXAMPLE_HPP_HH
#define EXAMPLE_HPP_HH

class Foo {
public:
    virtual ~Foo() {}
    virtual int callback();
};

void set_foo(Foo *foo);
int call_foo_callback();

#endif
