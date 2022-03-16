# Javascript 03.03 - Prototype


## Prototype
Javascript는 **ProtoType 기반 언어**라고 불리는 만큼 프로토타입은 자바스크립트의 매우 중요한 기능이다.   
그렇다면 프로토타입은 뭐라고 하면 좋을까? **원형(original) 객체로써 객체의 데이터, 동작 방식을 재사용할 수 있게 해주는 기능**이라고 하면 좋을 것 같다.   
우선 프로토타입의 예시를 보고 하나하나 차근차근 살펴보자!
```
function Person(){
    this.eyes = 2;
    this.nose = 1;
    this.mouth =1;
}
const dino = new Person();
const jane = new Person();
const dave = new Person();
```
Person이란 객체는 `eyes=2,nose=1,mouth=1`이란 기본값을 가지는 함수형 객체이다. 함수형 객체는 new 연산자를 통해 constructor를 호출할 수 있게 되고, 이로써 dino, jane, dave 객체는 각각 눈,코,입이 2개,1개,1개를 가질 수 있다.   
이 코드의 문제점은 어떤 것이 있을까? 메모리를 많이 쓴다는 것이다. 동일한 데이터를 객체마다 3개씩 쓰고있기 떄문이다! 이런 상황을 해결하기 위해 **prototype**을 쓸 수 있다.
```
function Person(){

}

Person.prototype.eyes=2;
Person.prototype.mouth=1;
Person.prototype.nose=1;

const dino = new Person();
const jane = new Person();
const dave = new Person();
console.log(dino.eyes,dino.mouth,dino.nose);//2 1 1
console.log(jane.eyes,jane.mouth,jane.nose);//2 1 1
console.log(dave.eyes,dave.mouth,dave.nose);//2 1 1
```
아니 이럴수가, Person 객체엔 아무 값도 없는데, dino, jane, dave는 눈,코,입 데이터를 얻을 수 있다! prototype 객체에서 값을 참조한 것이다!    
위의 설명 처럼 원형 객체인 prototype 객체에서 데이터를 재사용하는 것이다. 이것이 프로토타입의 전부이다!   

## Prototype Link, Prototype Object
이렇게 간단한 프로토타입의 사용법을 좀 더 내부적으로 살펴보자! Prototype Link, Prototype Object 두개를 통틀어 prototype이라고 한다.   
모든 자바스크립트 객체는 function을 통해 생성된다. 함수가 정의되면 아래의 두가지일이 생긴다.
### constructor 자격 부여
첫 번째는 constructor 자격이 부여된다. 이를 통해 우리는 new 연산을 사용할 수 있는 것이다.   
### prototype Object 생성
위의 Person 예시를 다시 살펴보자.
```
function Person(){

}
Person.prototype.eyes=2;
Person.prototype.mouth=1;
Person.prototype.nose=1;

console.log(Person.prototype); /// javascript object
```
Person의 prototype도 역시나 객체이다. 즉! Person 함수를 선언하면 Person.prototype이란 자바스크립트 객체를 생성하게 되는 것이다! 그렇다면 당연히 Person.prototype도 constructor와 __proto__를 가지게 된다.   
그렇다면 **__proto__**는 뭘까?? 소제목에 나온 **Prototype Link**가 된다. prototype object는 모든 함수가 가지고 있고, 모든 객체는 __proto__를 가지게 된다. 이 객체를 통해 눈,코,입 데이터를 Prototype Object에서 참조할 수 있는 것이다.


### prototype chain
프로토타입 체인이라는 것은 프로토타입 링크인 __proto__속성을 통해 상위 프로토타입과 연결되어 있는 상태를 의미한다.
```
let a = {a:1};
let b = {b:2};
let c = {c:3};

console.log(c.b) // undefined;
c.__proto__ = b;
console.log(c.b) // 2
console.log(c.a) // undefined
b.__proto__ = a;
console.log(c.a) // 1
```
주의해야할 것은 Prototype Object를 수정하게 되면 해당 Object를 링크로 한 모든 객체에서 반영된다는 것이다.   
마지막으로, 모든 __proto__의 끝은 Object 객체이다. 즉 모든 함수형 객체는 Object를 프로토타입으로 가지고 있다는 것이다.   