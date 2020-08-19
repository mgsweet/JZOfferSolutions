# Solution 1
i=0
cat file.txt | while read line
do
	i=$i+1
	if [[ $i -eq 10 ]]
	then
		echo $line
        break
	fi
done

# Solution 2
sed -n 10p file.txt
