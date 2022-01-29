#include <ecl/ecl.h>
extern void init_hello(cl_object cblock);

int
main(int argc, char **argv)
{
    /* setup the lisp runtime */
    cl_boot(argc, argv);

    /* call the init function via ecl_init_module */
    ecl_init_module(NULL, init_hello);

    /* ... */

    /* shutdown the lisp runtime */
    cl_shutdown();

    return 0;
}
