#include <Python.h>

/*
 * Function called from Python
 */
static PyObject* function(PyObject* self, PyObject* args)
{
    return Py_BuildValue("s", "Hello world");
}

/*
 * Binding for python functions to our C
 */
static PyMethodDef myModule_methods[] = {
        {"hello_world", function, METH_VARARGS},
        {NULL, NULL}
};

/*
 * Initialize module
 */
void initmyNativeModule()
{
    (void) Py_InitModule("myNativeModule", myModule_methods);
}