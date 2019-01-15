#include <iostream>  /* std::cout, std::endl */
#include <optional>  /* std::optional, std::bad_optional_access */
#include <typeinfo>  /* operator typeid */

using namespace std;

#define TYPE_EQL(type1, type2) (static_cast<bool>(typeid(type1)==typeid(type2)?sizeof(type1)==sizeof(type2)?1:0:0))

int main()
{
    optional<int> x;
    x = 2;

    cout << *x << x.value() << endl;  // Output: 22

    x = {};
    cout << x.value_or(-1) << endl;  // Output: -1
    *x = 2;

    optional<optional<int>> y = x;
    cout << **y << endl;  // Output: 2

    **y = *x = {};

    try
    {                               //           ||
        cout << x.value() << endl;  // No output \/
    }
    catch(const bad_optional_access & e)
    {
        cout << "Error: " << e.what() << endl;  // Output: Error: bad optional access
    }

    cout << typeid(x).name() << endl << typeid(y).name() << endl;  // Output: St8optionalIiE + endl + St8optionalIS_IiEE
    cout << TYPE_EQL(x, y) << endl;  // Output: 0

    optional<int> z;

    cout << TYPE_EQL(x, z) << endl;  //Output: 1
	return 0;
}
