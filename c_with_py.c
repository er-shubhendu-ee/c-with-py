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
	exe_pycode("print(1+1)");
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
