# Javascript 03.02 - Maps
Sets에 이어 이번엔 ES6의 Maps이다. 설명에 따르면 Map은 key라는 값의 세트로 각 키는 다른 값을 가지고 있는 형태를 말한다.  배열과 비교를 해볼 수 있는데, Maps는 배열과 다르게 정수가 아닌 key를 index로써 사용할 수 있다. Maps는 크기가 뭐 얼마나 크건 key <-> value가 정해져있기 때문에 매우매우 빠르다(당연히 근데 배열보단 느리지). 이제 한번 Map을 만들고 사용하는 것 까지 해보자.
```
//A
> let empty_map = new Map()
> empty_map
//Map(0) {}

//B
> let map = new Map([['a','cccc'],['b','ccccccc']])
> map
//Map(2) { 'a' => 'cccc', 'b' => 'ccccccc' }
```
Map을 생성하는 방법은 크게 두 개이다. 
	* A : 그냥 빈 Map을 만드는 것
	* B : iterable 데이터를 사용하는 방법이다. [key,element] 구조가 iterable하게 된 데이터를 사용해서 map을 만들 수 있다.
```
> let map = new Map()
undefined
> map.set('a',1);							//set method : 저장!
Map(1) { 'a' => 1 }
> map.get('a')							//get method : 키에 대한 값을 가져온다.
1
> map.set(1,2);
Map(2) { 'a' => 1, 1 => 2 }
> map.set('1',3);							//Key Point : Map은 key를 저장할 때 값 뿐만 아니라 타입까지 판단한다.
Map(3) { 'a' => 1, 1 => 2, '1' => 3 }
> map.keys()
//[Set Iterator] { 'a', 1, '1'}
> map values()
//[Set Iterator] { 1, 2, 3}
> map.get(1);
2
> map.get('1');
3
> map.has(3)								//has method : 가지고 있으면 true, 없으면 false
false
> map.has(1)
true
> map.size
3
> map.clear();
undefined
> map
Map(0) {}
```

Set과 Map의 공통적으로 key나 value는 어떤 값 모두가 가능하다. 즉, null, undefined, NaN도 가능하다는 것이다. 예외처리용으로 좋겠군. 또한, 값이 같음으로써 key를 판단하는게 아닌 정체성으로 판단하기 때문에 T 예시 같은 상황이 나타날 수 있다.
```
> map.set(NaN,1)
Map(1) { NaN => 1 }
> map.get(NaN)
1
> map.set(null,2).set(undefined,3)
Map(3) { NaN => 1, null => 2, undefined => 3 }
> map.get(null)
2
> map.get(undefined)
3
> let kk = {}
undefined
> map.set(kk,123);
Map(4) { NaN => 1, null => 2, undefined => 3, {} => 123 }
> map.get({})							//T
undefined
> map.get(kk)
123
```
