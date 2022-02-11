# jest 03 - Async in Jest
자바스크립트 하면 역시나 비동기 처리가 빠질 수 없다. 비동기적인 처리를 하는 단위 혹은 함수의 경우 어떻게 테스트할지 알아보자. 테스트 코드는 [여기](Tech/jest/demo/test/async.test.js)에 있다.
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