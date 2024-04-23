#include "library/ft_printf.h"
#include <limits.h>

int main(void){
	
      char *test = "int %d hex %x HEX %X unsinged %u int %i string %s char %c pointer %p percent %%\n";
      unsigned int i = UINT16_MAX;
      int in = INT_MIN;
      char * str= "test";



   //printf(test, in);
   ft_printf(test, in, i, i , i, in, str, str[0]);
   ft_printf(test, in, i, i , i, in, str, str[0]);

   
}
