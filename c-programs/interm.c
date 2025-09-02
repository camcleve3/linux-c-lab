#include <stdio.h>
int add(int a, int b){
   return a + b;	
}
int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num > 0) printf("Positive\n");
  else printf("Non-positive\n");
	  
 printf("%d\n", add(3,4));

return 0;
}
