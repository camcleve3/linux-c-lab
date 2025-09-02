read -p "Enter a filename to check: " FILE

if [ -f "$FILE" ]; then
    echo "File '$FILE' exists."
    ls -l "$FILE"
else
    echo "File '$FILE' does not exist."
fi
