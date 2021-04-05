function calc(x:number, y:number, what?:string):number{
    if(what){
        switch(what){
            case '+':
                return x+y;
            case '-':
                return x-y;
            case '*':
                return x*y;
            case '/':
                return x/y;
        }
    }
    return x+y;
}

console.log(calc(3,4,'+'));
console.log(calc(4,3,'-'));
console.log(calc(5,6,'*'));
console.log(calc(6,2,'/'));
console.log(calc(16,34));

