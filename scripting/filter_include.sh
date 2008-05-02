rm ./include/*.h

for f in ../include/*.h; do
  sed 's/CIGI_SPEC //g' < $f | grep -v 'const static' > include/$f
done
