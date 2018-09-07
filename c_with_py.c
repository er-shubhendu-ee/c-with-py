#include "Python.h"

#ifndef UNICODE
	#define UNICODE
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#if PY_MAJOR_VERSION >= 3
	#define IS_PY3K
#endif

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_py_info(void);
void exe_py_code(const char *code);
int exe_py_module(int, char **);


int main(int argc, char *argv[])
<<<<<<< HEAD
{
//	get_py_info();
	printf("test point 1 in c\n");
	exe_py_module(argc, argv);
	return 0;
}


int exe_py_module(int argc, char **argv)
{
	 PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    if (argc < 3) 
    {
        printf("Usage: exe_name python_source function_name\n");
        return 1;
    }

    // Initialize the Python Interpreter
    Py_Initialize();
    // Build the name object
    pName = PyUnicode_FromString(argv[1]);
    printf("Argument string: \n%s\n",argv[1]);
    printf("Converted string: \n%s\n",PyUnicode_AsUTF8(pName));

    // Load the module object
    pModule = PyImport_Import(pName);
    
    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);

    // pFunc is also a borrowed reference 
    pFunc = PyDict_GetItemString(pDict, argv[2]);

    if (PyCallable_Check(pFunc)==1) 
    {
        PyObject_CallObject(pFunc, NULL);
        printf("test point 3 in c\n");
    }
	else 
    {
    	printf("Python call formation error.\n");
        PyErr_Print();
    }

    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

    return 0;
=======
{
	exe_pycode("print(1+1)");
	return 0;
>>>>>>> parent of 747536b... Merge pull request #1 from er-shubhendu-ee/office
}

int get_py_info(void)
{
		printf("Getting Python information.............\n");
	Py_Initialize();
	if(!Py_IsInitialized())
	{
		puts("Unable to initialize Python interpreter.");
		return 1;
	}
	printf("Prefix: %s\nExec Prefix: %s\nPython Path: %s\n",
			Py_GetPrefix(),
			Py_GetExecPrefix(),
			Py_GetProgramFullPath());
	printf("\n");
	printf("Full path: %s\nModule Path: %s\n",
			Py_GetProgramFullPath(),
			Py_GetPath());
	printf("\n");
	printf("Version: %s\nPlatform: %s\nCopyright: %s\n",
			Py_GetVersion(),
			Py_GetPlatform(),
			Py_GetCopyright());
	printf("\n");
	printf("Compiler String: %s\nBuild Info: %s\n",
			Py_GetCompiler(),
			Py_GetBuildInfo());
			Py_Finalize();
	return 0;

}


void exe_pycode(const char* code)
{
	Py_Initialize();
	PyRun_SimpleString(code);
	Py_Finalize();
}
