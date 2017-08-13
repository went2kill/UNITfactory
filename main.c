#include "ft_printf.h"

int main() {
    int i;
    i = ft_printf("%10s is a string", "this");
    printf("<-%d\n", i);
    i = printf("%10s is a string", "this");
    printf("<-%d\n", i);
  return (0);
}
