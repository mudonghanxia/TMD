class excel:
    def __init__(self, num: int):
        self.array = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                      'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
        self.num = num

    def fun(self)->str:
        ret = str()
        while self.num != 0:
            self.num -= 1
            ret = (self.array[self.num % 26]) + ret
            self.num = self.num // 26
        return ret

def __main__():
    f = excel(701)
    ret = f.fun()
    print(ret)

__main__()
