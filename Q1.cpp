#include <iostream>
#include <vector>
#include <list>

using namespace std;

class base {
   int x;
   vector<double> v;
public:
   base(int y, vector<double> z): x{y}, v{z} {}

   void base_print() const {
      cout << "x = " << x << endl;
      cout << "v = ";
      for (auto e : v)
         cout << e << " ";
      cout << endl;
   }
};

class derived : public base {
   list<bool> l;
public:
   derived(int y, vector<double> z);
   derived(int y, vector<double> z, list<bool> el);
   void print() const;
};

derived::derived(int y, vector<double> z) : base(y, z), l() {
   // Initializes an empty bool list
}

derived::derived(int y, vector<double> z, list<bool> el) : base(y, z), l(el) {}

void derived::print() const {
   base_print(); // Call the inherited base class member function
   cout << "list = ";
   for (auto x : l)
       cout << x << " ";
   cout << endl;
}

int main() {
    derived d{10, {10, 2.5, 8.9}, {true, false, false}};
    d.print();
    return 0;
}
