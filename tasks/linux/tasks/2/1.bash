find *.txt | xargs basename -s .txt | xargs -i mv {}.txt {}.md
