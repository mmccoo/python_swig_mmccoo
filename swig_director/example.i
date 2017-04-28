/* example.i */
%module(directors="1") example

%{
#include <example.hxx>
%}

%feature("director") Foo;
%include <example.hxx>


