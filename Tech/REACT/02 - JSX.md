# REACT - 02. JSX
`const element = <h1>Hello, world!</h1>;`   
JSX는 자바스크립트의 확장 문법이다.  리액트로 개발할 때 사용되므로 공식적인 자바스크립트의 문법은 아니다. react의 공식 문서의 내용으로 공부해보자!   
테스트 시뮬레이터는 https://codepen.io/pen?&editors=0010 이걸 사용하였다.
먼저 JSX를 할당하는 법에 대해서 알아보자!
```
const element = <h1>hello. world!</h1>;	//한줄로 선언하기
const elements = (						//괄호로 묶어서 선언하기. 덮는 상위 tag가 필요하다.
	<div>
		<h1>hello, world!</h1>
		<h2>It's React!</h2>
	</div>
);
```

우선 JSX에 모든 javascript 표현식을 중괄호에 담을 수 있다. 표현식이라고 하면 값을 return하는 식, 코드를 말한다.
```
const name = 'dino';
const tag = <span>HI! {name}!</span>;	//간단한 변수 넣기
const member = [
  {'name':'dino','age':11},
  {'name':'jane','age':22},
  {'name':'jun','age':33},
  {'name':'tina','age':44}
]
const element = (
	<div>
		{tag}
		{
			member.map(ele => <span>{ele.name}({ele.age})</span>)		//중괄호 내부에 표현식 사용하기
		}
	</div>
);
```

물론 JSX도 표편식이기 때문에 if,for 절에 사용할 수 있고 return 또한 가능하다.
```
function NUMBER(number){
  if(number%2==0)	//if문에 대한 return
     return <h2>NUMBER({number})</h2>;
  else
     return <h2>({number})</h2>;		//JSX return
}
const name = 'deeeeeeeeeno';
const nameTag = (name.length>10) ? <span>{name.substring(0,7)+'...'}</span> : <span>{name}</span>;
const element = (
    <div>
    <h1>Hello!</h1>
    {NUMBER(3)}
    {nameTag}
    </div>);
ReactDOM.render(element, document.getElementById('root'));
```

