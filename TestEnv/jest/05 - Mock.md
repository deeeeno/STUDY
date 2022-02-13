# jest 05 - Mock
```
mock - 흉내내다
```
테스트를 진행하다보면 테스트 대상이 dependency를 사용해야하는 경우가 있다. 가령, DB의 데이터 삭제 test를 해야하는 경우 DB 요청, 테스트 완료 후 롤백 등 테스트 하나를 위해 주변 대응이 더 커지는 경우이다. 그럼 테스트 자체가 독립적이지 못하고 접속 시간 등 일관성을 가지지 못하기에 문제가 발생할 수 있다. 그러기 위해 **mocking**이란 것을 사용한다.   
**mocking**이란 흉내내다라는 뜻 처럼 실제 객체의 역할을 가지는 **가짜** 객체를 생성하는 것을 말한다. 그럼 jest에서 mocking 사용법을 알아보자.   
### jest.fn
첫 번쨰는 jest의 fn메소드이다. 이름에서 알 수 있듯이 **가짜 함수를 만드는 메소드이다.** 테스트 코드는 [여기](demo/test/mock.test.js)
```
const mockFn = jest.fn();
//모듈의 함수를 대상으로 삼을 수도 있다.
axios.get = jest.fn();
```
jest.fn()의 default return value는 undefined이다. return value는 mockReturnValue, mockResolvedValue로 수정 가능한데 이름에서 유추가 가능하듯 일반 return, promise.resolve return을 나타낸다.
```
test('mock function 중 mockReturnValue 사용 테스트',()=>{
    const mockFn = jest.fn();
    mockFn.mockReturnValue(1);
    expect(mockFn()).toEqual(1);
});


test('mock function 중 mockResolvedValue 사용 테스트',(done)=>{
    const mockFn = jest.fn();
    mockFn.mockResolvedValue(1);    //resolve로 비동기 리턴
    mockFn().then((result)=>{
        expect(result).toEqual(1);
        done();
    });
});
```
물론 함수 자체를 재현할 수 있다.
```
const mockFn = jest.fn();
mockFn.mockImplementation((a,b)=>a+b);
```
### jest.spyOn
가짜 함수를 구혆애서 테스트하는 경우도 있지만 가짜 함수 구현이 아닌 옆에서 지켜보며 데이터를 가져오는 방법도 있다. 스파이란 이름처럼 spyOn 메소드를 쓰는 것인데, 아래와 같이 사용할 수 있다. spyOn은 객체의 소속 함수를 칭해주어야 한다.
```
const calculator = {
    add : (a,b)=>a+b
}
const spy = jest.spyOn(calculator,'add');
```

### mock matcher
Mock function에 대해서 대표적인 두가지 matcher가 있다. toBeCalledTimes, toBeCalledWith이 존재한다. Mock function은 몇 번 호출되었는지, 어떤 파라미터로 호출 되었는지 기록하고 있기 때문에 검사가 가능하다.
```
test('mock function matcher 1 -> toBeCalledWith',()=>{
    const mockFn = jest.fn();
    mockFn(1);
    mockFn(2);
    mockFn({1:2});
    mockFn([1,2]);
    expect(mockFn).toBeCalledTimes(4);
    expect(mockFn).toBeCalledWith(1);
    expect(mockFn).toBeCalledWith(2);
    expect(mockFn).toBeCalledWith({1:2});
    expect(mockFn).toBeCalledWith([1,2]);
});
```

### jest.mock
아래 테스트 코드를 보자. 이 코드는 mailService의 sendMail 함수가 몇 번 호출 되었는지 테스트하는 함수이다. mailService의 sendMail은 유저 create 시 호출 되도록 되어있다.
```
/// test/fn.test.js
import userService from '../src/users';
import mailService from '../src/mail';

mailService.sendMail = jest.fn();
const sendMail = mailService.sendMail;
beforeEach(()=>{
    sendMail.mockClear();   //모킹된거 지워버리기.
});

test('jest.fn을 이용한 mocking',()=>{
    const user =  {
        email: "test@email.com",
        name:'dino'
    };
    userService.create(user);

    expect(mailService.sendMail).toBeCalledTimes(1);
    expect(mailService.sendMail).toBeCalledWith(user.email,user.name+'님이 가입하였습니다.');
});
```
코드를 보면 sendMail을 mock function으로 만들고 테스트를 진행하고 있다. 하지만, 만약 mailService의 다른 함수들을 테스트 하고싶다면? `mailService.sendMail = jest.fn()` 부분이 여러번 호출 되지 않을까? 사용법이 어렵진 않지만, fn, spyOn의 경우 타겟이 되는 함수 하나하나 설정해주어야 한다는 단점을 가지고 있다. 이런 단점을 보완하고자 jest는 mock 메소드를 제공한다. 가령, mailService의 sendSMS 함수도 테스트를 한다고 보자(sendSMS 또한 create 시 발생한다고 가정하자.). 그럼 아래처럼 `jest.fn()`의 호출부는 하나 더 늘어날 것이다.
```
...
mailService.sendMail = jest.fn();
mailService.sendSMS = jest.fn();
...
```
이번엔 `jest.mock`을 사용해보자. 우선 설명하자면 mock 함수는 모듈 하위의 함수들을 mock function 설정을 해주는 것이다.
```
import userService from '../src/users';
import mailService from '../src/mail';

jest.mock("../src/mail");       //jest.fn, jest.spyOn과 다르게 모듈 자체에 걸어버리기
test('jest.mock을 이용한 mocking',()=>{
   
    const user =  {
        email: "test@email.com",
        name:'dino'
    };
    userService.create(user);

    expect(mailService.sendMail).toBeCalledTimes(1);
    expect(mailService.sendMail).toBeCalledWith(user.email,user.name+'님이 가입하였습니다.');
    expect(mailService.sendSMS).toBeCalledTimes(1);
    expect(mailService.sendSMS).toBeCalledWith(user.email,user.name+'님이 가입하였습니다.');
})
```
무지하게 사용이 간단하다.   
여기까지 jest의 대부분 중요한 내용을 다뤄 보았다. 개발에 있어서 개발 환경, 테스트 환경이 공부하고 보니 가장 중요함을 느꼈다. 다음으로는 리액트, 뷰를 대상으로 jest 사용법을 알아보자.
