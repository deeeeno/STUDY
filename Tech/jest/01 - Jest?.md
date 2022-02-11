# jest 01 - Jest?
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