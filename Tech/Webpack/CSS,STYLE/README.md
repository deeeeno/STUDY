# WEBPACK
이번엔 CSS, Style loader에 대해서 알아보겠습니다. CSS, Style로더는 말 그대로 css파일 로딩과 style이 적용되게 하는 로더입니다. 아래의 명령어로 로더를 다운로드 받습니다.
```
npm install css-loader style-loader
```

Root 경로에 resources파일을 만들고 style.css파일을 만들어 봅시다
```
//.  ./resources/style.css
.container{
    width: 500px;
    height: 500px;
    color: red;
}
.font-red{
    font-size: 15px;
    color: red;
}
```
이제 webpack.config.js에 설정한 loader들을 사용해봅시다.  css를 읽어오는 데에는 css loader만 필요하지만 실제 style이 적용되게 하려면 style loader가 필요하답니다.
webpack.config.js의 module->rules에 아래를 추가합니다.
```
{
     test: /\.css$/,
     use:["style-loader","css-loader"]
},
```

우리 webpack의 entry는 ./src/index.js입니다. 이 파일에서 css를 import 하고 webpack을 듭니다,
```
import Style from '../resources/style.css'; // 추가
npx webpack
```
만든 후 dist/main.js를 확인하면 아래와 같이 css가 들어간걸 확인할 수 있습니다.
```
___CSS_LOADER_EXPORT___.push([module.id, “.container{\n    width: 500px;\n    height: 500px;\n    color: red;\n}\n.font-red{\n    font-size: 15px;\n    color: red;\n}”, “”]);
```

