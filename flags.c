#include "main.h"

/**
* get_flags - Calculates active flags in a formatted str
* @ft: The formatted string containing flags
* @a: An int parameter
* Return: The calculated flags
*/
int get_flags(const char *ft, int *a)
{
  int b, c_i;
  int flgss = 0;
  const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
  const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

  for (c_i = *a + 1; ft[c_i] != '\0'; c_i++)
  {
    for (b = 0; FLAGS_CH[b] != '\0'; b++)
      if (ft[c_i] == FLAGS_CH[b])
      {
        flgss |= FLAGS_ARR[b];
        break;
      }
    if (FLAGS_CH[b] == 0)
      break;
  }
  *a = c_i - 1;
  return (flgss);
}
