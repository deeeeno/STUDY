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
