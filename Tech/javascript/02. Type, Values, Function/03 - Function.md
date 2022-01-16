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
함수는 파라미터를 가질 수 있다. 만약 파라미터가 2개인데, 실행 할 때 하나만 넣으면 어떻게 될까?
```
test(1); // 1, undefined
function test(a,b){
	console.log(a);
	console.log(b);	
}
```
코드로 확인해본 결과 undefined가 되는 것을 알 수 있다. undefined로 되면, 코드가 에러가 나는 경우가 생길테인데.. 이를 방지하기 위해서 디폴트 값을 설정해줄 필요가 있다. 자바스크립트에선 매우 간단하다! 매개변수를 선언할 때 default값을 함께 할당해주면 된다.
```
test(1); // 1, 0
function test(a,b=0){//b가 undefined가 될 시에 0으로 할당되도록 함.
	console.log(a);
	console.log(b);	
}

function test2(a,b=a*30){//default는 고정된 값이 아닌 수식을 할당할 수도 있다.
	console.log(a);
	console.log(b);	
}
```

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

### rest Parameter(ES6)
파라미터 수가 정해져 있으면 아주 베스트지만, 가령 집합 중 가장 작은 수 찾기 같은 개수를 알기 어려운 경우는 어떻게 할까(당연히 파라미터를 리스트로 받으면 되긴 하겠지)?
Rest parameter는 이런 경우를 대비해서 여러개의 파라미터를 리스트로 저장되게끔 해준다. 사용법은 파라미터 앞에 **…** 를 붙여서 선언해준다.
```
function restTest(a, ...rest){
    console.log(a);
    console.log(rest);
}

restTest(1,2)	//1 [2]
restTest(1,2,3,4,5,6,7,8) //1 [2,3,4,5,6,7,8]
```
위의 코드를 보면 알다시피 하나의 파라미터로 선언된 것들을 제외한 나머지들을 리스트로 저장이 된다. 이 점에서 Arguments Object와는 차이가 나타난다.