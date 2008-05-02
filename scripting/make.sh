swig -c++ -ruby -Iinclude swig.i
g++ -I. -I/usr/local/lib/ruby/1.8/i686-linux -I/usr/local/lib/ruby/1.8/i686-linux -I.  -fPIC -g -O2  -fPIC -I../include  -c swig_wrap.cxx
gcc -shared -o ruby/cigi.so swig_wrap.o -L'.' -L'/usr/local/lib' -Wl,-R'/usr/local/lib' -L.  -rdynamic -Wl,-export-dynamic    -Wl,-R -Wl,/usr/local/lib -L/usr/local/lib -lruby  -ldl -lcrypt -lm   -lc -L/usr/local/lib -lcigicl
