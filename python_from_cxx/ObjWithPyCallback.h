#include <Python.h>

class ObjWithPyCallback 
{
   public:

      ObjWithPyCallback();
      void setCallback(PyObject *callback);
      void call();

      PyObject *callback_;
};

