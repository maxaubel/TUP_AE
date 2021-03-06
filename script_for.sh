foldername="output_new/$(date +%y-%m-%d_%H-%M-%S)"
echo "folder name: $foldername"
mkdir -p "$foldername"

nIter=10000000
nIndividuals=1000


function first {
	nTeams=4
	for q1 in 1 2
	do
		q2=1
		echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (first script)"
		python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
		python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
	done

	nTeams=6
	for q1 in 1 2 3
	do
		for q2 in 1
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (first script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done

	nTeams=8
	for q1 in 1 2 3 4
	do
		for q2 in 1 2
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (first script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done

	nTeams=10
	for q1 in 1 2 3 4
	do
		for q2 in 1 2
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (first script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done
}

function second {
	nTeams=12
	for q1 in 1 2 3 4
	do
		for q2 in 1 2
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (second script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done

	nTeams=14
	for q1 in 2 4 5 6
	do
		for q2 in 1 2
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (second script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done

	nTeams=16
	for q1 in 2 4 6 8
	do
		for q2 in 1 2 3
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (second script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done
}


function third {
	nTeams=18
	for q1 in 2 4 6 8 9
	do
		for q2 in 1 3
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (third script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done

	nTeams=20
	for q1 in 4 6 8 10
	do
		for q2 in 1 3 4
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (third script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done

	nTeams=30
	for q1 in 4 8 12 15
	do
		for q2 in 1 4 6 7
		do
			echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (third script)"
			python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
			./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
			python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
		done
	done
}


first &
second & 
third &

wait