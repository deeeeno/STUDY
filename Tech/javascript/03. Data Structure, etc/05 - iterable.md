# Javascript 03.05 - iterable
> iterate - 반복하다.   

### iterable Object
Iterable Object란 반복이 가능한 객체를 의미한다. 여기서 말하는 반복이란 순서대로 객체 내 성분을 읽을 수 있다는 것이다. 대표적으로 **배열**이 있다.
```
const arr = [1,2,3,4,5]
for(const ele of arr) console.log(arr);
```
위의 예시처럼 `for ~ of`를 사용해 순서대로 읽을 수 있는 객체를 **iterable Object**라고 한다.   

### Symbol.iterator
배열에서 Symbol.iterator라는 키로 console.log를 해보면 다음과 같이 나타날 것이다. 그것을 null로 바꾸면 어떻게 되는지 확인해보자.
```
const arr = [1,2,3,4,5]
console.log(arr[Symbol.iterator]);  //[Function: values]
arr[Symbol.iterator] = null;
for(const ele of arr) console.log(arr); // arr is not iterable
```
이 예시를 보고 눈치 챘겠지만, Symbol.iterator라는 것은 Iterable Object라는 것을 판단하는 값이다! 일반 Object의 Symbol.iterator를 출력해보면 다음과 같을 것이다.
```
const a = {};
console.log(a[Symbol.iterator]);        //undefined
```
Symbol.iterator는 프로토타입에 정의되어 있다. 우리가 흔히 쓰는 iterable Object인 Array와 문자열의 prototype에서 Symbol.iterator를 출력해보면 함수가 정의돠어 있음을 알 수 있다. 조금 특이한 것은 Map, Set도 iterable Object라는 것이다..!
```
> Array.prototype[Symbol.iterator]
[Function: values]
> String.prototype[Symbol.iterator]
[Function: [Symbol.iterator]]
> Map.prototype[Symbol.iterator]
[Function: entries]
> Set.prototype[Symbol.iterator]
[Function: values]
> Object.prototype[Symbol.iterator]
undefined
```

### iterator function
그렇다면 Symbol.iterator function은 어떤 역할을 할까? 아래의 코드 예시를 살펴보자.
```
const arr = [1,2,3,4,5]

const iterator_arr = arr[Symbol.iterator]();
console.log(iterator_arr.next());
console.log(iterator_arr.next());
console.log(iterator_arr.next());
console.log(iterator_arr.next());
console.log(iterator_arr.next());

//{ value: 1, done: false }
//{ value: 2, done: false }
//{ value: 3, done: false }
//{ value: 4, done: false }
//{ value: 5, done: false }
//{ value: undefined, done: true }
```
iterator function 이터레이터 객체를 반환하게 되고, 이 객체는 next라는 메소드를 호출하게 되는데, 이는 출력 결과를 보면 알겠듯이 iterable Object의 값들을 순서대로 보여주게 된다. 우리가 흔히 쓰는 `for ~ of` 문법은 iterator.next()를 계속 호출해주면서 done이 false가 나올때 종료시켜주는 것이다. 물론 당연하게 우리가 iterator function을 만들 수 있다.   
iterator function은 객체를 return 해야 하고, 이 객체는 next라는 메소드가 존재해야 한다. 그리고 next 메소드의 return 값은 done, value를 가져야 한다. done이 없는 경우 `for ~ of`에서 끝나는 지표를 알 수 없어 무한루프가 돌게 되고, value 키가 없으면 값을 반환하지 못한다.   
예시로 iterable Object가 아닌 일반 javascript Object를 Symbol.iterator를 사용해 iterable Object로 만드는 것을 알아보자.
```
const obj = {from : 1, to : 5}
obj[Symbol.iterator] = function(){
    return {
        current : this.from,
        last : this.to,
        next(){
            return (this.current <= this.last) ?
                {value:this.current++,done:false}:
                {done:true}
        }
    }
}
const obj_iterator = obj[Symbol.iterator]();
console.log(obj_iterator.next());
console.log(obj_iterator.next());
console.log(obj_iterator.next());
console.log(obj_iterator.next());
console.log(obj_iterator.next());
console.log(obj_iterator.next());

for(const value of obj){
    console.log(value);
}

/* console.log
{ value: 1, done: false }
{ value: 2, done: false }
{ value: 3, done: false }
{ value: 4, done: false }
{ value: 5, done: false }
{ done: true }
1
2
3
4
5
*/
```
