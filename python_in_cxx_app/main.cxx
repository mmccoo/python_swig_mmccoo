
#include <string>

#include <Python.h>

static wchar_t* charToWChar(const char* text)
{
    const size_t size = strlen(text) + 1;
    wchar_t* wText = new wchar_t[size];
    mbstowcs(wText, text, size);
    return wText;
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
                       "print('Today is',ctime(time()))\n");
    Py_Finalize();
    return 0;
}

