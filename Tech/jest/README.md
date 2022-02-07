# jest
jest는 페이스북에서 만든 테스팅 라이브러리이다. [공식 홈페이지](https://jestjs.io/)   
공식 문서에 따르면 자바스크립트를 위한 간단함에 강점이 있는 테스팅 프레임워크라는 표현을 사용하였다. 리액트, 리액트 네이티브에 용이하고 babel, ts, vue 등등 프로젝트에 사용이 가능하다고 한다!   

## 장점
* 설치하기 쉽다! npm이나 yarn으로 직접적으로 설치할 수 있다. 또한 프로젝트의 test.js파일을 모두 인식해 절로 실행시켜주는 용이함을 가지고 있다.   
```
//package.json
scripts:{
    ...
    "test":"jest",
    ...
}
```
* 빠르다! 사례로 airbnb는 mocha -> jest로 변하고 테스트 런타임이 12분이나 줄었다고 한다. 병렬 프로그래밍을 사용하고, 가장 느린 테스트를 먼저 실행한다. 또한 babel 변환인 경우 캐싱을 해놓아 cpu사용률을 줄인다.   
* 모킹(mocking) 능력이 뛰어나다! 이 부분은 모킹을 공부하면서 알아보자!   
* 스냅샷을 사용한다! 스냅샷 테스트를 통해 UI의 어떤 부분이 변경되었는지 알 수 있다.

## jest 설정하기
위에서 설명 했듯이 설치가 매우 간단하다. `npm i -D jest` 를 사용해서 다운로드를 진행하자. 그 후엔 ES6를 지원하도록 하기 위해 babel도 설치해주자.
```
npm i -d babel-jest @babel/core @babel/preset-env

///설치 후 babel.config.js
module.exports = {
  presets: [
    [
      '@babel/preset-env',
      {
        targets: {
          node: 'current',
        },
      },
    ],
  ],
};
```

## jest 사용해보기
```
$ tree -I node_modules
.
|-- README.md
|-- babel.config.js
|-- package-lock.json
|-- package.json
|-- src
|   `-- sum.js
`-- test
    |-- sample.test.js
    `-- sum.test.js
```
test 코드들은 test경로에 test파일들을 모아뒀다. test라는 디렉토리 하위 코드들은 알아서 인식되나 싶었지만 되지 않았다. 이제 package.json에서 설정한 스크립트인 test를 통해 실행해보자. `npm test`   
콘솔에 그럼 실패한 경우에 대해서 친절하게 보여준다.   
![jest result](resources\result.JPG)

## Matcher
jest의 문법을 보면 다음과 같다. 
```
test('테스트 명', ()=>{
    expect(received data).{Matcher}(expected data);
});
```
Matcher는 received data와 expected data를 맞춰보는 메소드이고, 여러가지 종류가 있다. 그 중 자주 쓰이는 것들을 알아보자.(사용된 예시는 [이 코드](test\matcher.test.js)에 있다.)   
### toEqual
이름에서 알다시피 둘의 값, 타입이 같은지 테스트하는 메소드이다. 값과 타입이 같은 경우 test에 통과하게 된다.
```
expect(123).toEqual(123);       //pass
const abc = 123;
expect(abc).toEqual(123);       //pass
expect(abc).toEqual('123');     //wrong 
```
### toBe
toEqual과 동일하게 값을 판단하는 메소드이다. toEqual과 다른 점은 메모리까지 확인한다는 점이다.
```
expect(123).toBe(123);      //pass
const abc = {a:123};
expect({a:123}).toBe(abc);  //wrong
expect(abc).toBe(abc);      //pass
```
### toBeTruthy, toBeFalsy
자바스크립트의 경우 true, false에 대해서 0 혹은 null 등의 빈 값에 대해 false, 그 외에 대해 true를 나타낼 수 있다. 이러한 경우에 대해 true, false임을 테스트해보는게 두 개의 메소드이다. 
```
expect(123).toBeTruthy();
expect(0).toBeFalsy();
```
### toHaveLength, toContain
리스트 테스트에 주로 사용되는 것들이다. toHaveLength는 길이를 판단하는 메소드이다. received data로 들어온 리스트의 길이와 expected data와 같은지 테스트한다.   
toContain은 리스트 내 존재하는 엘리먼트인지 테스트해보는 메소드이다.
```
const phone = ['iPhone','Galaxy','BlackBerry'];
expect(phone).toHaveLength(3);      //pass
expect(phone).toContain('Vega');    //wrong
```
### toMatch
정규식 매칭을 해보는 메소드이다. expected data엔 정규식이 들어가고 received data에 대해 테스트한다.
```
const email = 'kkrs0512@naver.com';
const not_email = 'kkrs0512';
expect(email).toMatch(/.*\@.*/);        //pass
expect(not_email).toMatch(/.*\@.*/);    //wrong
```
### toThrow
received data가 throw된 error인지 테스트하는 메소드이다. toThrow 인자로 메세지를 입력하면 에러 메세지까지 체크할 수 있다. 특이점은 함수 실행의 경우 콜백함수로 실행시켜야 한다는 점이다. 
바로 에러가 나는 함수를 실행시키면 아래의 경우 throw가 아닌 정말 그냥 에러가 나타날 수 있기 때문이다.
```
function errorfunc(){
    try{
        a = 1;
    }catch(e){
        throw e;
    }
}
expect(()=>errorfunc()).toThrow();
```

### 비동기 처리 in Jest
자바스크립트 하면 역시나 비동기 처리가 빠질 수 없다. 비동기적인 처리를 하는 단위 혹은 함수의 경우 어떻게 테스트할지 알아보자. 테스트 코드는 [여기](test/async.test.js)에 있다.
### done 처리
아래의 코드를 살펴보자.
```
const get = (cb)=>{
    setTimeout(()=>{
        cb('test');
    },500);
}
test('비동기 처리 테스트',()=>{
    get((data)=>{
        console.log('hihi');
        expect(data).toEqual('테스트');   //wrong
    });
});
```
아래 테스트는 실패한 예시다. 하지만? 실제로 실행해보면 성공했다고 나타난다. Jest Runner는 기본적으로 테스트 함수를 최대한 빨리 실행시키게 한다. 그렇기에 콜백 함수는 호출될 기회조차 얻지 못하고 테스트가 종료되는 경우가 나타나는 것이다. 이를 해결하는 방법은 done이란 함수인자를 사용하는 것이다. test의 콜백함수에 인자가 없는 것을 보고 뭔가 들어가지 않을까? 싶었다면 이 done이 그 호기심을 해결해 줄 것이다.   
```
test('비동기 처리 테스트',(done)=>{
    get((data)=>{
        console.log('hihi');
        expect(data).toEqual('테스트');   //wrong
        done();
    });
});
```
코드를 이렇게 수정했다. done의 역할은 테스트가 끝나는 부분을 명시적으로 나타내는 것이다. 즉, `expect(data).toEqual('테스트')` 코드 후 테스트가 끝나게 해달라는 것이다. 이 상태로 테스트를 다시 진행하면 정상적으로 틀렸다는 문구를 얻을 수 있다.   
### Promise 함수의 처리
비동기 하면 빠질 수 없는 것은 역시 Promise 객체이다. Promise 객체의 경우 아래처럼 테스트 코드를 작성하면 당연히 틀려도 맞다고 할 것이다. 왜냐면 콜백함수는 실행될 시간이 없어서!   
```
const getPromise = (str)=>{
    return new Promise((resolve)=>{
        setTimeout(()=>{
            resolve(str);
        },500);
    });
}

test('프로미스 비동기 처리 테스트',()=>{
    getPromise('test').then((str)=>{
        expect(str).toEqual('테스트');
    });
});
```
Promise의 경우 방법은 꽤나 간단한데, Promise 함수를 return 해주는 것이다. 그럼 Jest Runner는 resolve/reject까지 기다려준다.
```
test('프로미스 비동기 처리 테스트',()=>{
    return getPromise('test').then((str)=>{
        expect(str).toEqual('테스트');
    });
});
```
### async/await
당연히 async/await도 빠질 수 없다. 두 개를 쓴다면 보다 더 간단하게 나타낼 수 있다.
```
test('프로미스 async/await', async ()=>{
    const str = await getPromise('test');
    expect(str).toEqual('테스트');
});
```