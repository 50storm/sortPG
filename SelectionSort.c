#include <stdio.h>

int COMPARE_COUNT=0;

int Swap(int X[], int n, int m){
      int tmp;

      tmp  = X[n];
      X[n] = X[m];
      X[m] = tmp;
      return 0;

}

int Selection_Sort(int X[], int num){
      int i,j,max;
      for(i=num-1; i > 0; i--)
      {
            max=0;
            for(j=1; j<=i ; j++)
            {
                  COMPARE_COUNT++;
                   //仮の最大値より、大きい値が見つかったら、インデックスを設定し直す
                  if(X[max] < X[j]) max=j;
            }
            Swap(X,i,max);
      }
      return 0;

}

int main(){
      int Data[] ={ 29, 13, 52, 92, 48, 31, 65, 71};
      int i, rc;

      printf("Before: \n");
      for(i=0; i<8 ; i++) printf("%d \t", Data[i]);
      printf("\n");

      rc = Selection_Sort(Data,8);
      
      printf("After: \n");
      for(i=0; i<8 ; i++) printf("%d \t", Data[i]);
      printf("\nComparing: %d tmes \n", COMPARE_COUNT);
      
      return 0;

}
