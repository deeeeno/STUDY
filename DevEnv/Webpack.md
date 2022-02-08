# 웹팩을 통한 개발환경 세팅하기

### 사용할 패키지
```
webpack                         //웹팩 패키지
webpack-dev-server              //웹팩 개발서버 설정 패키지
terser-webpack-plugin           //자바스크립트 난독화 패키지
html-webpack-plugin             //html 생성 플러그인
mini-css-extract-plugin         //style 간소화 플러그인
css-loader                      //css 로더
css-minimizer-webpack-plugin    //css 파일 최적화 플러그인
```

### 기본적인 webpack.config.js 설정하기
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
}
```

### webpack.config.js의 추가적인 옵션
* devtool : source-map 값을 사용하면 번들된 자바스크립트 파일과 오리지널 파일의 위치를 링크시킨 map파일을 함께 생성한다.   
* devServer : 개발 서버를 띄우도록 설정한다.
```
devServer:{
    host:'localhost',
    port:8080,
    open:true,
    watchFiles:'index.html'
},
```
### Optimization 설정
최적화에 사용되는 것들이다. 다른 플러그인들도 많지만 우선 terser-webpack-plugin과 css-minimizer-webpack-plugin을 사용한 기본 최적화를 사용해보자.
```
optimization:{
    minimizer:[
        new TerserWebpackPlugin(),
        new cssMinimizerWebpackPlugin()
    ]
}
```
* TerserWebpackPlugin : mode=production인 경우 js코드 난독화, debugger문구 제거 등의 기능을 제공해준다.   
* cssMinimizerWebpackPlugin : css파일을 축소시키는 역할 진행.

### Plugins 설정
```
new HtmlWebpackPlugin({
    title:'dino',               //템플릿의 타이틀 
    template:'./index.html',    //템플릿이 될 타겟
    inject: 'body',             //번들 js 파일을 넣을 위치(body or head(default))
    favicon:'favicon.ico'       //파비콘
})
new MiniCssExtractPlugin({
    filename:'style.css',       //import된 스타일들을 하나의 css파일로 로딩한다.
})
```
### module 설정
* css   
```
rules:[
    {
        test:/\.css$/,
        use:[MiniCssExtractPlugin.loader,'css-loader']
    }
]
```