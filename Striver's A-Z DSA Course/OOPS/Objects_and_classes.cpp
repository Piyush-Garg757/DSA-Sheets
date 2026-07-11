#include <bits/stdc++.h>
// #include "hero.cpp"  agar kisi aur file mein banaya hai class to iss file mein include kar sakte hain
using namespace std;

class hero
{
public: // ye properties kahi bhi acceess kar sakte hain
    string name;
    int health;
    void getscore() // getter
    {
        return health;
    }
    void setscore(int s) // setter
    {
        score = s;
    }
    hero(int health) // constructor function
    {
        cout << "Constructor called";
        this->health = health
    }
    // Copy constructor
    hero(hero &temp)
    {
        // To create a deep copy
        char *a = new char[strlen(temp.name) + 1];
        strcpy(ch.temp.name);
        this->name = ch;

        this->health = temp.health;
        this->score = temp.score;
    }

    // Destructor
    ~hero()
    {
        cout << "abc";
    }

private: // ye properties bas class ke andar access kar sakte hain
    int score;
};

class spidey : public hero
{
    // ye hua inheritance
    // spidey ke paas hero ki abilities to hain hi saath saath mein apni bhi hain
};
int main()
{
    hero h1;             // Static allocation
    hero *h2 = new hero; // Dynamic allocation
    // aur jab dynamically banaya ho to baar baar properties ya functions access karne ke liye (*h2).score  aise karo ya fir h2->score
    cout << sizeof(h1);
    // h1 ek object ban gaya hero class ka   aur jab int hoga ek hero ke andar  to h1 ka size 4 ata  but jab empty class hai to 1 byte memory allocate hoti hai

    // jab bhi ek class ka object create karte hain to automatically construtor call hota hai  upar vale case mein h1.hero aur h2.hero call hoga

    // agar chahe to khud ka constructor bhi define kar sakte hain aur aisa karne pe default vala constructor hat jayega
    // aur koi parameter pass karenge to this ka use karna yaad rakhna where this is a pointer to the current object

    hero h4(h3) // to h4 mein h3 ki cheezein copy ho jayengi aur ye copy constructor ke through hota hai
                // ise bhi khud ka bana skte hain aur ismein bhi same hoga default vala hat jayega  aur ye deep copy nahi banata hai shallow copy banata hai by default    deep copy banane ke liye thodi mehant kani padegi

        h2 = h1;
    // ye likhne pe h1 ki values h2 mein aa gayi
    // iss case mein h2 already formed tha

    // aise hi destructor use hota hai memory free karne ke liye   aur ismein bhi same cheex vahi sab

    // inheritance -> upar spidey vala
    /*
1️⃣ Single Inheritance
Jab ek derived class, sirf ek base class se inherit karti hai.
Syntax:
class Derived : public Base {};

2️⃣ Multiple Inheritance
Jab ek derived class, ek se zyada base classes se inherit karti hai.
Syntax:
class Derived : public Base1, public Base2 {};

3️⃣ Multilevel Inheritance
Jab ek class, dusri class se inherit karti hai aur wahi class aage kisi aur ko inherit karti hai.
Syntax:
class B : public A {};
class C : public B {};

4️⃣ Hierarchical Inheritance
Jab ek hi base class se multiple derived classes inherit karti hain.
Syntax:
class B : public A {};
class C : public A {};

5️⃣ Hybrid Inheritance
Jab do ya do se zyada types of inheritance ka combination use hota hai.
Syntax:
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};*/
    // encapsulation -> class banana hi encapsulation hai
    // Polymorphism
    /*
    Polymorphism ka matlab hota hai “ek hi function ya object ka alag-alag form mein behave karna”.

🔹 Types of Polymorphism in C++
1️⃣ Compile Time Polymorphism

Jab function ka decision compile time par ho jata hai.

Types:

Function Overloading

Operator Overloading

Example (Function Overloading):

class A {
public:
    int add(int a, int b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

2️⃣ Runtime Polymorphism

Jab function ka decision program run hone ke baad hota hai.

👉 Iske liye inheritance + virtual function use hota hai.

Example:

class Base {
public:
    virtual void show() {
        cout << "Base class show" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show" << endl;
    }
};*/
    // Abstraction -> Abstraction ka matlab hota hai sirf important details dikhana aur internal implementation chhupa dena.
    return 0;
}