  mark_grout_succsee = ""
mark_grout_unsuccess = ""
while True:
    try:
        mark = input("请输入您的成绩:")
    except:
        break
    mark = int(mark)
    if mark >= 0 and mark < 60:
        mark_grout_succsee += str(mark) + "   差\n"
    elif mark >= 60 and mark < 70:
        mark_grout_succsee += str(mark) + "   中等\n"
    elif mark >= 70 and mark < 90:
        mark_grout_succsee += str(mark) + "   良好\n"
    elif mark >= 90 and mark <= 100:
        mark_grout_succsee += str(mark) + "   优秀\n"
    else:
        mark_grout_unsuccess += str(mark)
with open("E://score.dat","w") as file:
    file.write(mark_grout_succsee)
    file.write("\n")
    file.write(mark_grout_unsuccess)
    file.close()

input("\n按任意键继续")
