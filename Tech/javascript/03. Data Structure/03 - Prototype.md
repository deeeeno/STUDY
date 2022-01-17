# Javascript 03.03 - Prototype


### Prototype
Prototype은 한국어로 하면 초기 모델, 초기 형태로 나타낼 수 있다. 게임 프로토타입에서도 주인공 알렉스 머서는 연구의 초기 실험체로 실험체의 초기 모델인 프로토타입이 된다(맞나?). 아무튼, 중요한 것은 **초기 모델**이라는 것! Javascript에서도 똑같이 객체의 기본 모델을 설정하는 기능이라고 할 수 있다.
```
function Dino(){};

Dino.prototype.name = 'dino';
Dino.prototype.height = '20000';
Dino.prototype.info = function(){
    console.log(`name:${this.name} height:${this.height}`);
}

const deeeeno = new Dino();
deeeeno.info();    // name:dino height:20000
```
이럴수가, 함수형 객체인 Dino엔 아무것도 설정한게 없는데 deeeeno 객체는 info함수도 있고, name,height도 있는걸 볼 수 있다. 이렇게 객체를 new로 생성했을 때 기본적으로 가지는 변수, 함수를 설정하는 것이 prototype의 기능이다.

### what happen?
아니 근데 무슨 일이 일어나는 것일까? 우리는 함수형 객체에 아무것도 넣지 않았는데? 실제로 위에서 생성한 deeeeno를 출력해보면 아래처럼 나온다.
```
Dino{}
```
name, info, height는 어디에 저장이 되는 것일까?   
함수형 객체가 정의 되면 constructor 자격이 부여된다. constructor 자격이 생기게 되면 new 키워드를 통해 객체를 만들 수 있다.   
또한 함수를 정의하면 **prototype** 객체가 함께 생성이 된다. 위에서는 기능이라고 했지만 엄밀히 보면 prototype도 객체일 뿐이다.   
즉, 함수는 함수 자신의 내용 뿐만 아니라 prototype 객체도 함께 생성이 되는 것이다.   
함수의 constructor를 통해 생성하면 객체엔 __proto__란 이름으로 프로토타입 내용이 생긴다.
```
function testObj(){
    this.a = 1;
    this.b = 2;
}
testObj.prototype.c = 3;
testObj.prototype.d = 4;

const test = new testObj();
console.log(test);
console.log(test.__proto__);
```

### prototype chain
프로토타입 체인이라는 것은 객체의 프로토타입 객체인 __proto__도 어떤 객체이고 그 안에도 __proto__이고 또 그렇고 저렇고.. 이렇게 체인식으로 연결되어 있는 것을 말한다. 아래 코드를 보자.
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
코드를 보면 좀 더 이해가 쉬울 것이다. __proto__객체를 통해 새로운 데이터를 주입할 수 있고, 상위 객체는 하위의 __proto__또한 정보로 가질 수 있음을 알 수 있다.   
```
a.a = 100;
console.log(b.a);
console.log(c.a);

c.a = 100000;
console.log(a.a);
console.log(b.a);
console.log(c.a);
```
단, 이것은 나의 유추이긴 한데, 실질적인 데이터를 가진 부분, 가령 c의 a가 아닌 a의 a를 수정, 삭제 등을 하면 상위 객체도 함께 적용이 되지만, 역 방향은 취지가 좀 다르게 나타난다.
```
a.a = 100;
console.log(b.a); //100
console.log(c.a); //100

delete b['a']//사실 오리지널 b는 a를 가지고 있지 않다.
console.log(a.a); //100
console.log(b.a); //100
console.log(c.a); //100
```
실제로 최상위인 c에 a를 10만으로 주면 아래와 같이 된다.
```
console.log(c); {c:3}
c.a = 100000;
console.log(c); {c:3,a:100000}
```
마지막으로, 모든 __proto__의 끝은 Object 객체이다. 즉 모든 함수형 객체는 Object를 프로토타입으로 가지고 있다는 것이다.   