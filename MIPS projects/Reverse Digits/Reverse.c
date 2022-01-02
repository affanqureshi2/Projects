#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/

void revNum(int v1[])
{
  int out[3];               //output display array
  int j = 0;
  for (int i = 2;i >= 0;i--)// Reverse loop to get reverse values of input index
  {
  out[j] = v1[i];           //index store last value of input array in first index of output array
  j++;                      //increments output index
  }
  for (int i = 0;i <= 2;i++) // now i is output index and it display the values in reverse order
  printf("%d",out[i]);
}

void main(void) {
int v1[3] = {1,2,3};// input array
revNum(v1);

}

/*************************** End of file ****************************/

