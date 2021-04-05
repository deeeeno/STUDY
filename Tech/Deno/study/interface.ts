//interface
//typedef같은 느낌이구만?
//있어도 되고 없어도 되는 변수는 물음표로 나타낸다.
//readonly를 사용해서 생성될 때만 할당 할 수 있다.
interface example{
    readonly only:number,
    name:string,
    seq:number,
    canIgnore?:string
}

function exampleToString(obj:example):void{
    console.log("only : " + obj.only);
    console.log("name : " + obj.name);
    console.log("seq : " + obj.seq);
    if(obj.canIgnore)   console.log("canIgnore : " + obj.canIgnore);
};

let test:example = {only:1, name: "김성희",seq: 123, canIgnore: '123123123'};
exampleToString(test);
test.only = 3;
test = {only:2, name:"메롱",seq:1234}
exampleToString(test);



