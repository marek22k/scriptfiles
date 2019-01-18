#ifndef MMINILANG_HPP
#define MMINILANG_HPP

#ifdef __cplusplus
    #include <istream>
    #include <ostream>
    #include <vector>

    #include <cstddef>
    #include <cmath>
#else
    #include <stddef.h>
    #include <math.h>
#endif

#define YP_ARG_1 std::istream &
#define YP_ARG_2 std::ostream &
#define YP_ARG_3 std::vector<double> &

/* decs */
int yyparse(YP_ARG_1, YP_ARG_2, YP_ARG_3);
unsigned gcd(unsigned, unsigned);
unsigned lcm(unsigned, unsigned);

#endif