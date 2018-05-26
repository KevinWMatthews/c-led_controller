#ifndef INTERRUPT_INCLUDED
#define INTERRUPT_INCLUDED

/*
 * Mock AVR library functions here for testing on a local build.
 *
 * Actual ISR vectors are defined are defined in chip-specific avr/io*.h files.
 * See, for example, <avr/iotnx61.h>.
 */


// #  define ISR(vector, ...)            \
//     void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
//     void vector (void)

// Provide function declaration and start of definition.
// ISR() is used as if it were a function name and is assumed
// to be followed by a function body:
//      ISR(<vector_name>)
//      {
//          // ...
//      }
#define ISR(vector) \
    void vector(void); \
    void vector(void)

/*
 * From <avr/interrupt.h>
 *      Enables interrupts by setting the global interrupt mask. This function
 *          actually compiles into a single line of assembly
 *      # define sei()  __asm__ __volatile__ ("sei" ::: "memory")
 *
 * Create a function that can be mocked to ensure that production code actually calls this macro.
 */
void sei(void);


#endif
