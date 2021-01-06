# !/bin/basih

compile='g++ -std=c++17'
gen='generator/gen'
echo $compile $gen'.cpp' '-o' $gen
$compile $gen'.cpp' '-o' $gen

val='validator/val'
echo $compile $val'.cpp' '-o' $val
$compile $val'.cpp' '-o' $val

compile='gcc'
sol='solutions/sol'
echo $compile $sol'.c' 'solutions/function.c' '-o' $sol
$compile $sol'.c' 'solutions/function.c' '-o' $sol

target_path='tests/'
test_number=1
task_num=(0 3 3 4)
for subtask in 1 2 3; do
	cnt=0
	while [ $cnt -lt ${task_num[subtask]} ]; do
		echo $gen $subtask $test_number '>' ${target_path}${test_number}'.in'
		$gen $subtask $test_number > ${target_path}${test_number}'.in'
		echo $val '<' ${target_path}${test_number}'.in'
		$val < ${target_path}${test_number}'.in'
		echo $sol '<' ${target_path}${test_number}'.in' '>' ${target_path}${test_number}'.out'
		$sol < ${target_path}${test_number}'.in' > ${target_path}${test_number}'.out'	

		test_number=`expr $test_number + 1`
		cnt=`expr $cnt + 1`
	done
done
