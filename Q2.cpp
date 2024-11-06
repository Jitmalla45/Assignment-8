#include <iostream>

class Base {
public:
    virtual void iam() { std::cout << "Base\n"; }
};

class D1 : public Base {
public:
    void iam() override { std::cout << "D1\n"; }
};

class D2 : public Base {
public:
    void iam() override { std::cout << "D2\n"; }
};

void print(Base* bptr) {
    bptr->iam(); // Calls the appropriate iam() function based on the object's actual type
}

int main() {
    Base b;
    D1 d1;
    D2 d2;
    
    print(&b);  // Expected output: "Base"
    print(&d1); // Expected output: "D1"
    print(&d2); // Expected output: "D2"
    
    return 0;
}
