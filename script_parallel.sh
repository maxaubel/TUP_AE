foldername="output/$(date +%d-%m-%y_%H-%M-%S)"
echo "folder name: $foldername"
mkdir -p "$foldername"

nIter=1000
nIndividuals=1000

nTeams=4
for q1 in 1 2
do
	q2=1
	./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
done

nTeams=6
for q1 in 1 2 3
do
	for q2 in 1
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nTeams=8
for q1 in 1 2 3 4
do
	for q2 in 1 2
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nTeams=10
for q1 in 1 2 3 4
do
	for q2 in 1 2
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nIter=10000000
nTeams=12
for q1 in 1 2 3 4
do
	for q2 in 1 2
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nTeams=14
for q1 in 2 4 5 6
do
	for q2 in 1 2
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nTeams=16
for q1 in 2 4 6 8
do
	for q2 in 1 2 3
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nTeams=18
for q1 in 2 4 6 8 9
do
	for q2 in 1 3
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done



nTeams=20
for q1 in 4 6 8 10
do
	for q2 in 1 3 4
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done

nTeams=30
for q1 in 4 8 12 15
do
	for q2 in 1 4 6 7
	do
		./TUP instances/umps${nTeams}.txt ${q1} ${q2} ${nIter} ${nIndividuals} > "$foldername"/umps${nTeams}_${q1}_${q2}_${nIter}_${nIndividuals}.txt &
	done
done


wait