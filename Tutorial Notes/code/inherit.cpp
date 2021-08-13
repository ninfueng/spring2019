#include <iostream>

// TODO: make a pure function int get_id()
class A {
    public:
        virtual int get_id() = 0;

};

// TODO: override get_id(), return 1
class B : public A {
    public:
        int get_id() override {
            return 1;
        }
};

// TODO: override get_id(), return 2
class C : public B {
    public:
        int get_id() override {
            return 2;
        }
};


int main()
{   
    C c;

    // print out c's ID
    std::cout << c.get_id() << std::endl;

    // TODO: cast c to type B. Call get_id(). What happens?
//    B* b;
//    b = reinterpret_cast<B*>(&c);

    B b;
    b = static_cast<B>(c);
    std::cout << b.get_id() << std::endl;

    // TODO: cast c to type A. Is this possible?
    A* a;
    a = reinterpret_cast<A*>(&c);
    std::cout << a->get_id() << std::endl;

    // TODO: Set some B *bptr to the address of c. Call get_id(). What happens?
    // Do the same for a variable A *aptr. What do you notice?
    B *bptr = nullptr;
    A *aptr = nullptr;
    bptr = &c;
    aptr = &c;
//    A *aptr = new A;
//    B *bptr = new B;
    std::cout << bptr->get_id() << std::endl;
    std::cout << aptr->get_id() << std::endl;
//
//    delete aptr;
//    delete bptr;
    return 0;
}
