# Javascript 02.03 - Function
### Description
Javascript의 function은 자바스크립트 코드의 블럭으로, 한번 정의되면 여러번 실행될 수 있는 것을 의미한다. Function은 매개변수화 되어있어서 function 내 블럭에서 지역변수로 사용되는 파라미터(매개변수) 리스트를 정의에서 포함할 수 있다.
자바스크립트에서는 흥미롭게도 Function이 Object 타입을 띈다. 그래서 object variables로써 다른 함수로 할당이 가능하다.  function의 기본 선언법은 아래와 같다.
```
function fName(param1, param2, ...){
	console.log(param1);
}
//recursive도 가능!
function factorial(x){
	if(x<=1) return 1;
	return x * factorial(x-1);
}
```
두 함수의 가장 큰 차이점이라면 **return**의 유무이다! return은 함수가 종료된 후의 반환값인데, return이 정의되면 함수가 끝난 후 해당 값이 반환이 되지만, 없는 경우엔 **undefined**가 반한된다.

### Function Declarations, Function Expressions
함수를 만드는 방식은 크게 두개가 있다. **함수 선언식(Function Declarations), 함수 표현식(Function Expressions)** 두개의 차이는 아래와 같다.
```
function a(){
	console.log('a');
}
var b = function(){
	console.log('b');
}
```
언뜻 보면 별로 큰 차이가 없어 보이지만, 자바스크립트의 **호이스팅**에서 차이가 나타난다.  호이스팅에 의해 변수 b 는 최상단으로 올라가지만, 함수가 할당됨은 같이 올라가지 않으므로  b는 함수의 할당이 나올때 까지 함수가 아니게 된다. 아래 코드를 보면 차이가 나타난다.
```
a();
b();	//error, b is not a function
function a(){
	console.log('a');
}
var b = function(){
	console.log('b');
}
```

### IIFE(Immediately Invoked Function Expressions)
IIFE는 즉시 호출 함수 표현식이라고 한다. 위에 다뤘던 함수 표현식, 선언식과 관련이 있는데, IIFE는 함수 선언식을 표현식으로 만들어 바로 실행시켜버리는 것을 말한다. 기본 형태는 다음과 같다.
```
(function(){
	///code
})();
```
일반적인 함수 선언식을 괄호로 감싸 실행시키는걸 볼 수 있다. 물론 괄호에 쌓인 함수는 함수 객체가 되므로 call, bind, apply를 사용할 수 있다.    

### Arrow Function
Arrow Function은 ES6의 문법으로 간단한 syntax를 사용한 함수 표현식이다. 말 그대로 화살표를 사용한 방식인데 아래와 같이 사용한다.
```
const test2 = function(){
    console.log("TEST");
}
const test2_arrow = ()=>{
    console.log("TEST");
}
```
화살표 함수는 함수가 return 값 만을 가지는 single line인 경우 return 기호를 **생략할 수 있다.**
```
const multiply = (x,y) => { return x*y };
const multiply = (x,y) => x*y;   //생략 가능!
```

### Parameter Defaults
파라미터가 있는 함수를 파라미터 없이 실행시켜 보면, 각 파라미터엔 undefined가 나타날 것이다.
```
test(); // undefined, undefined
function test(a,b){
	console.log(a);
	console.log(b);	
}
```
이런 경우 각 파라미터를 사용하는 연산에 오류가 나타날 수 있다. 그렇다면 아래 방식으로 기본값을 설정할 수 있을 것이다.
```
test();// 1,2
function test(a,b){
	if(typeof a === undefined) a = 1;
	if(typeof b === undefined) b = 2;
	console.log(a);
	console.log(b);
}
```
하지만, 변수 하나하나 이렇게 기본값을 설정하는 것은 굉장히 비효율적이다... ES6엔 이런 문제를 해결하고자 파라미터의 기본값을 아주 간편하게 설정해줄 수 있도록 마련되어있다.
```
test();
function test(a=1,b=2){
	console.log(a);
	console.log(b);
}
```
매우 간편하게 사용할 수 있다. 하지만! 이 문법에도 문제점은 존재하는 것이 있으니.. 만약 b만 할당해주고 싶다면? 나는 `test(3)`으로 쓰고 싶지만, 이렇게 쓰면 `a=3`이 될 것이다. 즉, `test(undefined,3)`으로 작성해주어야 하는데, 이는 사용에 불편함을 일으킬 수 있다. 이런 문제를 해결하기 위해 **디스트럭쳐링**을 사용할 수 있다.
```
test();
test({a:3,b:4});
test({b:5});
function test({a=1,b=2}={}){
	console.log(a);
	console.log(b);
}
```
여기서 중요한 부분은 `={}`을 빼먹으면 안된다는 것이다. 이걸 빼먹게 되면 TypeError가 나타난다.

### Arguments Object
파라미터로 정의되진 않았지만, 실행할 때 입력한 모든 파라미터에 대해서 확인하는 방법이 없을까? 이럴 때 사용하는 것이 바로 Arguments Object이다. 특징은 dictionary라는 점이다. 비록 key값은 index이지만, 딕셔너리로 선언된 오브젝트이다.
```
function argText(x){
    console.log(x);
    console.log(arguments)
}
argText(1,2,3,4,5)
//1
//[Arguments] { '0': 1, '1': 2, '2': 3, '3': 4, '4': 5 }
```