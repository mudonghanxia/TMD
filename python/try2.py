m1 = ["601988","中国银行",20000,3.221,3.330]
m2 = ["600318","中国平安",10000,79.30,90.10]
m3 = ["600745","闻泰科技",900,95.23,103.00]
m4 = ["002821","凯莱英",600,262.32,239.27]
m5 = ["300676","华大基因",800,133.52,128.00]
m = [m1,m2,m3,m4,m5]
for choice in m:
    choice.insert(0,choice[2]*(choice[4]-choice[3]))
m.sort(reverse=True)
for choice in m:
    print(f'{choice[1]} {choice[2]} {choice[3]} {choice[4]} {choice[0]}')
a = input("按任意键退出.")
