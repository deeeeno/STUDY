# React - 04. Component, Props
### Component
Component는 일반적으로 함수로 생각할 수 있다. 정의하는 방법은 함수, 클래스 를 이용한 방법이 있는데 아래와 같다.
```
/* 함수 컴포넌트 */
function WelcomeC(props) {
  return <h1>Hello, {props.name}</h1>;
}
/* 클래스 컴포넌트(ES6) */
class WelcomeF extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}

const element = (
  <div>
  <WelcomeC name="dino"/>
  <WelcomeF name="jane"/>
  </div>
)
ReactDOM.render(element, document.getElementById('root'));
```
그저 평소에 쓰던 함수와 동일하기 때문에 간단하게 볼 수 있을 것이다. 여기서 주의해야 할 것은 **컴포넌트 이름은 무조건 대문자로 시작해야 한다는 것이다. 소문자로 시작하면 태그로 처리하기 떄문이다.**
컴포넌트는 다른 컴포넌트를 함께 사용할 수 있다.
```
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}
function App(){
	return (
		<div>
		<Welcome name="dino"/>
		<Welcome name="jane"/>
		</div>
	);
}
```

### props
props는 컴포넌트에서 사용하는 매개변수 같은 느낌이다. props는 읽기 전용으로 사용하고, 아래의 예시로 살펴보자.
```
function Welcome(props) {
  return (
      <div>
        <h1>Hello, {props.name}</h1>
        <h3>{props.msg}</h3>
      </div>
    )
}

function App(props){
  return(
     <div>
        <Welcome name="dino" msg="Long Time no See"/>
        <Welcome name="jane" msg="Long Time no See!"/>
        <Welcome name="tom" msg="Long Time no See!!"/>
      </div>
  )
}

const element = (
  <App/>
)
ReactDOM.render(element, document.getElementById('root'));
```
컴포넌트를 만들 때 어트리뷰트로 설정한 값이 props로 들어간다. Welcome 컴포넌트를 사용할 때 보면 name, msg라는 키에 값을 넣고, 이걸 props.name, props.msg로 사용하는 것을 볼 수 있다. 이게 아닌 하위 태그들을 props로 사용할 수 있는데 위의 코드를 아래 처럼 변경해서 사용할 수 있다.
```
function Welcome(props) {
  return (
      <div>
        <h1>Hello, {props.name}</h1>
        <h3>{props.msg}</h3>
      </div>
    )
}
function Middle(props){
  return(
      <div>
        {props.children}
      </div>
  )
}

function App(props){
  return(
     <Middle>
        <Welcome name="dino" msg="Long Time no See"/>
        <Welcome name="jane" msg="Long Time no See!"/>
        <Welcome name="tom" msg="Long Time no See!!"/>
      </Middle>
  )
}

const element = (
  <App/>
)
ReactDOM.render(element, document.getElementById('root'));
```
