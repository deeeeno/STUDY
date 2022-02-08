# Project 1) 키보드 만들기.

### webpack 설정하기
* 웹팩 패키지 설치하기.   
```
npm install -D webpack webpack-cli webpack-dev-server
```
* webpack.config.js 생성하기   
```
const path = require('path');
module.exports= {
    entry: "./src/js/index.js",                 //webpack 타겟
    output:{
        filename:"bundle.js",                   //생성할 웹팩 파일명
        path:path.resolve(__dirname,'./dist'),  //웹팩 파일 경로
        clean:true                              //기존 파일 제거 후 생성
    },
    devtool : 'source-map',                     //빌드한 파일과 원본 파일을 링크해주는 것
    mode : 'development',                       //웹팩의 모드(development or production)
    optimization:{
        minimizer:[
            new TerserWebpackPlugin()           //mode=production인 경우 자바스크립트 코드 난독화 기능을 추가해준다.
        ]
    }
}
```
* 웹팩 진행하기.   
```
npx webpack
```
입력하면 dist폴더의 **bundle.js**가 생긴 것을 확인할 수 있다. 특이점은 우리의 웹팩 설정은 devtool이 source-map이다. 그렇기에 **bundle.js.map**이란 이름으로 매핑정보 파일이 같이 있는 것을 알 수 있다.
* html 관련 웹팩 설정하기.   
```
npm i -D html-webpack-plugin
npm i -D mini-css-extract-plugin css-loader css-minimizer-webpack-plugin
```
* html-webpack-plugin   
html-webpack-plugin은 설정한 옵션대로 html 템플릿을 생성하게 해주는 플러그인이다.
```
new HtmlWebpackPlugin({
    title:'keyboard',           //템플릿의 타이틀 
    template:'./index.html',    //템플릿이 될 타겟
    inject: 'body',             //번들 js 파일을 넣을 위치(body or head(default))
    favicon:'favicon.ico'       //파비콘
})
```

* npm install option   
`--save-exact` : package.json으ㄹ 보면 앞ㅔ 꺽새(^)표시가 있다. 이는 패키지에 설치된 버전이 최신 버전이 아닌 경우 install 시 최신 버전으로 업데이트를 시켜준다는 것이다. 이 때 `--save-exact`옵션을 주게 된 경우 꺽새가 없이 딱 그 버전만 다운로드 받도록 하게 해준다. 

* eslint, prettier
eslint는 자바스크립트 프로젝트를 실행 전 코드에 대해서 문법적인 오류가 있는지 없는지 체크해주는 라이브러리이다. prettier는 코드의 형식 즉 코드 스타일을 일관성있게 만들어주는 라이브러리이다. 이 두가지 라이브러리를 사용해서 문법과 스타일 환경을 세팅해보자.
아래의 디펜던시들을 다운받자.
```
npm i -D eslint 
npm i -D --save-exact prettier
npm i -D eslint-config-prettier eslint-plugin-prettier
```
eslint-config-prettier는 eslint도 코드 포맷을 검사하는 기능이 있어 prettier와 충돌이 날 수 있다. 이를 방지해주는 디펜던시이고,   
eslint-plugin-prettier는 eslint에 prettier기능을 넣어주는 플러그인이다.   
모두 다운로드를 받았다면 `npx eslint --init`을 통해 config 파일을 만들자.
```
➜  project1 npx eslint --init
You can also run this command directly using 'npm init @eslint/config'.
Need to install the following packages:
  @eslint/create-config
Ok to proceed? (y) y
✔ How would you like to use ESLint? · problems
✔ What type of modules does your project use? · esm
✔ Which framework does your project use? · none
✔ Does your project use TypeScript? · No / Yes
✔ Where does your code run? · browser
✔ What format do you want your config file to be in? · JSON
Successfully created .eslintrc.json file in /Users/dino/Desktop/fastcampus/project1
```
이렇게 생성하면 프로젝트에 `.eslintrc,json`이란 파일이 생성된다. 파일을 살펴보면 아래와 같다.
```

```
