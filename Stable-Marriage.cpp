
#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   static int mp[3][3] = { {0,2,1},  //  Man Zero's preference
  {0,2,1},  // Man One's preference
      {1,2,0} // Man Two's preference
      }; 

   static int wp[3][3] = { {2,1,0},  // Woman Zero's preference
  {0,1,2},  // Woman One's preference
      {2,0,1} // Woman Two's preference
      }; 

// Conflict check
   for (int i = 0; i < c; i++) {                   
      if (q[i] == q[c]) { return false;}
      if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) 
      {return false;}
      if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) 
      {return false;}                           
   }
   return true;
}

void print(int q[]) {
   static int solution = 1;
   cout << "Solution #" << solution++ << ":"<<endl;
   cout<< "Man "<<" Woman "<<endl;
   for (int i = 0; i < 3; ++i)
      cout << i << "     " << q[i] <<endl;
      cout<< "----------------------"<<endl;
}
int main() {
  int q[3]= {};
  int c = 0;
  q[c] = 0;

while(c >= 0){
  c++;
  if(c==3){
    print(q);
    c--;
  } else q[c] = -1;  

  while(c >= 0) {
     q[c]++;

     if(q[c] == 3)
       c--;  
     else if (ok(q,c))
       break;   
  }
}
  return 0;
}
