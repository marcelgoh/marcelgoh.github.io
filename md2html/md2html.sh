
for i in ./*.md; do
    cat "preamble.txt" > "${i%.*}.html";
    sed -i "s/{{ site.baseurl }}//g" "$i"
    pandoc -f markdown --mathjax "$i" >> "${i%.*}.html";
    cat "postamble.txt" >> "${i%.*}.html";
done;
