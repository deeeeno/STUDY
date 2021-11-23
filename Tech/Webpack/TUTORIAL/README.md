# WEBPACK
회사에서 frontend랍시고 vue를 열심히 다뤄본 결과… javascript, css의 파일이 방대해지고, IE, 모바일 등등 여러 환경에서 동작이 되야 하는 것을 고려해야 하였다.
가장 큰 문제는 IE에선 javascript의 es6문법이 적용되지 않는다는 점… 그래서 웹팩을 공부하였다. 생각보다 간단해서 놀랬던 웹팩! 물론 심도있게 다루려면 어렵지 않을까?

* WEBPACK이란?
웹팩은 모듈 번들러로 리소스 파일들의 모음집이다. 모듈은 리소스 파일을 의미하고, 번들은 모음이란 뜻이니까 리소스의 모음! 
* 왜 필요해?
앞서 말한 고충처럼 한 페이지에서 수많은 javascript와 css를 다뤄야 한다. 하지만, 만약에 한페이지가 아니라 10곳이 넘는 곳이라면..? 한곳한곳 다 수정해야할 수도 있다(내가 겪음). 그저 한줄씩 import해두고 사용하면 편해! 또한 webpack에서 사용하는 Loader중 babel loader라고 있는데 이는 es6 -> es5 문법으로 변경해준다. 그렇다면 문법에 상관없이 코딩해도 상관없어 진다!

한번 직접 해봅시다 웹팩! 간단하게 프로젝트를 만들어보겠습니다.
```
mkdir webpack-test && cd webpack-test
npm init -y
npm install webpack webpack-cli
```

webpack엔 설정파일이 존재합니다. 이름은 **webpack.config.js**라고합니다. 우선 이것부터 생성해보겠습니다.
```
const path = require('path')
module.exports = {
    entry : './src/index.js',					//entry : 입력파일
    output : {									//output: bundle이 어디서 생길지
        filename: 'main.js',
        path : path.resolve(__dirname,'dist')
    },
    resolve: {									//각종 옵션
        roots: [__dirname],						//root 경로를 설정(황경변수 같은거)
    },
    mode: 'production',							//production mode -> 최적화 기능을 기본으로 적용되도록 함.
}

```
Resolve 옵션에 사용되는 것들은 [Resolve | webpack](https://webpack.js.org/configuration/resolve/#resolveroots) 여길 확인해보면 됩니다.
위를 해석하면 매우 간단하다! **Src/index.js를 main.js로 번들화 하라!** 라는 뜻입니다. 그럼 간단하게 index.js를 먼저 만들어보겠습니다.
```
function hello(str){
    console.log('---------------');
    console.log('hi! ' + str);
    console.log('---------------');
}


hello('dino')
```

간단한 함수를 생성해두고 아래의 명령어를 입력합니다. 이는 번들링을 진행하는 명령어이고 성공하면 아래처럼 successfully라는 말을 남기게 됩니다.
```
npx webpack


dinoui-MacBook-Pro:webpack-test dino$ npx webpack
asset main.js 225 bytes [emitted] (name: main)
./src/index.js 141 bytes [built] [code generated]
webpack 5.64.2 compiled successfully in 122 ms
```
후에 dist/main.js를 확인해보면 우리가 만든 함수가 저장되는 것을 알 수 있습니다.
```
/******/ (() => { // webpackBootstrap
var __webpack_exports__ = {};
function hello(str){
    console.log('---------------');
    console.log('hi! ' + str);
    console.log('---------------');
}


hello('dino')
/******/ })()
;

```

이렇게 웹팩 기본이 마무리 되었습니다. 너무 쉽네.. 다음엔 css,style,babel loader를 통한 리소스 번들링을 진행해보겠습니다!