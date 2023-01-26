#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
int array[9];


int  **temp;

int **allocate_memory(){
    temp=(int **)malloc(sizeof(int *)*9);
    for(int i=0;i<9;i++){
      temp[i]=(int *)malloc(sizeof(int)*9);
        for(int j=0;j<9;j++)
          temp[i][j]=-1;
      }
    return temp;
}


void initialise(int *arr){
  for(int i=0;i<9;i++)
     arr[i]=-1;
}

bool append(int col,int val){
 for(int j=0;j<9;j++){
   if(temp[col][j]==-1){
      temp[col][j]=val;
      return true;
   }   
   else if(val==temp[col][j])
     return false;
 }
return true;
}

int count=0;
int called=0;
bool validSolution(unsigned int board[9][9]){
   allocate_memory();
   for(int i=0;i<9;i++){
     initialise(array);
     for(int j=0;j<9;j++){
       if(board[i][j]==0)
         return false;
      else if(array[board[i][j]-1]==1)
         return false;
     else
       array[board[i][j]-1]=1;       
     if(!append(j,board[i][j]))
         return false;
     }
   }
  
   //check 3*3 matrix
   for(int i=0,j=1,k=2; k<9; i=i+3,j=j+3,k=k+3){
    initialise(array);
    for(int z=0;z<3;z++){     
        if(array[temp[i][z]-1]==-1)
           array[temp[i][z]-1]=1;       
        else 
           return false;
      
        if(array[temp[j][z]-1]==-1)
          array[temp[j][z]-1]=1;               
        else
           return false;
      
        if(array[temp[k][z]-1]==-1)
           array[temp[k][z]-1]=1;                
        else
           return false;       
     }           
     initialise(array);
     for(int z=3;z<6;z++){
          if(array[temp[i][z]-1]==-1)     
            array[temp[i][z]-1]=1;       
         else
            return false;
       
        if(array[temp[j][z]-1]==-1)
           array[temp[j][z]-1]=1;
               
        else
           return false;
       
        if(array[temp[k][z]-1]==-1)
          array[temp[k][z]-1]=1;
                  
        else
           return false;      
    }

   initialise(array);  
   for(int z=6;z<9;z++){
    if(array[temp[i][z]-1]==-1)
        array[temp[i][z]-1]=1;
           
    else
       return false;
   if(array[temp[j][z]-1]==-1)
       array[temp[j][z]-1]=1;
          
   else
       return false;
   if(array[temp[k][z]-1]==-1)
       array[temp[k][z]-1]=1;
       
   else
       return false;
   } 
    
 }
free(temp);
 return true;
}

int main(){
unsigned int board[9][9]={
  {5, 3, 4, 6, 7, 8, 9, 1, 2},
  {6, 7, 2, 1, 9, 5, 3, 4, 8},
  {1, 9, 8, 3, 4, 2, 5, 6, 7},
  {8, 5, 9, 7, 6, 1, 4, 2, 3},
  {4, 2, 6, 8, 5, 3, 7, 9, 1},
  {7, 1, 3, 9, 2, 4, 8, 5, 6},
  {9, 6, 1, 5, 3, 7, 2, 8, 4},
  {2, 8, 7, 4, 1, 9, 6, 3, 5},
  {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

if(validSolution(board)==1)
  printf("Valid solution\n");
else
  printf("Invalid solution\n");

}

