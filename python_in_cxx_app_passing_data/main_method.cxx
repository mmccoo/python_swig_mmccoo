
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

    int argpos = 1;
    if (pModule == NULL) {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[argpos]);
        return 1;
    }
    fprintf(stdout, "loaded \"%s\"\n", argv[argpos]);
    argpos++;
    
    auto_pyptr pObjectClass(PyObject_GetAttrString(pModule, "myclass"));
    fprintf(stdout, "got object ");
    PyObject_Print(pObjectClass, stdout, Py_PRINT_RAW);
    fprintf(stdout, "\n");
    
    
    auto_pyptr pClassInst(PyObject_GetAttrString(pModule, argv[argpos]));
    /* pFunc is a new reference */
    fprintf(stdout, "got val ");
    PyObject_Print(pClassInst, stdout, Py_PRINT_RAW);
    fprintf(stdout, "\n");
    
    if (!pClassInst || !PyObject_IsInstance(pClassInst, pObjectClass)) {
        if (PyErr_Occurred()) { PyErr_Print(); }
        fprintf(stderr, "Cannot find class instance \"%s\"\n", argv[argpos]);
    }
    argpos++;
    
    auto_pyptr pMethodName(PyUnicode_DecodeFSDefault(argv[argpos]));
    argpos++;
    
    auto_pyptr pArgs(PyTuple_New(argc - argpos));
    for (int i = 0; i < argc - argpos; ++i) {
        auto_pyptr pValue(PyLong_FromLong(atoi(argv[i + argpos])));
        if (!pValue) {
            fprintf(stderr, "Cannot convert argument\n");
            return 1;
        }
        /* pValue reference stolen here: */
        PyTuple_SetItem(pArgs, i, pValue);
        pValue.report_stolen();
    }

    fprintf(stdout, "calling method now\n");
    // the NULL is important. you'll get a seg fault without it.
    auto_pyptr pValue(PyObject_CallMethodObjArgs(pClassInst, pMethodName, NULL));
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
