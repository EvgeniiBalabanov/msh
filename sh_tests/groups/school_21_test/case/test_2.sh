echo $PWD; unset PWD
echo $PWD; export PWD=/ ; echo $PWD;
pwd; echo $PWD
cd; echo $PWD; cd -
echo $PWD; echo $OLDPWD
unset OLDPWD; echo $OLDPWD
cd; echo $OLDPWD
cd ; echo $PWD; echo $OLDPWD
cd -
pwd