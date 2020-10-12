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
echo $compile $sol'.c' '-o' $sol
$compile $sol'.c' '-o' $sol

target_path='tests/'
test_number=1
while [ $test_number -le 10 ]; do
	echo $gen $test_number '>' ${target_path}${test_number}'.in'
	$gen $test_number > ${target_path}${test_number}'.in'
	echo $val '<' ${target_path}${test_number}'.in'
	$val < ${target_path}${test_number}'.in'
	echo $sol '<' ${target_path}${test_number}'.in' '>' ${target_path}${test_number}'.out'
	$sol < ${target_path}${test_number}'.in' > ${target_path}${test_number}'.out'	

	test_number=`expr $test_number + 1`
done
