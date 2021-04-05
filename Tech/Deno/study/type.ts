/*
typescript의 원시형 타입
boolean, number, string, array, tuple, any, void, undefined, null
그 외 타입
object
*/

//boolean - true,false
var boolean_example:boolean = true;
boolean_example = !boolean_example;
//boolean_example = 3; // error 

//number - 숫자
let number_example:number = 1;
//number_example = "123"; // error

//string - 문자열
let string_example:string = "aliejflaijefli";
//string_example=1; // error
 
//array - 배열
const array_example1:string[] = ["1","2","3"]; //이렇게도 선언 가능
const array_example2:Array<number> = [1,2,3];  //저렇게도 선언 가능

//any - 무엇이든 가능
let any_example:any = 3;
any_example = "123";

//void - 보이드형(no return function)
function return_function(a:string):string{
    return a+"123";
}
function void_function(a:string):void{
    console.log(a);
};

//tuple - 튜플
let x:[string, number];
x = ["hi",3];
//x = [3,"hi"]; // error

//enum - enum
enum COLOR {RED='r',GREEN='g',BLUE='b'};
console.log("COLOR RED ->" + COLOR.RED);
console.log("COLOR GREEN ->" + COLOR.GREEN);
console.log("COLOR BLUE ->" + COLOR.BLUE);

//object 원시형 타입이 아닌 나머지 타입
let obj_example:object;
//obj_example = 3;
obj_example = {test:3};