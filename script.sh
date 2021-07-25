foldername="output/$(date +%d-%m-%y_%H-%M-%S)"
echo "folder name: $foldername"
mkdir -p "$foldername"

echo "6 teams and 1000 generations:"
python alert.py working on 6 teams, 1000 generations, 1000 individuals
./TUP instances/umps6.txt 1 1 1000 1000 > "$foldername"/umps6_1_1_1000_1000.txt
python alert.py "$foldername"/umps6_1_1_1000_1000.txt ./TUP instances/umps6.txt 1 1 1000 1000 `tail -n 16 "$foldername"/umps6_1_1_1000_1000.txt`


echo "8 teams and 1000 instances:"
python alert.py working on 8 teams, 1000 generations, 1000 individuals
./TUP instances/umps8.txt 1 1 1000 1000 > "$foldername"/umps8_1_1_1000_1000.txt
python alert.py "$foldername"/umps8_1_1_1000_1000.txt ./TUP instances/umps6.txt 1 1 1000 1000 `tail -n 16 "$foldername"/umps8_1_1_1000_1000.txt`

echo "10 teams and 1000 instances:"
python alert.py working on 10 teams, 1000 generations, 1000 individuals
./TUP instances/umps10.txt 1 1 1000 1000 > "$foldername"/umps10_1_1_1000_1000.txt
python alert.py "$foldername"/umps10_1_1_1000_1000.txt ./TUP instances/umps10.txt 1 1 1000 1000 `tail -n 16 "$foldername"/umps10_1_1_1000_1000.txt`

echo "12 teams and 1000 instances:"
python alert.py working on 12 teams, 1000 generations, 1000 individuals
./TUP instances/umps12.txt 1 1 1000 1000 > "$foldername"/umps12_1_1_1000_1000.txt
python alert.py "$foldername"/umps12_1_1_1000_1000.txt ./TUP instances/umps12.txt 1 1 1000 1000 `tail -n 16 "$foldername"/umps12_1_1_1000_1000.txt`

echo "14 teams and 1000 instances:"
python alert.py working on 14 teams, 10000000 generations, 1000 individuals
./TUP instances/umps14.txt 1 1 10000000 1000 > "$foldername"/umps14_1_1_10000000_1000.txt
python alert.py "$foldername"/umps14_1_1_10000000_1000.txt ./TUP instances/umps14.txt 1 1 10000000 1000 `tail -n 16 "$foldername"/umps14_1_1_10000000_1000.txt`

echo "16 teams and 1000 instances:"
python alert.py working on 16 teams, 10000000 generations, 1000 individuals
./TUP instances/umps16.txt 1 1 10000000 1000 > "$foldername"/umps16_1_1_10000000_1000.txt
python alert.py "$foldername"/umps16_1_1_10000000_1000.txt ./TUP instances/umps16.txt 1 1 10000000 1000 `tail -n 16 "$foldername"/umps16_1_1_10000000_1000.txt`

echo "18 teams and 1000 instances:"
python alert.py working on 18 teams, 10000000 generations, 1000 individuals
./TUP instances/umps18.txt 1 1 10000000 1000 > "$foldername"/umps18_1_1_10000000_1000.txt
python alert.py "$foldername"/umps18_1_1_10000000_1000.txt ./TUP instances/umps18.txt 1 1 10000000 1000 `tail -n 16 "$foldername"/umps18_1_1_10000000_1000.txt`

echo "20 teams and 1000 instances:"
python alert.py working on 20 teams, 10000000 generations, 1000 individuals
./TUP instances/umps20.txt 1 1 10000000 1000 > "$foldername"/umps20_1_1_10000000_1000.txt
python alert.py "$foldername"/umps20_1_1_10000000_1000.txt ./TUP instances/umps20.txt 1 1 10000000 1000 `tail -n 16 "$foldername"/umps20_1_1_10000000_1000.txt`

echo "30 teams and 1000 instances:"
python alert.py working on 30 teams, 10000000 generations, 1000 individuals
./TUP instances/umps30.txt 1 1 10000000 1000 > "$foldername"/umps30_1_1_10000000_1000.txt
python alert.py "$foldername"/umps30_1_1_10000000_1000.txt ./TUP instances/umps30.txt 1 1 10000000 1000 `tail -n 16 "$foldername"/umps30_1_1_10000000_1000.txt`
