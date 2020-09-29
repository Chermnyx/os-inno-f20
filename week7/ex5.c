#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char **s;
  char foo[] = "Hello World";
  /* my_code */
  s = malloc(sizeof(foo) * 1);  // 1st element
  /* /my_code */
  *s = foo;
  printf("s is %s\n",
         /* my_code */ */* /my_code */ s);  //  warning: format specifies type
                                            //  'char *' but the argument has
                                            //  type 'char **' [-Wformat]
  s[0] = foo;
  printf("s[0] is %s\n", s[0]);
  return (0);
}
