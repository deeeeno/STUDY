# React - 06. useState, useEffect

# 

이전에 리액트 컴포넌트의 life cycle과 state에 대해서 알아보았다. 이번엔 state와 rendering에 대해서 자주 쓰이는 기능에 대해서 알아보자. 함수형 컴포넌트에 사용됨을 유의하자.

### useState
말 그대로 state를 사용한다는 것이다. 예시를 보며 알아보자.   
`const [counter,setCounter] = useState(0);`
useState함수를 먼저 보면 파라미터로 초기값이 들어간다. 아무것도 넣지 않으면 state의 초기값이 undefined가 되므로 주의하자. 함수의 결과는 리스트로 나타나는데 다음과 같다.   
`[state의 초기값, state setter]`   
초기값은 뭐 간단하니까 setter에 대해서 알아보자. setter의 파라미터는 state의 값이다. 여기서 일반 값을 인자로 보낼 수도 있지만 callback 함수를 사용할 수 있다.
```
setCounter(count+1); // 일반 값을 인자로 넘김
setCounter((prev)=>prev+1);	//callback함수를 넘김
```
callback 함수의 인자가 현 state의 값인 것을 생각하면 현재 값을 기준으로 연산이 필요한 경우 신뢰성을 더할 수 있으므로 유용하게 사용될 듯 하다!

### useEffect
다음은 useEffect함수에 대해서 알아보자. state가 변하면 컴포넌트는 새로 렌더링이 된다. 다음을 확인해보자.
```
function App() {
  const [counter,setCounter] =  useState();
  console.log(counter);
  const [keyword,setKeyword] = useState('');

  const onClick = ()=> setCounter((prev)=>prev+1);
  const onChange = (event)=>{setKeyword(event.target.value)};
 
  console.log('hihi');

  return (
    <div>
      <input type="text" onChange={onChange} placeholder="Search here..."/>
      <h1 className={styles.title}>Welcome back!</h1>
      <button onClick={onClick}>click</button>
      <div>{counter}</div>
    </div>
  );
}
```
이 코드에서 카운터 버튼을 누르거나 input에 값을 입력하는 경우 state가 바뀌므로 hihi는 계속 나타나게 된다.   
하지만, component가 단 한번 실행될 때만 부를 API가 있는 경우도 있을 터이고, counter를 누르면 counter에만 영향이 가는 코드만 실행되게 하고싶은 경우가 있을 것이다.   
이때 사용하는 것이 **useEffect**이다. 설정은 다음과 같다.   
`useEffect(call back function, state list);`   
* call back function : 실행될 함수
* state list : 이 목록에 있는 state가 변할 떄 callback function을 실행   

useEffect함수 내 call back function은 컴포넌트가 처음 만들어 지는 과정엔 무조건 실행이 된다. 그럼? State list를 빈 값으로 두면 처음 생성될 때만 실행이 되게 트릭을 둘 수 있겠군!!   
함수형 컴포넌트가 클래스형보다 훨씬 쓰기 편한 것 같다..
