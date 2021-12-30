#  Javascript 01.03 - Lexical Scope
## Scope?
코드에서 스코프(Scope)란 식별자 이름이 있는 항목 가령.. 변수, 상수 함수 등이 인식되는 프로그램의 영역이라고 할 수 있다. 이 중 자바스크립트는 Lexical Scope를 따른다.

## Lexical Scope
Lexical scope는 함수, 변수의 스코프를 **선언된 위치를 기준**으로 정한다. 반대되는 개념으로 Dynamic Scope를 말할 수 있는데, 이는 호출된 시점을 기준으로 정하는 것이다.
```
var x = 1;

function print() {
    console.log(x); // 1
}

function out() {
    var x = 9;
    print();
}

out();
```
위 코드의 결과는 어떻게 될까? 9? 1? 정답은 1이다. Lexical Scope는 선언된 위치를 기준으로 코드 영역을 설정하는 것이라는걸 염두하고 생각해보자.
Print 메소드에 대해서 x가 선언된 값은 var x = 1로 1이 되고, out함수 또한 x=1로 선언이 되어 있다.  그렇기에 1이 나타나는 것이다. 그럼 아래 코드를 생각해보자.
```
var x = 1;

function out() {
    var x = 9;
    function print() {
        console.log(x); // 1
    }
    print();
}

out();
```
이번엔 9일까 1일까? 정답은 9! 이유는?? print()함수가 선언된 시점에서 보면 x는 9로 선언이 되어 있기 때문이다!

스코프를 탐색하는 순서는 안에서 밖으로 검색을 진행한다. 위의 코드를 예로 들면, print 함수가 x변수를 찾을 땐 자신의 scope영역을 탐색, 이 때 값이 없다면 외부 함수의 scope, 그 후에도 없다면 전역 scope순으로 탐색을 하게 된다.
