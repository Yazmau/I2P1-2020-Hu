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
test_cnt=1
test_amount=10
while [ $test_cnt -le $test_amount ]; do
	echo $gen $test_cnt '>' ${target_path}${test_cnt}'.in'
	$gen $test_cnt > ${target_path}${test_cnt}'.in'
	echo $val '<' ${target_path}${test_cnt}'.in'
	$val < ${target_path}${test_cnt}'.in'
	echo $sol '<' ${target_path}${test_cnt}'.in' '>' ${target_path}${test_cnt}'.out'
	$sol < ${target_path}${test_cnt}'.in' > ${target_path}${test_cnt}'.out'	

	test_cnt=`expr $test_cnt + 1`
done
