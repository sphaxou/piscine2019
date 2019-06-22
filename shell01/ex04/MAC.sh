ifconfig -a | grep "ether" | sed 's/ether //' |sed 's/ //g' | sed 's/^.//'
