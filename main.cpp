#include<iostream>
using namespace std;

int main()
{
  int number = 0;
  int count = 0;
  int sum = 0;
  int max = 0;
  while (cin >> number && number > 0)
  {
    if (number < 10)
    {
      if (max < number) max = number;
      count++;
      sum += number;
    }
  }

  cout << "Sum: " << sum << endl;
  cout << "Max: " << max << endl;
  cout << "Average: " << sum/(count * 1.0) << endl;

  return 0;
}