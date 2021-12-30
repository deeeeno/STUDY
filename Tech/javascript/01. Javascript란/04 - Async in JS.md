# Javascript 04 - Promise, async, await
Javascript는 코드의 실행이 끝나지 않고도 다음 코드를 실행시키는 특징인 **비동기**를 가지고 있다. 이를 해결하기 위해서 callback함수를 사용할 수 있지만, 자칫 콜백 함수의 콜백 함수의 콜백 함수…. 같은 암담한 상황이 발생할 수 있다..! 

### Promise Object
Promise 객체는 위의 문제를 해결하기 위한 객체이다. Promise는 결과에 대한 약속을 주는 객체로 이해하면 될 것이다. Resolve, reject를 반환하게 된다.   
resolve는 말그대로 해결되었으니 나간다는 의미고 reject는 제대로 되지 않았음을 의미한다.
```
function PromiseTest(num){
	//Promise는 객체
  return new Promise((resolve,reject)=>{
    if(num==1) resolve('good');	//사용자가 설정한 조건에 맞게 resolve,reject를 설정할 수 있다.
    else       reject('nono');
  });
}
```
그렇다면 반환되어 나오는 resolve나 reject는 어떻게 사용하는 것일까? axios나 ajax등을 사용해보면 .then~~.catch를 사용해서 다음 절차를 진행하게 되는데 Promise도 그와 동일하게 진행한다. 
```
function PromiseTest(num){
  return new Promise((resolve,reject)=>{
    if(num==1) resolve('good');
    else       reject('nono');
  });
}
PromiseTest(1).then((data)=>{	//resolve에 대한 콜백함수는 then절을 사용한다.
  console.log('good');
  console.log(data);
}).catch((data)=>{				//reject에 대한 콜백함수는 catch를 사용한다.
  console.log('error');
  console.log(data);
});
PromiseTest(2).then((data)=>{
  console.log('good');
  console.log(data);
}).catch((data)=>{
  console.log('error');
  console.log(data);
});
```
한번 새로운 예시를 만들어보자. 1초 뒤 나타나는 랜덤 숫자에 대해서 console.log를 실행 시킨다고 생각해보자.
```
var a;
setTimeout(()=>{
	a = 100;
},1000);
console.log(a);
```
javascript의 비동기 성질 때문에 a는 undefined가 나타나게 될 것이다..! 이를 Promise로 바꿔보자! 생각보다 매우 간단하다.
```
new Promise((resolve,reject)=>{
  setTimeout(()=>{
    a = 10000;
    resolve(a);
  },1000);
}).then((data)=>{
    console.log(data);
});
```

### async, await
처음 async,await에 대해서 볼 땐 대체 이게 무슨 말인지 도저히 몰랐다.. Promise를 모르고 봐서 그런가?? Promise에 익숙해지니 한 문장으로 설명할 수 있을 것 같다. Async, await는 Promise의 결과를 기다리게끔 해주는 기능이다. 위의 코드에서 then, catch가 없이 더욱 간결히 사용할 수 있다는 것이다. 각각의 사용처는 다음과 같다.   
* async : await를 사용할 함수의 앞에 붙여줌
* await : Promise 객체의 resolve, reject를 결과로 반환하는 함수 앞에 붙여줌.   

장점은 Promise를 여러개 사용해서 절차를 확실히 해야 하는 경우 유용하다. Promise객체 A의 결과 도출 -> B의 결과 도출의 순서가 확실해야한다면 유용할 것 같다.   
단점은.. 이게 resolve인지 reject인지 모른다… 가령 server API call 같은 경우 오류 처리가 reject로 되는 경우엔 가독성을 위해 안 쓰는게 좋은 경우도 있을지도..? 모든건 설계를 잘 하면 상관없지만!ㅎㅎㅎ   
아래 코드를 확인해보자. Promise두개를 반환하는 함수이다.
```
function asyncTest(msg){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      resolve(msg)
    },1000);
  });
}
function MAIN(){
  let a;
  asyncTest('a').then((data)=>{
    a = data;
    console.log(a);
  });
  
  asyncTest('b').then((data)=>{
    a = data;
    console.log(a);
  });
}
MAIN()
```
결과는 a,b로 나타날 것이다 왜냐면 각각 then절에 묶여서 값이 할당되기 때문이다.   
하지만, 이게 정녕 a로 바뀌었다가 b로 바뀌었을까? 직접 실행해보면 거의 동시에 결과나 나타나는 것을 알 수 있다.   
분명 설계 상 1초 차이가 나야할텐데? Promise라곤 하지만 결국 비동기 처리의 대상이 되어버리기 때문이다..   
이를 벗어나기 위해선 아래와 같이 사용할 수도 있을 것이다.
```
function MAIN(){
  let a;
  asyncTest('a').then((data)=>{
    a = data;
    console.log(a);
    asyncTest('b').then((data)=>{
      a = data;
      console.log(a);
    });
  });
}
```
하지만 이는 결국 콜백지옥 속으로 들어가는 행위이다. 이번엔 async, await를 사용해보자. async는 await를 사용할 함수 앞에 붙이니까 async function MAIN으로 될 것이고, **Promise Object**를 반환하는 함수인 asyncTest 앞에 await를 붙여야할 것이다.
```
function asyncTest(msg){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      resolve(msg)
    },1000);
  });
}

async function MAIN(){
  let a = await asyncTest('a');
  console.log(a);
  a = await asyncTest('b');
  console.log(a);
}
MAIN()
```
코드가 이전 then, catch를 사용할 때 보다 7배는 간결해졌다. 심지어 취지대로 1초의 텀을 둔 채 결과가 나타나는 것도 확인할 수 있었다. 중요한건 위에서 말했듯이, resolve를 reject로 바꾸어도 다른 점이 없다는 것..!