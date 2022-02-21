# Javascript 03.01 - Sets
자바스크립트에서 Object는 string을 임의의 값에 매핑할 때 사용되는 다목적 데이터 구조이다. 여기서 매핑되는 값이 true같은 고정 값인 경우엔 그저 문자열의 집합이 될 수 있다.
Object는 Map이나 Set으로 자주 사용이 되지만,  문자열의 제한 등으로 사용에 힘듬을 겪고 있다. 이를 위해 ES6에서 Map, Sets을 만들었다.

## Sets
Sets은 배열과 같이 값 들의 모임이다.  하지만 배열과다른 점이 있으니.. Sets은 순서, 인덱스가 없고 중복값을 허용하지 않는다는 것이다.  예시를 보자.
```
let diary = new Set();

const john = {'name':'john'}
const tom = {'name':'tom'}
const ted = {'name':'ted'}

diary.add(john)
//Set(1) { { name: 'john' } }

diary.add(tom)
//Set(2) { { name: 'john' }, { name: 'tom' } }

diary.add(ted)
//Set(3) { { name: 'john' }, { name: 'tom' }, { name: 'ted' } }

diary.add(john)	//john을 넣었지만 중복되었기에 set엔 또 안들어감
//Set(3) { { name: 'john' }, { name: 'tom' }, { name: 'ted' } }

diary.add(tom)
//Set(3) { { name: 'john' }, { name: 'tom' }, { name: 'ted' } }

let num = new Set([1,2,3,4,6,1,5,7,3,6,5,4,6,2,6])
//Set(7) { 1, 2, 3, 4, 6, 5, 7 }		//중복값이 사라져
```
위의 예시처럼 중복 값이 사라진다. Sets에 있는 method들은 뭐가 있는지 살펴보자.
```
> let s = new Set()			//constructor, 괄호엔 이터러블한 데이터는 다 들어가기 가능이다.
undefined
> s
Set(0) {}
> s.add(1);					//add method, 말그대로 추가
Set(1) { 1 }
> s.add(2).add(3).add(1);	//chain 가능~
Set(3) { 1, 2, 3 }
> s.size						//sets의 size알려주기
3
> s.add(true)					//sets엔 뭐든 들어갈 수 있다.
Set(4) { 1, 2, 3, true }
> s.size
4
> s.delete(1)					//delete method, 삭제, 삭제 성공시 true, 실패시 false 반환
true
> s.delete(1728372)			//없는 값을 지우려 하니 false
false
> let arr = [1,2,3]
undefined
> s.add(arr)
Set(4) { 2, 3, true, [ 1, 2, 3 ] }
> s.delete([1,2,3])			//삭제할 땐 완벽하게 일치한 리스트를 지워야 한다.
false
> s.delete(arr)				//이렇게 완벽한 것!!
true
> s.clear()					//clear method, set내 모든 데이터 삭제!
undefined
> s.size
0

> s.add(1).add(2).add(3)
Set(3) { 1, 2, 3 }
> s.has(2)					//Sets는 타입까지 판단하기 떄문에 문자열로 된 2여도 찾아지지 않는다.
true
> s.has('2')
false
```
Sets은 그럼 어떻게 사용할까? Sets의 장점은 중복을 허용하지 않는 점이다. 이 점을 이용하면 배열을 sets으로 만들어 탐색 시간을 늦출 수 있지 않을까? 아래 코드를 보자.
```
const john = {'name':'john'}
const tom = {'name':'tom'}
const ted = {'name':'ted'}
let member_list = [];
for(var i=0; i<1000; i++)
    member_list.push(john);
for(var i=0; i<100; i++)
    member_list.push(tom);
member_list.push(ted);
let member_sets = new Set(member_list);

console.log(member_list.length);	//1101
console.log(member_sets.size);	//3
```
좀 웃긴 예시지만… 이미 리스트와 셋의 갯수 차이부터 현저히 다르다. 이렇게 되면 탐색 시간도 당연히 줄지 않을까??
```
function CALLBACK(a,b){return a(b);}
const john = {'name':'john'}
const tom = {'name':'tom'}
const ted = {'name':'ted'}
let member_list = [];
for(var i=0; i<1000; i++)
    member_list.push(john);
for(var i=0; i<100; i++)
    member_list.push(tom);
member_list.push(ted);
let member_sets = new Set(member_list);

function FIND(a){
    a.forEach(ele=>{
        console.log(ele);
        if(ele.name == 'ted'){
            console.log('find ted');
            return;
        }
    })
}

console.log('LIST start');
let start = new Date();  // 시작

CALLBACK(FIND,member_list);

let end = new Date();  // 종료
console.log('LIST end');
console.log('LIST MILLI : ' + (end - start)); // 경과시간(밀리초)

console.log('SETS start');
start = new Date();  // 시작

CALLBACK(FIND,member_sets);

end = new Date();  // 종료
console.log('SETS end');
console.log('SETS MILLI : ' + (end - start)); // 경과시간(밀리초)

/////결과
//LIST MILLI : 77
//SETS MILLI : 0
```
천개도 사실 적은 숫자여서 밀리 세컨드 1이 나올까 말까 한다.  그렇기에 forEach사이에 console.log을 넣었다. 결과는 현저한 차이.. 센스있게 사용 해야겠다.