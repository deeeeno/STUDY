# Javascript 02.01 - Type
Javascript도 다른 언어들과 같이 변수를 선언할 수 있다. Javascript는 Non-Type 언어로써 C언어 처럼 int, char같이 타입이 존재하지 않는다. Javascript의 변수는 어떻게 관리되는지 알아보자!
### Type
Javascript엔 크게 두 가지 분류의 타입이 존재한다. 이는 **Primitive, Object Type**이다.
* Primitive Type   
number(숫자), string(문자열), boolean, null, undefined   
* Object Type   
Primitive Type을 제외한 나머지 type을 의미하고, name, value로 이루어진 property의 collection이다.   
Javascript의 Object는 property들이 정렬되어 있지 않다. 하지만, array같이 정렬된 object이 있긴 하다..!

### 변수의 선언
변수를 선언하는 방식은 3가지가 있다. **var, let, const**이다. 하지만, 각자 차이가 존재하는데,   
* var   
변수를 선언한 후, 같은 이름으로 **선언이 가능하다**.   
* let   
변수를 선언한 후, 같은 이름으로 **선언이 불가능 하다**.
* const   
변수를 선언한 후, **재할당이 되지 않는다**.
<pre><code>
////var
var t = 1;
console.log(t); //1
var t = 2;
console.log(t); //2

/////let
let a = 1;
console.log(a); //1
let a = 2; //Uncaught SyntaxError: Identifier 't' has already been declared
console.log(a);

////const
const c = 1;
console.log(c); //1
c = 3;  //Uncaught TypeError: Assignment to constant variable.
console.log(c);
//하지만 객체인 경우 const로 선언된 객체임에도 내부 key에 대한 CRUD는 가능하다.
const obj = {'a':1};
obj['c'] = 2;   //obj -> {'a':1, 'c':2}
delete obj['c'];   //true
</code></pre>
자바스크립트 변수 선언법에 대해서 크게 두가지 의견이 존재한다. 마티아스 바인스와 카일 심슨이란 아저씨의 의견인데 바인스의 의견은 아래와 같다.
```
기본적으로 const를 사용하되, 재할당이 필요한 경우 let으로 바꾸자
es6에선 var 절대 쓰지 말자.
```
카일 심슨의 의견은 다음과 같다.
```
여러 큰 스코프에서 공유가 필요한 경우 var를 쓰자.
작은 스코프에선 let을 쓰자.
코드작성이 좀 진행 된 후에 let, const로 리펙토링 하자.
```
나는 야메로 배워서 var을 쓰는데, let을 쓰도록 해야겠다..! -> 기본적으로 변수 선언할때 const를 디폴트로 쓰고 변경의 필요성을 느끼면 그때 let을 씀, var은 아직까지 써 본 기억이 없음 ㅋㅋㅋ

