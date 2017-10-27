#ifndef BIT_MANIP_INCLUDED
#define BIT_MANIP_INCLUDED

#define SBI(reg, bit) (reg) |= (1<<(bit))
#define CBI(reg, bit) (reg) &= ~(1<<(bit))

#endif
