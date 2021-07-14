echo bonjour > $test w/ test="o1 o2"

cat $test
cat o1
cat o2

rm -rf o1 o2 $test