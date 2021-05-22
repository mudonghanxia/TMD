function fun(){
    loop: for( let j = 1;j < 6; j++){
        document.write("<br>" + j + ":")l
        for(let i = 1; i < 6; i++){
            if(i == 3) continue loop;
            document.write(i);
        }
    }
}
