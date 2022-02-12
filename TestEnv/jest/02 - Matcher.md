# jest 02 - Matcher
jest의 문법을 보면 다음과 같다. 
```
test('테스트 명', ()=>{
    expect(received data).{Matcher}(expected data);
});
```
Matcher는 received data와 expected data를 맞춰보는 메소드이고, 여러가지 종류가 있다. 그 중 자주 쓰이는 것들을 알아보자.(사용된 예시는 [이 코드](demo/test/matcher.test.js)에 있다.)   
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