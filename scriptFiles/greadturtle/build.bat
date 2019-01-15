@echo off
echo Build...

echo Create build folder
mkdir build
echo Step 1/4 (Create resources file)
windres --use-temp-file -i./greadturtle.rc -o./build/greadturtle_rc.o --define __WXMSW__ --define _UNICODE --include-dir %1\lib\gcc_lib\mswud --include-dir %1\include --include-dir . --define NOPCH
echo Step 2/4 (Compile main program)
g++ -c -o ./build/greadturtle.o greadturtle.cpp -O0 -mthreads -DHAVE_W32API_H -D__WXMSW__ -D_UNICODE -I%2 -I%1\lib\gcc_lib\mswud -I%1\include -W -Wall -I. -DNOPCH -Wno-ctor-dtor-privacy -MD -MP -Wall -Wextra -Wpedantic
echo Step 3/4 (Compile turtlescript)
g++ -c -o ./build/turtlescript.o turtlescript.cpp -O3 -Wall -Wextra -Wpedantic -I%2
echo Step 4/4 (Linking)
g++ -o ./build/greadturtle.exe ./build/greadturtle_rc.o ./build/greadturtle.o ./build/turtlescript.o -mthreads -L%1\lib\gcc_lib -Wl,--subsystem,windows -mwindows -lwxmsw31ud_core -lwxbase31ud -lwxtiffd -lwxjpegd -lwxpngd -lwxzlibd -lwxregexud -lwxexpatd   -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lshlwapi -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lversion -lwsock32 -lwininet -loleacc -luxtheme

echo Complete.
pause