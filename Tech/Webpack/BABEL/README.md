# WEBPACK
이번엔 Loader를 다뤄보겠습니다. 기본적으로 유용하게 쓰이는 로더인 **Css, Style, Babel Loader**에 대해서 알아보겠습니다. 
* Babel Loader
Babel loader는 JSX, es6의 문법을 es5로 변경시켜주는 역할을 합니다. 우선 설치부터 진행해볼게요.
`npm install @babel/core @babel/preset-env babel-loader`
@babel/core는 바벨 컴파일러의 코어 파일, @babel/preset-env는 es6+ -> es5로 변경해주는 옵션입니다. 이번 현행 프로젝트의 가장 큰 문제는 IE대응 이었어요.. es6를 지원하지 않는 IE에 대해서 babel을 사용하는 것도 방법 중 하나로 고안되었습니다. 하지만, 그러기엔 크나 큰 공수가 필요했고, 시간이 적었기에 우선 추후 적용하기로 결론이 지어졌어요. 
그런 의미로! 한번 es6 -> es5로 변경 진행해봅시다!!!!!!! 먼저 일전에 만들었던 webpack.config.js을 아래처럼 수정합시다.
```
const path = require('path')

module.exports = {
    entry : './src/index.js',
    output : {
        filename: 'main.js',
        path : path.resolve(__dirname,'dist')
    },
    resolve: {
        roots: [__dirname],
    },
    module:{	//이 부분이 추가되는 것! 로더가 사용되는 부분입니다.
        rules:[		
            {
                test: /\.m?js$/i,		//정규식으로 찾습니다. .js,.mjs을 대상으로 로더를 적용합니다.
                exclude: /node_modules/,	//정규식으로 찾습니다. 이 부분은 제외하고 찾는다는 소리
                use: {					//사용할 로더를 설정해줘요.
                    loader:'babel-loader',		//우린 바벨로더를 사용할 것이고, @babel/preset-env옵션을 붙입니다.
                    options: {
                      presets: ['@babel/preset-env']
                    }
                  }
            },
        ]
    },
    mode: 'production',
    optimization: {minimizer:[]}
}
```
자 그럼 index.js를 아래처럼 수정하고 index.js와 같은 경로에 test.js를 만들게요
```
//index.js
import './test';
func1(1,2);
func2();
promiseFunc(1);
```
```
//test.js
const { resolve } = require("../webpack.config");

//es6 문법, Arrow Function
var func1 = (a,b)=>{
    console.log(a);
    console.log(b);
}
//es6 문법, default parameter
function func2(a=1,b=2){
    console.log(a);
    console.log(b);
}

function promiseFunc(a){
    new Promise(()=>{
        if(a==1)
            resolve('good');
        else
            reject('fail');
    }).then((res)=>{
        console.log(res);
    }).catch((rej)=>{
        console.log('error');
    })
}
```
자 이렇게 es6문법을 두르고 있는 함수들을 만들고 index.js에선 그저 import해주는 형식으로 하였습니다. 그런 후 **npx webpack**을 통해서 생성하면 main.js에 문법이 변경된걸 확인할 수 있습니다.
```
var func1 = function func1(a, b) {
  console.log(a);
  console.log(b);
};

function func2() {
  var a = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 1;
  var b = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 2;
  console.log(a);
  console.log(b);
}

function promiseFunc(a) {
  new Promise(function () {
    if (a == 1) resolve('good');else reject('fail');
  }).then(function (res) {
    console.log(res);
  })["catch"](function (rej) {
    console.log('error');
  });
}
```
