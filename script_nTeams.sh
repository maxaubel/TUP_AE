foldername="output_new/n_Individuals_test_$(date +%y-%m-%d_%H-%M-%S)"
echo "folder name: $foldername"
mkdir -p "$foldername"

nIter=10000000
#nIndividuals=1000

nIndividuals=2000
q1=3
q2=2

function first {
	for nTeams in 4 6 8 10 12 14 16 18 20 30
	do
		echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (second script)"
		python alert.py working on $nTeams teams, $nIter, $nIndividuals individuals
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt
		python alert.py "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt ./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} `tail -n 30 "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt`
	done
}





#first &
#second & 
#third &
first
wait
