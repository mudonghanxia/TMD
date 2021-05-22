#python中存在方法rjust（number1，str）
#   number1 是格式几位
#   str 是填充字符
# #
def count_1(number:int)->int:
    ret = 0
    while number != 0:
        ret += number % 2
        number = number // 2
    return ret

def function(num:int)->list:
    ret = list()
    for i in range(0,12):
        for j in range(0,60):
            if count_1(i) + count_1(j) == num:
                ret.append(str(i).rjust(2,'0') + ":" + str(j).rjust(2,'0'))
    return ret

def main():
    x = function(1)
    print(x)

main()
    
