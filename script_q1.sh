foldername="output_new_1/n_Individuals_test_$(date +%y-%m-%d_%H-%M-%S)"
echo "folder name: $foldername"
mkdir -p "$foldername"

nIter=10000000
nIndividuals=1000


nTeams=30
#q1=3
q2=2

function first {
	for q1 in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	do
		echo "$nTeams teams and $nIter generations, with q1: $q1, q2: $q2 (q1 iterations)"
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
