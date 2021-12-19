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
</code></pre>
나는 야메로 배워서 var을 쓰는데, let을 쓰도록 해야겠다..! -> 기본적으로 변수 선언할때 const를 디폴트로 쓰고 변경의 필요성을 느끼면 그때 let을 씀, var은 아직까지 써 본 기억이 없음 ㅋㅋㅋ

