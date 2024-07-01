# COMMANDS

## Echo

echo "hello world"
echo 'hello world'
echo -n "hello world"
echo -n 'hello world'


echo '"hello world"'
echo "'hello world'"
echo -n '"hello world"'
echo -n "'hello world'"

echo -n "$HOME"
echo -n '$HOME'

## Echo and env

echo '"$HOME"'
echo "'$HOME'"
echo -n '"$HOME"'
echo -n "'$HOME'"

echo '$HOME/'
echo "$HOME/"
echo -n '$HOME/'
echo -n "$HOME/"

<!-- Not done 
echo $?
echo -n $?
-->

## Cds

cd $HOME
cd -
cd "../"
cd "./"
cd "~/"

<!-- ** "cd ."  does nothing .. so ignore -->
<!--  change to absolute / relative directory
tilde
cd ~

Relative Paths
cd ../
cd ../../
cd ../42
remain in same directory
cd ./
cd ./anotherfile.txt
cd /Users/eddieseet/MDesktop/Curr/minishell/utils
cd /Users/eddieseet/MDesktop
cd /bin
 cd /etc/hosts** 
 -->

## ENV

<!-- to check -->
env
export MY_VAR="Hello, World!"
unset MY_VAR
env

## Some others

to do

## By Aqil
unset PATH, to test if common commands can still be used or not
