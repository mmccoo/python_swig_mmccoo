#include "ObjWithPyCallback.h"

#include <iostream>

ObjWithPyCallback::ObjWithPyCallback() : callback_(NULL) {}

void ObjWithPyCallback::setCallback(PyObject* callback)
{
   if (!PyCallable_Check(callback))
   {
      std::cerr << "Object is not callable.\n";
   }
   else
   {
      if ( callback_ ) Py_XDECREF(callback_);
      callback_ = callback;
      Py_XINCREF(callback_);
   }
}

void ObjWithPyCallback::call()
{
   if ( ! callback_ )
   {
      std::cerr << "No callback is set.\n";
   }
   else
   {
      // I want to call "callback_(*this)", how to do this cleanly?
      PyObject *result = PyObject_CallFunction(callback_, "");
      if (result == NULL)
         std::cerr << "Callback call failed.\n";
      else
         Py_DECREF(result);
   }
}

