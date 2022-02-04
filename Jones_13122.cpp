#include <iostream>
using namespace std;

int main()
{
  int i,j,m,n;
  int matching_cards [3][3]={{1,2,3},{2,3,1},{3,1,2}};
  for (int i=0; i<n ;i++)
  for (int j=0; j<m; j++)
  {
    cout << "Enter a value";
    cin >> matching_cards[i][j];
  }
  if (i == j)
    cout << "Congratulations! You found a match! Do you want to play again or exit?" << endl;
  else
    cout << "Not a match. Try again" << endl;
  return 0;
}
