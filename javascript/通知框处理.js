function fun(){
    const value = prompt("请输入您的年纪？");//通知框输入
    switch(value){
        case '1':{
            alert("1年纪");//通知框输出
            break;
        }
        case '2':{
            alert("2年纪");
            break;
        }
        case '3':{
            alert("3年纪");
            break;
        }
        case '4':{
            alert("4年纪");
            break;
        }
        default:{
            alert("我也不知道您几年级"
                 );
        }
    }
}
