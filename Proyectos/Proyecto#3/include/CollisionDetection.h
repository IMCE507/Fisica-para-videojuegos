#include <Box2D/include/box2d.h>
#include <iostream>

using namespace std;

class MyContactListener : public b2ContactListener
{
    bool longBoolean;
    void BeginContact(b2Contact* contact)
    {

        b2Fixture* f1 = contact->GetFixtureA();
        b2Fixture* f2 = contact->GetFixtureB();

        b2FixtureUserData o1 = f1->GetUserData();
        b2FixtureUserData o2 = f2->GetUserData();
   
        longBoolean = (o1.pointer == 69 && o2.pointer == 7) || (o1.pointer == 69 && o2.pointer == 99) || (o1.pointer == 69) && (o2.pointer == 420) || (o1.pointer == 69) && (o2.pointer == 1) || (o1.pointer == 69) && (o2.pointer == 20) || (o1.pointer == 69) && (o2.pointer == 16);

        if (longBoolean)
        {
            onAir = false;
            cout << "Ground touched" << endl;
        }
    }

    void EndContact(b2Contact* contact)
    {
        b2Fixture* f1 = contact->GetFixtureA();
        b2Fixture* f2 = contact->GetFixtureB();

        b2FixtureUserData o1 = f1->GetUserData();
        b2FixtureUserData o2 = f2->GetUserData();

        longBoolean = (o1.pointer == 69 && o2.pointer == 7) || (o1.pointer == 69 && o2.pointer == 99) || (o1.pointer == 69) && (o2.pointer == 420) || (o1.pointer == 69) && (o2.pointer == 1);

        if (longBoolean)
        {
            onAir = true;
            cout << "Ground left" << endl;
        }

    }

public:
    bool onAir = false;
};
