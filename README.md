This repo is to share some simple code snippets for integrating between python and c++, often using SWIG.

There are already tutorials out there this on this topic. I will add to that pile via my [nerd.mmccoo.com](nerd.mmccoo.com) blog. 
What it often missing is complete, compilable, functional code. Hench this repo.

I'm a linux guy. I test these on ubuntu. I've had very little success programming on windows, so I've basically given up there.

Here's what you'll find in this repo

## basic_python 
This snippet shows how to use SWIG to integrate simple c/c++ functions into python
 - this is basically a cut/paste from the [swig tutorial](http://www.swig.org/tutorial.html).
 - My contribution here is a makefile. In particular, note the test section of the makefile that runs the code.
## python_in_cxx_app
This snippet shows how to add python support to a c/c++ application
 - this is basically a cut/paste from the python documentation [about embedding](https://docs.python.org/3.5/extending/embedding.html)
## python_in_cxx_app_passing_data
This snippet extends python_in_cxx_app to add passing simple data back and forth
 - this began as a cut/paste from the python documentation
 - I've moved things around a bit to improve readability.
 - I've added the use of auto pointers [from the active state site](http://code.activestate.com/recipes/577985-automatic-python-pyobject-ref-count-management-in-)
## python_from_cxx
This snippet shows a way to add the ability to register python callback functions to a c/c++ app
 - this is basically a cut/paste from [this question on stackoverflow](http://stackoverflow.com/questions/12392703/what-is-the-cleanest-way-to-call-a-python-function-from-c-with-a-swig-wrapped). Again, I'm just making it a bit easier to get the code running. Again, note the test part of the makefile




