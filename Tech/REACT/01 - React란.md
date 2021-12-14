# REACT - 01. React란?
### React란? 
	User Interface를 만들기 위한 JavaScript 라이브러리.
### React의 특징
* 선언형(Declarative)이다.
프로그래밍 패러다임엔 명령형과 선언형 프로그래밍이 있는데 이 중 리액트는 선언형 프로그래밍이다. 간단하게 두 개의 차이를 보자면 아래와 같다.
```
var arr = [1,2,3,4]
///명령형
function add_ex(){
	var ret = 0;
	for(i of arr) ret += i;
	return ret;
}
function add_dec(){
	return  arr.reduce((ac,cur)=>ac+cur);
}
```
말장난 같아 보이지만…. 결국의 차이는 어떻게 실행시키는지와 다르기 선언형은 무엇을 나타나는지 알려주는 것이라고 보면 된다.
react는 jsx 문법을 사용한다. 이를 도출할 떄 선언형에 맞게 알고리즘이 구현되지 않고 return으로 이루어 진다.
* component 기반이다.
컴포넌트로 이루어지기 때문에 높은 재사용성을 가진다.
* Virtual DOM을 사용한다(이것에 대해서는 다시 정리해보기).

### React의 장점
* 쉽다. 복잡함이 적다
* 다른 라이브러리처럼 controller, directive 등 분리하지 않고 하나의 component로 관리한다.
* 메모리 관리와 성능 면에서 아주 뛰어나다.
* UI수정, 재사용이 아주 간편하다.
* 다른 프레임워크나 라이브러리와 혼용하며 사용하기 편하다.
### React의 단점
* View만 관여하기 때문에 데이터 모델링, Ajax등은 제공하지 않는다.
* javascript의 배경지식이 필요하다.
* IE8 이하 버전들은 지원하지 않는다.
