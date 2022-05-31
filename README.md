# Eva
#### Eva ecosystem - launch base for future languages
Welcome to the Eva ecosystem, I'm Andrea and, if you want, I'll take you inside hand in hand of this crazy but at the same time very fun and educational project.

### What is the purpose?
Eva was born with the aim of creating an ecosystem to help those who have the desire to give birth to its own programming language, even just for fun.
Cooming soon...

```c
#define __EVA_ARCH_FILE "myarch.h" // define your architecture
#include "eva/eva.h"               // place eva sources into a (sub)directory
#include "mylang.h"                // language compiler

#define ubyte n8_t
#define ulong n64_t

int main(int argc, const char *argv[]) {
  if (argc < 2)
    eva_fatal(EVA_NULL, "no input source");
  
  mylang_t ml; // compiler
  mylang_init(&ml);
  for (int i = 1; i < argc; ++i)
    mylang_add_source(&ml, argv[i]);
  mylang_compile(&ml);
  
  ubyte *img;
  ulong  len;
  
  if (EVA_SUCCESS != mylang_gen_image(&ml, &img, &len)) {
    mylang_clear(&ml);
    return EXIT_FAILURE;
  }
  
  eva_t eva;
  eva_init(&eva);
  
  if (EVA_SUCCESS != eva_load_image(&eva, img, len)) {
    mylang_clear(&ml);
    return EXIT_FAILURE;
  }
  mylang_clear(&ml);
  
  int res = eva_start(&eva, 120);
  eva_clear(&eva);
  
  return res;
}

```
