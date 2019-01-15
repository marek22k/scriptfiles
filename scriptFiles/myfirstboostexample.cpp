#include <iostream>  /* cout */
#include <initializer_list>  /* initializer_list */

#include <cstddef>  /* size_t */

#include <boost/any.hpp>  /* any, any_cast */
#include <boost/dynamic_bitset.hpp> /* dynamic_bitset */
#include <boost/foreach.hpp>  /* BOOST_FOREACH */

/* optional */
#if __cplusplus < 201703L
    #include <boost/optional.hpp>
#else
    #include <optional>
#endif

using namespace std;
using namespace boost;

// Typedefs
typedef struct {
    dynamic_bitset<> bits;
} byte;

typedef decltype(byte().bits) bits;
// typedef dynamic_bitset<> bits;


// Function declarations
bits DynamischesBitsetErstellen(initializer_list<optional<bool>>);

int main()
{
    any db = DynamischesBitsetErstellen({1, 0, 1, {}, 0, {}, 1, 0});
byte b ;

    for(size_t i = 0; i < any_cast<bits>(db).size(); i++)
        cout << any_cast<bits>(db)[i] << ((i+1)%4==0?" ":"");
    return 0;
}

// Function definitions
bits DynamischesBitsetErstellen(initializer_list<optional<bool>> il)
{
    bits db;

    BOOST_FOREACH(optional<bool> b, il)
        db.push_back(b.value_or(0));

    return db;
}
