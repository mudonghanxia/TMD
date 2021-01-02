sstring = "56220,73900,79560,25631,68321,49600,67200,96000,47100,87500,68500,101700,39500,3564,23600"
group_new = []
char = ""
ans = 0
for value in sstring:
    if value >= '0' and value <= '9':
        char += value
    else:
        group_new.append(int(char))
        char = ""
group_new.append(int(char))
for value in group_new:
    ans += value
print(f"the biggest is {ans},the min is {min(group_new)},the max is {max(group_new)}")
input("\n按任意键继续")
