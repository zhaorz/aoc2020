#include <iostream>

using std::cout;
using std::endl;

class Loop {
public:
  ~Loop() {
    Loop l;
    (void) l;
  }
};

int main() {
  cout << "sandbox" << endl;
  Loop l;
  (void) l;
}
