
#include <stdio.h>
#include <math.h>


void insertion(int arr[],int n){
   int i,j,key;
   
  for(int i =0;i<n;i++){
      key=arr[i];
      j=i-1;
     
    while(j>=0 && arr[j]>key){
    arr[j+1]=arr[j];
        j=j-1;
    }
      arr[j+1]=key;
     
  }
}

void printarray(int arr[],int n ){
 for (int i =0;i<n;i++){
     printf("%d ",arr[i]);
}
}

int main(){
 int arr[]={27,55,84,26,12};
  int n =sizeof(arr)/sizeof(arr[0]);
  printarray( arr,n);
  printf("\n");
  insertion(arr,n);
   printarray( arr,n);
  return 0;
   
}