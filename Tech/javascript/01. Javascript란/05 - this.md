# this
javascript의 this에 대해서 알아보자. JAVA나 C++의 this로 생각하면 너무나 오산인 this… javascript에서 this는 바라보고 있는 어떠한 객체라고 할 수 있다.   
그렇다면? 바라보는 객체라는건 어떤 것일까? 주로 호출하는 주체가 되는데 아래 예시를 보면서 살펴보자. 

### 전역 객체
첫 번째는 전역 객체이다. 크롬 브라우저의 경우 window 객체가 될 것이고, 터미널의 node로 실행한 경우 node 객체가 될 것이다.  아래 코드를 터미널에서 한줄한줄 실행해보자.
```
var a = 1
console.log(this.a) ///1

function print(){
	this.b = 'abcd';
	console.log('hi');
}
console.log(this.b); ////undefined
print()
console.log(this.b); ////abcd
```
현재 전역 스코프에서 진행하고 있기에 this는 전역 객체가 된다. 즉 a를 선언하는 것은 전역객체.a가 되는 것이고, print함수의 호출 주체는 전역객체이므로 this.b는 전역객체.b가 되는 것이다.

### 객체 암시
단어가 조금 이상한데, 이는 자신을 호출할 객체로 this를 정하겠다고 암시를 한다고 생각하면 된다.
```
function test() {
  console.log(this.a);
}

var obj = {
  a: 20,
  func1: test,
  func2: function() {
    console.log(this.a);
  }
};
test() /// undefined
obj.func1(); // 20
obj.func2(); // 20
```
위 예시를 보면 test함수는 this의 a를 출력하고 있다. obj 객체는 a, func1, func2가 있는데 a는 20, 1은 test함수, 2는 this의 a를 출력중이다. 이제 중요한 함수 호출 부분을 보자.   
test만을 호출한 것은? 전역 스코프에서 호출했기 때문에 this는 전역스코프가 된다. 따라서 a가 없는 전역스코프이므로 undefined가 나타난다. 반면에 obj의 func1, func2를 출력한 것은 obj객체의 스코프 내 a를 출력하게 될 것이다.

### 명시적인 바인딩
함수 객체는 call, apply, bind 메소드를 가지고 있다. 우리가 흔히 함수 호출에 사용하는 함수명()을 통한 실행이 아닌 다른 방법으로 실행하는 방법이다.  우선 3개의 사용법 부터 차근차근 알아보자.
```
//1.call
//call(obj,arg1,arg2.....)
//2.apply
//apply(obj,[arg1,arg2....])
//3. bind
//bind(obj,arg1,arg2 ....).  return으로 새로운 함수
var name = 'dino';
function print(a,b,c,d){
	console.log(this.name);
	console.log(a,b,c,d);
	return a+b+c+d;
}

var obj = {name:'deeeeno'};

print(1,2,3,4);				//dino 1 2 3 4   return value : 10
print.call(obj,1,2,3,4);    //deeeeno 1 2 3 4 return value : 10
print.apply(obj,[1,2,3,4]); //deeeeno 1 2 3 4 return value : 10

var bindFunc = print.bind(obj,1,2,3,4); //deeeeno 1 2 3 4 return value : 10
```
Call, bind,apply의 첫 번째 인자는 this에 사용될 객체이다. 즉, 객체를 주입하면 해당 객체가 this가 되어버린다.

### Event Handler
html에서 이벤트 핸들러에 사용된 this에도 차이점이 존재한다. 먼저 설명하면 인라인으로 입력한 경우와 이벤트 핸들러로 등록하는 경우에 차이가 있다.
```
<!DOCTYPE html>
<html>
  <body>
    <button id="btn1" onclick="foo()">Button1</button>
    <button id="btn2">Button2</button>
    <script>
      function foo () {
        console.log(this); // window object
      }
      document.getElementById('btn2').addEventListener('click',function(e){
        console.log(this);  //btn2
      });
    </script>
  </body>
</html>
```

### this in Arrow Function
laeifjlaiwejflija
함수 선언식에서 this는 호출하는 주체가 저장이 된다고 앞에서 얘기하였다. ES6에서는 함수 표현식으로 화살표 함수를 사용하곤 한다.
```
const hi = (hi)=>console.log(`hello ${hi}`);
```
이 화살표 함수에서는 this가 조금 상이한데, 결론부터 말하자면 화살표 함수에서의 this는 실행 주체가 아닌 상위 스코프가 저장이 된다. 예시를 살펴보자.
```
const div = document.querySelector('.div');
div.addEventListener('click',function(event){
  this.classList.toggle('active');    //함수 실행 주체인 div가 this로 됨.
  setTimeout(function(){
    this.classList.toggle('active');  //error!
  },500);
})
```
왜 두번 째 this는 오류가 나타날까? 바로 실행시키는 주체가 window 객채이기 때문이다...! 그렇다면 위 코드가 정상 동작하도록 하려면 어떻게 해야 할까? 정답은 화살표 함수에 있다. 화살표함수의 this는 상위 스코프라고 했다. 그럼 setTimeout의 상위 스코프인 div로 주면 되는거니까 아래처럼 수정하면 동작한다.
```
const div = document.querySelector('.div');
div.addEventListener('click',function(event){
  this.classList.toggle('active');   
  setTimeout(()=>{
    this.classList.toggle('active');
  },500);
})
```
다음엔 아래 예시를 node 커맨드를 통한 터미널에서 한줄한줄 써보자.
```
> this
> var a = 1;
> const person = {a:2,grow:()=>{this.a+=1}};
> person.grow();
> this.a          //2
> person.a        //2
```
위 예시를 보면 person.grow 함수를 실행시키는 스코프는 node 스코프이므로 node객체의 a가 1더해짐을 알 수 있다.