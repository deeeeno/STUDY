# React - 05. Component Cycle, State

### State
State는 props처럼 컴포넌트의 렌더링에 사용되는 자원이다. props는 컴포넌트에 파라미터로 전달되는 반면, state는 컴포넌트 안에서 관리된다는 차이점을 가지고 있다.
state를 설정할 수 있는 방법은 constructor에서 설정하는 방법과 setState를 사용하는 방법이 있다. 먼저 constructor을 사용한 state 설정을 확인해보자.
```
class Clock extends React.Component {
  constructor(props){
    super(props); 					//항상 기본 constructor를 props로 호출해야한다!
    this.state = {date:new Date()};	//state를 사용해서 값을 설정함
  }
  
  render() {
    return (
      <div>
        <h1>Hello, world!</h1>
        <h2>It is {this.state.date.toLocaleTimeString()}.</h2>	//state에 저장된 데이터를 사용. 
      </div>
    );
  }
}
ReactDOM.render(
    <Clock/>,
    document.getElementById('root')
);
```
### Component Life Cycle
React 컴포넌트는 생명주기를 가지고 있는데,  https://projects.wojtekmaj.pl/react-lifecycle-methods-diagram/ 이 url을 보면 도식화된 모습을 알 수 있다.
크게 총 3가지 단계가 있는데 **mount, update, unmount** 세개로 나눌 수 있다.
	* mount : 컴포넌트의 인스턴스가 생성되어 DOM 상에 삽입될 때에 호출 됨.
	STEP) constructor() -> render() -> componentDidMount()
		* constructor : 메서드 바인딩이나 state 초기화 목적으로 사용됨. 마운트 되기 전에 호출! 다음에 다
	* update : props 또는 state가 변경되면 갱신이 발생합니다. 아래 메서드들은 컴포넌트가 다시 렌더링될 때 호출 됨
	STEP) getDerivedStateFromProps() -> shouldComponentUpdate() -> render() -> componenentDidUpdate()
	* unmount : DOM 상에서 제거될 때 호출
	STEP) componentWillUnmount()