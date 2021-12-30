# Javascript 01.02 - Hoisting
## Hoisting
호이스팅(hoisting)은 hoist의 동사로 **게양하다**라는 뜻을 가진다. 국기를 게양한다는 그 게양인데, 뜻처럼 무언가를 끌어올리는 것이다. Javascript에서의 호이스팅은 함수 혹은 namespace에 있는 선언들을 모두 끌어올려서 최상단에 위치하게 하는 것이다. 
그렇다고 모든 것이 호이스팅 되는 것은 아니다. 호이스팅은 **var 변수 선언과 함수 선언문에서만 일어난다.** 여기서 중요한건 변수 선언이지 값 할당은 아니니까 주의!
호이스팅은 JS Parser에서 일어난다. Var 변수의 호이스팅은 아래와 같다.
```
console.log('a');
var a = 1;
let b = 2;
const c = 3;

//////////HOISTING
var a;	/// HOISTING
console.log('a');
a = 1;
let b = 2;
const c = 3;
```

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