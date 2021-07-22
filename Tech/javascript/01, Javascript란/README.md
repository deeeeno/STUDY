# Javascript 01 - Javascript?
* **자바스크립트(Javascript)**란? 
웹 페이지에 생동감을 불어넣기 위해 탄생한 언어. 인터프리터 언어로 별도의 준비 없이 실행 가능하다(가령 컴파일).
* **자바스크립트(Javascript)**의 특징
	1. 인터프리터 언어
	인터프리터 언어는 한줄한줄 기계어로 번역하며 진행되지만, 최근 브라우저엔 JIT(Jist In Time Compiler) 컴파일러를 통해 실행속도가 매우 빨라졌다.
	2. 객체 기반의 언어
	함수, 변수 등의 값들을 모두 객체로 관리하기에 함수에 함수를 변수로 준다거나 하는 동작이 가능하다. 하지만 상속, 클래스의 개념은 없다.
	3. HTML 문서에 기술됨
	HTML 문서에 같이 작성이 되며 함께 수행이 된다.
	4. 비동기
	특정 코드가 종료되지 않았어도 대기하지 않고 다음 코드를 실행 시켜버림.

* **자바스크립트(Javascript)**의 장점
인터프리터 언어로써 컴파일이 따로 필요없어서 빠른 시간안에 결과를 확인할 수 있다. 단순한 구조, 원칙을 가지기 때문에 쉽게 접근이 가능하다. 또한 모든 변수, 함수는 객체로써 관리되어 유연한 동작이 가능하다.
* 단점
None-type 언어이다. 이 말은 문자열, 인티져 등의 타입이 존재하지 않는다는 것. 확실한 약속이 없으면 유지보수에 매우 크나큰 단점이 될 수 있다..!!


* 자바스크립트의 구조
이 공부를 시작한 계기인데, 자바스크립트를 많이 사용하지만, 내부적인 구조를 알지 못했다. 자바스크립트를 더 확실히 알기 위해 구조를 파악해보자. 자바스크립트는 Javascript Engine, Web API, Event Loop, Task Queue로 동작한다.
![structure](/Tech/resources/structure.png)
	1. 자바스크립트 엔진
	자바스크립트가 동작하는 클라이언트, 즉 브라우저는 자바스크립트 엔진을 가지고 있다. 대표적으로 Google V8엔진이 있는데, 크롬과 Node.js에서 사용한다. 
	엔진의 구성은 매우 간단하다. **Memory heap, Call Stack**으로 이루어져 있다. 메모리 힙은 메모리 할당, 콜 스택은 코드 실행에 따른 호출 스택이 쌓이는 곳이다.
	heap은 메모리가 할당되는 곳이니 건너뛰고 Call Stack의 구조를 살펴보자!
	2. Call Stack
	기본적으로 자바스크립트는 씽글 쓰레드 기반의 언어이다. 이 말은 호출 스택(Call Stack)이 하나란 소리!. 그렇기에 한번에 한가지 작업만을 처리할 수 있다.
	호출 스택은 우리가 프로그램 상 어디에 위치해 있는지 기록해두는 자료구조이다. 아래 코드는 이런 Call Stack 절차를 가질 것이다.
```
function add(x,y){console.log(x+y);}
function calculate(x,y){
	add(x,y);
}
calculate(2,3);
```

![callback](/Tech/resources/callstack.png)

	3. Task Queue
	Task Queue는 이벤트가 발생 하고, 호출되어야 할 콜백함수들이 기다리는 동안 대기하는 큐이다. 주로 비동기로 호출되는 함수들이 Task Queue로 보내진다. 
	아래 코드를 통해 Task Queue의 역할을 확인해보자.
```
console.log("start");
setTimeout(function(){
	console.log('123');
},3000);
console.log("end");
```
setTimeout의 경우 자바스크립트의 api가 아닌 Web API이다. 코드가 실행이 되고 setTimeout에 봉착하면 Web API로 하여금 실행시키도록 한다. 그럼 Web API에서 3초 대기를 하고 callback 함수를 TaskQueue로 전송한다. 이를 Event Loop가 감시를 하며 Task Queue에 들어온 콜백 함수를 실행시키게 된다.








