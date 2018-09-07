#ifndef UNICODE
	#define UNICODE
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "Python.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void exe_pycode(const char* code);
void exe_py_interpreter(int , char **);



int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
	
	for(i=0;i<argc; i++)
	{
		printf("argc: %d, argv[%d]= %s\n",i,i,argv[i]);
	}
    if (argc < 3) 
    {
        printf("Usage: exe_name python_source function_name\n");
        return 1;
    }

    if (argc < 3) {
        fprintf(stderr,"Usage: call pythonfile funcname [args]\n");
        return 1;
    }

    Py_Initialize();

//    pName = PyUnicode_DecodeFSDefault(argv[1]);
	pName = PyUnicode_FromString(argv[1]);

    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, argv[2]);
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(argc - 3);
            for (i = 0; i < argc - 3; ++i) {
                pValue = PyLong_FromLong(atoi(argv[i + 3]));
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return 1;
                }
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}

void exe_py_interpreter(int argc, char** argv)
{
	int i;
	for(i=0;i<argc;i++)
	{
		printf("argc: %d\n",argc);
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	Py_Initialize();
	Py_Main(argc, (wchar_t **) argv);
	Py_Finalize();
}

void exe_pycode(const char* code)
{
	Py_Initialize();
	PyRun_SimpleString(code);
	Py_Finalize();
}
