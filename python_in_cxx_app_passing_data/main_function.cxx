
// This code was copied from here:
// https://docs.python.org/3.5/extending/embedding.html

#include <Python.h>
#include <auto_pyptr.h>

#include <iostream>

// I've put this stuff into a function because I'm using
// auto_ptrs. We don't want to decrement PyObjects after
// PyFinalize. If you don't understand what this means,
// don't worry about it.
int run_python_stuff(int argc, char *argv[])
{
    auto_pyptr pName(PyUnicode_DecodeFSDefault(argv[1]));
    /* Error checking of pName left out */
    
    auto_pyptr pModule(PyImport_Import(pName));

    if (pModule == NULL) {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    
    auto_pyptr pFunc(PyObject_GetAttrString(pModule, argv[2]));
    /* pFunc is a new reference */

    if (!pFunc || !PyCallable_Check(pFunc)) {
        if (PyErr_Occurred()) { PyErr_Print(); }
        fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
    }

    auto_pyptr pArgs(PyTuple_New(argc - 3));
    for (int i = 0; i < argc - 3; ++i) {
        auto_pyptr pValue(PyLong_FromLong(atoi(argv[i + 3])));
        if (!pValue) {
            fprintf(stderr, "Cannot convert argument\n");
            return 1;
        }
        /* pValue reference stolen here: */
        PyTuple_SetItem(pArgs, i, pValue);
        pValue.report_stolen();
    }
    auto_pyptr pValue(PyObject_CallObject(pFunc, pArgs));
    if (pValue == NULL) {
        PyErr_Print();
        fprintf(stderr,"Call failed\n");
        return 1;
    }
    printf("Result of call: %ld\n", PyLong_AsLong(pValue));
    return 0;
}

int
main(int argc, char *argv[])
{

    if (argc < 3) {
        fprintf(stderr,"Usage: call pythonfile funcname [args]\n");
        return 1;
    }

    Py_Initialize();
    int retval = run_python_stuff(argc, argv);
    Py_Finalize();
    return retval;
}
