# Javascript 01.02 - Hoisting

## TDZ(Temporal Dead Zone)
호이스팅을 보기 전 TDZ라는 것을 먼저 알아야 한다. TDZ는 임시 비활성 구역으로 변수를 일시적으로 사용할 수 없는 공간을 의미한다.   
## Hoisting
호이스팅(hoisting)은 hoist의 동사로 **게양하다**라는 뜻을 가진다. 국기를 게양한다는 그 게양인데, 뜻처럼 무언가를 끌어올리는 것이다. Javascript에서의 호이스팅은 함수 혹은 namespace에 있는 선언들을 모두 끌어올려서 최상단에 위치하게 하는 것이다.   
호이스팅은 선언부들이 최상단으로 올라가게 되는데, javascript에는 3가지 변수 선언법인 var, let, const, 함수 선언식이 있다. 여기서 중요한건 변수들의 호이스팅 차이이다. 아래 코드를 보자.
```
console.log(x);		//undefined
var x = 1;

console.log(xx);	//Reference Error
let xx = 1;
```
왜 var 선언은 undefined가 나타나고, let은 reference error가 나타나게 되는 것일까? 여기서 **TDZ**의 차이가 나타나게 된다.   
변수의 호이스팅이 일어나게 되면 아래의 절차를 거치게 된다.
```
선언		(let xx, var x)
TDZ
초기화		 (xx = 1, x=1)
```
이 때, TDZ에서 변수를 호출하게 되면 var변수는 **undefined**를 나타내게 해주고, let, const는 error를 내보내게 된다. 

함수 선언식은 어떨까?
```
test1();
test2();

function test1(){
	console.log('1111');
}
var test2 = function(){
	console.log('2222');
}
//////////HOISTING
var test2;		///선언이 올라옴
function test1(){
	console.log('1111');
}
test1();	//1111
test2();	//test2 is not a function
test2 = function(){
	console.log('2222');
}
```
함수 표현식은 일어나지 않으니 주의해야 한다!