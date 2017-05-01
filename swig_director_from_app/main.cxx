
#include <string>
#include <stdio.h>

#include <Python.h>

#include <example.hxx>

static wchar_t* charToWChar(const char* text)
{
    const size_t size = strlen(text) + 1;
    wchar_t* wText = new wchar_t[size];
    mbstowcs(wText, text, size);
    return wText;
}

static Foo *localfoo = NULL;
void register_cb(Foo *foo)
{
    localfoo = foo;
}


int
main(int argc, char *argv[])
{
    // if you get an error complaining about not being able to convert
    // char* to wchar*, you're missing some compile flags. python-config --cflags
    // is your friend
    Py_SetProgramName(charToWChar(argv[0]));  /* optional but recommended */
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is',ctime(time()))\n"
                       "import sys; sys.path.append('.')\n");
    printf("importing main\n");
    PyRun_SimpleString("import main");

    if (localfoo == NULL) {
        printf("localfoo is still null\n");
    } else {
        printf("foo->one %d\n", localfoo->one());
        printf("foo->two %d\n", localfoo->two("from main"));
    }
    Py_Finalize();
    return 0;
}

