for f in */*/Description.txt;
do mv "$f" "$(dirname "$f")/README.md";
done
