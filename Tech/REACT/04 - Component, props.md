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
//props의 표현은 두가지로 나타날 수 있다. props객체로 나타낼 수 있지만.
//const {a,b} = {a:1,b:2}로 할당이 가능하듯이 props의 키의 집합으로 나타낼 수가 있다.
//function Welcome(props) {
function Welcome({name,msg}){
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

### Memo
부모의 state가 변경이 되면 자식 컴포넌트들도 함께 렌더링이 된다. 아래 경우를 보자.
```
function Btn({text,onClick}){
    return <button style={{
        backgroundColor:'tomato',
        color:'white',
        padding:'10px 20px',
        borderRadius:10,
        border:0
    }} onClick={onClick}>{text}</button>;
}
const MemorizedBtn = React.memo(Btn)
const App = ()=>{
    const [value,setValue] = React.useState("Save Change");
    const changeValue = ()=>{
        setValue("Revert Changes");
    }
    //React component에 onclick이라고 넣으면 핸들러가 아닌 props가 된다.
    //Import TIP : 부모의 state가 변경되면 모두 다 렌더링이 됩니다
    return(
        <div>
            <MemorizedBtn text={value} onClick={changeValue}/>
            <MemorizedBtn text="Confirm"/>
        </div>
    )
}
const root = document.querySelector('#root');
ReactDOM.render(<App/>,root);
```
text가 Confirm인 경우 props가 변경되지도 않지만, App의 state가 변경되어서 함꼐 렌더링이 된다. 실상 자원낭비인 격이다. 이런 경우 사용하는 것이 Memo 기능이다.   
Memo는 리액트 컴포넌트를 만드는 것인데 **부모가 변경되어도 자식의 props,state가 변경이 되면 렌더링을 하는 컴포넌트**이다.

### PropTypes
위의 예시에서 App을 아래와 같이 썼다고 해보자.
```
const App = ()=>{
    const [value,setValue] = React.useState("Save Change");
    const changeValue = ()=>{
        setValue("Revert Changes");
    }
    //React component에 onclick이라고 넣으면 핸들러가 아닌 props가 된다.
    //Import TIP : 부모의 state가 변경되면 모두 다 렌더링이 됩니다
    return(
        <div>
            <Btn text={value} onClick={changeValue} fontSize={16}/>
            <Btn text={14} fontSize="Confirm"/>
        </div>
    )
}
```
두번째 Btn을 보면 text, fontSize를 거꾸로 썼다. 하지만 이게 리액트 앱 입장에서 오류는 아니다. 그저 우리에게 오류일 뿐..!   
이걸 방지하기 위한 유용한 기능이 propTypes이다. props의 각 데이터 유형을 테스트해볼 수 있는 기능이다.
```
Btn.propTypes = {
    //사용법은 props이름과 어떤 타입을 검사할지
    text: PropTypes.string,
    fontSize: PropTypes.number.isRequired
};
```
이렇게 설정해두면 text데이터는 string인지 검사, fontSize는 number인지 검사해본다. 검사기는 다양한 종류를 가지고 있다. 
https://ko.reactjs.org/docs/typechecking-with-proptypes.html
위 페이지를 보면 어떤 것들을 판별 가능한지 나와있다.   
두번째 fontSize에 사용한 isRequired는 이 props가 무조건 필요하다는 것을 말하는 것이다. 그렇다면? 없으면 warning이 나타난다.