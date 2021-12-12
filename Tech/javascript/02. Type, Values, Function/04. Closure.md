# Javascript 02.04 - Closure
Closure란 내부 함수에서 외부함수의 자원(변수 함수 등등)을  scope를 통해 접근이 가능하지만, 반대는 불가능한 개념을 말한다. 간단하게 이해한 바로는 데이터를 독립적(?)으로 두기 위함..?

```
let count = 0;
function counter(){
    let count =0 ;
    return{
        get: function(){
            return count;
        },
        increment: function(){
            count += 1;
        }
    }
}

const a = counter();
console.log(a.get());		//0
a.increment();
console.log(a.get());		//1

console.log(`global한 count값은 ? ${count}`);	//global한 count 값은 ? 0

const b = counter();
console.log(b.get());		//0
b.increment();
console.log(b.get());		//1
```
코드 상단에 보면 count =0 을 선언, 초기화 해주었고, counter 함수 안에서 count란 변수를 선언, 초기화 하였다.  counter함수 내부를 살펴보자. Get, increment 함수 입장에서 count가 선언된 곳은 외부 스코프(counter)의 count가 될 것이다. 그로 인해서 counter 함수에 대한 count 값은 언제나 0이 될 것이다. 위의 코드를 살펴보면 a 변수, b변수에 대해서 모두 0 으로 시작함을 알 수 있다.

그렇다면 클로져를 사용하는 이유는 어떤 것이 있을까?
	* 데이터 접근을 제한할 수 있다. 클로져의 개념을 다시 보면 내부함수는 외부함수의 자원을 접근할 수 있지만, 외부함수는 내부함수의 자원을 제한한다. 이 개념을 살려서 사용할 데이터를 연산 -> object로 캡슐화 시킨 후 return시키면 내부의 데이터 접근을 제한할 수 있다.
	* 모듈화에 유리하다. 위의 코드에서도 알 수 있지만, 데이터를 독립적으로 사용할 수 있다. 이를 통해 모듈화가 용이하다.
	* 데이터 보존에 좋다. 코드에서 a와 b 카운터에 대해서 처음 외부함수로 할당한 후엔 스코프가 유지되기 때문에 count값이 유지되는 것을 알 수 있다.

뭔가 간단한데… 뭔가 어려운 closure… 결국 lexical scope를 제대로 이해하고 사용해야 한다는 것!
