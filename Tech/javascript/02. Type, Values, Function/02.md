# Javascript 02.02 - Values
이 전에서 간단하게 Type과 선언 방식에 대해서 알아보았다면, 이제 Javascript의 value들에 대해서 알아보자! 대표적으로 쓰이는 numbers, strings, null, undefined, map, array, set에 대해서 알아보자.

### Numbers
Numbers는 말 그대로 숫자이다. numbers엔 크게 두 가지의 유형이 존재하는데, **Integer**와 **Float**가 있다. 정수와 실수로 알면 될 것이다. 소수가 있고 없고 차이?   
정수 간 연산은 사칙연산과 모듈러연산(나머지 연산) 외에도 Math 라이브러리를 통해 반올림, 올림, 제곱근 등의 연산을 할 수 있다. Math 연산에 대해 추가적인 설명으로 연산의 결과가 overflow 나지 않는다. overflow의 상황이 오면 결과값은 **Infinity**라는 value로 나타나게 된다.   
연산에 대한 결과로는 **NaN(Not a Numnber)**라는 값도 존재한다. 이는 연산 결과가 숫자가 아니라는 것을 의미하는 데에 있어서 Infinity와 다르다고 볼 수 있다. 예를 들어, 0/0이나 숫자와 문자열의 뺄셈,나눗셈 등 결과가 숫자가 아닌 것을 의미한다.
<pre><code>
Math.pow(2,4) = 2^4 = 16
Math.round(0.6) = 0.6의 반올림 = 1
Math.sqrt(3) = 3의 제곱근 = 루트 3
1/0 => Infinity
0/0 => NaN
등등...
</code></pre>
Number 라이브러리엔 문자열을 숫자로 변환, 정수인지 등등 유틸리티를 가지는 라이브러리 이다.
<pre><code>
Number.isNaN(x)
Number.isFinite(x)
Number.parseInt(x)
Number.parseFloat(x)
등등...
</code></pre>
### Text
Text는 문자열이다. String! 문자열은 특징이나 라이브러리가 간단하므로 패스하고 ES6의 **Template**의 사용을 알아보자.
Template의 경우 따옴표로 문자열을 덮는게 아닌 `기호를 사용해서 문자열을 덮는다. java나 C의 format string처럼 생각하면 쉽다.   
<pre><code>
const hi = 'hi';
const name = 'deeeeno';
const templateStr = `TEMPLATE : ${hi} ${name}`;
console.log(templateStr); //TEMPLATE : hi deeeeno
</pre></code>
사용법은 위의 코드처럼 ``사이에 문자열을 입력하고, 사용하고픈 variable을 ${}을 통해 주입시켜주면 된다.
### null
값이 없는 경우 나타나는 값이다. 특이하게도 typeof 오퍼레이터로 null인 변수를 찍어보면 'object'라고 나타나는 것을 알 수 있다. 이는 object가 아님을 나타내는 특별한 object라는 것으로 확인할 수 있다. null은 문자열, 숫자 뿐만 아니라 object가 "no value"라는 것을 타나낼 수 있다.
### undefined
undefined 또한 값이 없는 경우를 나타내지만, 조금 깊은 분류로 값이 없음을 나타낸다. 가령 선언은 되었지만, 초기화가 안된 변수라거나.. object에서 없는 property로 검색한 경우 등 존재하지 않는 경우를 의미한다.   
결론 짓기를, null은 프로그램 레벨에서 **no value**인 경우를 의미하고, undefined는 시스템 레벨에서 에러에 의한 **no value**를 의미한다고 할 수 있다.
### Map
### Array
### Set
