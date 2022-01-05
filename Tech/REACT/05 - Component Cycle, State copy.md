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
크게 총 3가지 단계가 있는데 **mount, update, unmount** 세개로 나눌 수 있다. 내부 STEP에 있는 메소드 들로만 절차가 이루어지는 것은 아니고, 자주 쓰일 것들만 정리해둔 것임을 명심해주길 바람….   
* mount : 컴포넌트의 인스턴스가 생성되어 DOM 상에 삽입될 때에 호출 됨.   
	STEP) constructor() -> render() -> componentDidMount()
	* constructor : 메서드 바인딩이나 state 초기화 목적으로 사용됨. 마운트 되기 전에 호출!
	* render : 반드시 있어야함. 주로 JSX를 return하게 된다. DOM 트리에 들어갈 태그를 저장하는 메소드. 정적으로 이루어져야 한다.
	* conponentDidMount : 컴포넌트가 마운트 되고 DOM 트리에 삽입된 직후에 호출. DOM이 있어야 하는 뭐 제이쿼리 요청? 같은걸 사용할때 여기서 하면 됨
* update : props 또는 state가 변경되면 갱신이 발생합니다. 아래 메서드들은 컴포넌트가 다시 렌더링될 때 호출 됨   
	STEP) shouldComponentUpdate() -> render() -> componentDidUpdate()
	* shouldComponentUpdate : props나 state가 변환되면 실행되는 메소드. 데이터가 업데이트 시 렌더링을 하냐 마냐를 결정하는 메소드. 파라미터로 변환되는 props, state를 가지게 되고 설정하지 않는 경우 true 기본값을 반환한다. 초기 렌더링이나 forceUpdate를 사용하는 경우엔 이 메소드가 포출되지 않는다.
	* componentDidUpdate : conponentDidMount와 마찬가지로 컴포넌트가 마운트 되고 DOM 트리에 삽입된 직후 호출.
* unmount : DOM 상에서 제거될 때 호출   
	STEP) componentWillUnmount()
	* componentWillUnmount : 컴포넌트가 마운트 해제되어 제거되기 직전에 호출되는 메소드  

그럼 위의 clock class에 life cycle을 사용하여 알아서 움직이게 해보자.
```
class Clock extends React.Component {
	////// 1
  constructor(props) {
    console.log('constructor');
    console.log(document.querySelector('#clock'));
    super(props);
    this.state = {date: new Date(), num: true};
  }
	/////// 2
  componentDidMount() {
    console.log('componentDidMount');
    console.log(document.querySelector('#clock'));
    this.timerID = setInterval(
      () => this.tick(),
      1000
    );
  }
	/////// 3
  shouldComponentUpdate(nextProps,nextState){
    console.log('shouldComponentUpdate');
    if(nextState.num) return false;
    return true;
  }

  componentWillUnmount() {
    clearInterval(this.timerID);
  }

  tick() {
    this.setState({
      date: new Date(),
      num : !this.state.num
    });
  }

  render() {
    return (
      <div id="clock">
        <h1>Hello, world!</h1>
        <h2>It is {this.state.date.toLocaleTimeString()}.</h2>
      </div>
    );
  }
}

ReactDOM.render(
  <Clock />,
  document.getElementById('root')
);
```
1. Constructor
	생성자에서는 id=clock인 태그를 검색해보고 있다. 결과는 과연 어떨까? Null이 나올 것이다. **왜냐 render가 아직 되지 않았기 때문이지.**
2. componentDidMount
	여기선 id=clock인 태그가 검색이 될 것이다. **render후이기 때문이지**
![](/Tech/resources/between.png)
3. shouldComponentUpdate
	메소드를 보면 num이 true인 경우 return false를 시켰다. 이 결과 시간은 2초 간격으로 흐르게 보일 것이다.
