mark = int(input("请输入您的成绩:"))
if mark >= 0 and mark < 60:
    print(f"您最终等级为差!")
elif mark >= 60 and mark < 70:
    print(f"您最终等级为中等!")
elif mark >= 70 and mark < 90:
    print(f"您最终等级为良好!")
elif mark >= 90 and mark <= 100:
    print(f"您最终等级为优秀!")
else:
    print("成绩超出范围，请重新启动程序输入！")
input("\n按任意键继续")
