#include "stack.cpp"
using namespace std;

int main()
{
  int ch, size;
  char element;
  int i = 1;
  cout << "Enter the size of stack: ";
  cin >> size;
  Stack <char> stack(size);
  while (i)
  {
    cout << "Enter your choice (1-4): " << endl;
    cout << "1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "Enter the element to push: ";
      cin >> element;
      stack.push(element);
      break;
    case 2:
      stack.pop();
      break;
    case 3:
      stack.peek();
      break;
    case 4:
      stack.displayStack();
      break;
    case 5:
      i = 0;
      break;
    default:
      cout << "Wrong Choice!!!!" << endl;
      break;
    }
  }
  return 0;
}
