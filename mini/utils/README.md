# Test command for redirections

## Create / Rewrite the whole file

echo "Hello, world!" > output.txt

## This appends to the file

echo "Additional text." >> output.txt

## Reads from the file

cat < input.txt

cat << EOF

## To do

1. env variables
2. Edge cases
3. formatting

